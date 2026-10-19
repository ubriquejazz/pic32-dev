#include "HardwareSetup.h"
#include "SpiOne.h"
#include "uart.h"

#define SMM_NODE_ID 8
#define RESET_SMM_CODE 0x72657365

static CANInit_t canInitialisation;
static CANBoardTypes_e canBoardType;
static BOOL halfSecondUp;
static uint32_t msecCounter;

static void initialiseTimer1(void);
static BOOL resetViaCAN(uint32_t address, uint32_t data, BOOL readAccess);

BOOL HWAPI_InitialiseHardware(void)
{
    DDPCONbits.JTAGEN = 0;  // disable JTAG 
    // PORTs Setup      // '1' sets pin as input '0' as output
                        // signal name with _B indicated a signal which is logic '0' asserted
    
    TRISA = 0xC60C;     // PORT A
    PORTACLR = 0xFFFF;  // RA0: NOT_USED output
                        // RA1: TP302 output
                        // RA2: I2C_2_CLK bi-directional set as input
                        // RA3: I2C_2_DATA bi-directional set as input
                        // RA4: TP303 output
                        // RA5: TP304 output
                        // RA6: TP305 output
                        // RA7: TP306 output
                        // RA14: I2C_1_CLK bi-directional set as input
                        // RA15: I2C_1_DATA bi-directional set as input
                        
    TRISB = 0x007F;     // PORTB
    PORTBCLR = 0xFFFF;  // RB0: PROGRAM_DATA bi-directional set as input
                        // RB1: PROGRAM_CLK bi-directional set as input
                        // RB2-RB6: are used as analogue inputs, set as inputs 
                        // RB7-RB15: are not used set as output
                        
    TRISC = 0x0010;     //PORTC   
    PORTCSET = 0x0006;  // RC1: DIGI_RESET output set high so DIGI module is not in reset 
                        // RC2: DIGI_INIT_B output set high so DIGI module is not in reset
                        // RC3: NOT_USED output
                        // RC4: PROM_DATA_OUT used as SDI1 set as input 
                        // RC13: NOT_USED output
                        // RC14: NOT_USED output
                        // RC15: NOT_USED output 
                        // rest of pins either don't exist on device or used for the crystal oscillator, set as inputs

    TRISD = 0xF0E0;     // PORTD  
    PORTDCLR = 0x0F1B;  // RD0: PROM_DATA_IN, SPI_1_DOUT output 
    PORTDSET = 0x0004;  // RD1: NOT_USED output
                        // RD2: PROM_MUX_ENABLE output
                        // RD3: PIC_LED output
                        // RD4: POWER_LED output
                        // RD5: SLFAN_ALT2 input
                        // RD6: SLFAN_ALT3 input
                        // RD7: SLFAN_ALT4 input
                        // RD8: PROM_SEL_B output 
                        // RD9: PROM_CSB output 
                        // RD10: PROM_CLK output
                        // RD11: PROM_SEL_A output  
                        // RD12: 1_WIRE input
                        // RD13: SLFAN_ALT1 input
                        // RD14: HWDET_ALL input
                        // RD15: DUTFAN_ALL input
                        
    TRISE = 0x0000;     // PORTE  
    PORTECLR = 0x03FF;  //RE0: PIC_SMMIO_0 output
                        //RE1: PIC_SMMIO_1 output
                        //RE2: NOT_USED output
                        //RE3: NOT_USED output
                        //RE4: NOT_USED output
                        //RE5: NOT_USED output
                        //RE6: NOT_USED output
                        //RE7: NOT_USED output
                        //RE8: NOT_USED output
                        //RE9: NOT_USED output
                        
    TRISF = 0xFED1;     //PORTF
    PORTFCLR = 0x0008;  // RF0: CAN1_RX input
                        // RF1: CAN1_TX output
                        // RF2: NOT_USED output
                        // RF3: PROM_WP output
                        // RF4: DIGI_SPI_OUT/UART_RX input
                        // RF5: DIGI_SPI_IN/UART_TX output
                        // RF8: NOT_USED output
                        // RF12: DIGI_SPI_EN input
                        // RF13: DIGI_SPI_CLK input
                        
    TRISG = 0x0001;     //PORTG
    PORTGCLR = 0x01C0;  // RG0: CAN_2_RX input
                        // RG1: CAN_2_TX output
                        // RG2: NOT_USED output
                        // RG3: NOT_USED output
                        // RG6: SMM_PROM output
                        // RG7: MP_PROM output
                        // RG8: SYS_LED output
                        // RG9: NOT_USED output
                        // RG12: NOT_USED output
                        // RG13: NOT_USED output
                        // RG14: NOT_USED output
                        // RG15: NOT_USED output
    return TRUE;
}

void HWAPI_InitialiseInterfaces(void)
{
    objectDictionary_t* pObjectDictionary;

    UARTAPI_InitialiseUartThreeA();
    SPIOne_InitialiseSPIOne();

    canInitialisation.nodeId = HWAPI_getNodeId();
    canInitialisation.bridgeCanOneAndTwo = TRUE;
    canInitialisation.bridgeCan = CAN_1;    
    CAN1_Initialise(&canInitialisation);
    CAN2_Initialise(&canInitialisation);
    
    initialiseTimer1();

    pObjectDictionary = OBJECTDICT_getObject(RESET_REG);
    pObjectDictionary->function = &resetViaCAN;
}

/**
* Initialise Timer 1.
* Timer 1 is setup as 16 bit timer giving an interrupt every 100ms.
*/
static void initialiseTimer1(void)
{
    // Initialise count variables
    halfSecondUp = FALSE;
    msecCounter = 0;

    // Configure Timer
    T1CONbits.TCS = 0;      // Use internal peripheral clock
    T1CONbits.TCKPS = 0x3;  // Presacaler set at 256   
    PR1 = COUNT_50MS_TICK;
    
    // Setup interrupts
    IEC0CLR = _IEC0_T1IE_MASK;  // Disable Timer 1 Interrupts
    IFS0CLR = _IFS0_T1IF_MASK;  // Clear Timer 1 Interrupt Flag
    IPC1CLR = _IPC1_T1IP_MASK;
    IPC1SET = TIMER1_INTERRUPT_PRIORITY << _IPC1_T1IP_POSITION;     //set interrupt priority
    IPC1CLR = _IPC1_T1IS_MASK;
    IPC1SET = TIMER1_INTERRUPT_SUB_PRIORITY << _IPC1_T1IS_POSITION;//set interrupt sub-priority
    IEC0SET = _IEC0_T1IE_MASK;  // enable Timer 2 Interrupts;
    T1CONSET = _T1CON_ON_MASK; // start timer 2
}

/**
* Gets the CAN nodeId.
*
* The nodeId is specified as NodeId[17..0] = [17..8]:BOARD_TYPE +[7..0]:SLOT_ID
*/
uint16_t HWAPI_getNodeId(void)
{
    uint16_t nodeId; 
    canBoardType = SMM_BLADE_01;
    nodeId = SMM_NODE_ID;
    nodeId = nodeId | (canBoardType<<8); 
    return (nodeId);
}

/**
* Gets the CAN slotId.
*/
uint16_t HWAPI_getSlotId(void)
{ 
    return (SMM_NODE_ID);		
}

/**
* Checks if 1 second has ellapsed.
* This function will return TRUE if a second has expired since the last
* time the function had returned TRUE. 
*
* @return TRUE when one second has ellapsed
*/
BOOL HWAPI_IsHalfSecondUp(void)
{
	BOOL result = FALSE;

	if (halfSecondUp == TRUE)
	{
		result = TRUE;	
		halfSecondUp = FALSE;
	}
	return result;
}

/**
* Timer 1 Interrupt handler.
* Increments the msecCounter on every interrupt and sets the oneSecondUp flag when a one second has elapsed.
* The msecCounter is reset when one second has elapsed.
*/
void __attribute__((vector(_TIMER_1_VECTOR), interrupt(ipl4), nomips16)) Timer1InterruptHandler(void)
{
   	msecCounter ++;                         // Increment millisecond counter 
	if(msecCounter == HALF_SECOND_50MSEC)   // One second passed
	{
        halfSecondUp = TRUE;	
		msecCounter = 0;
	}
    IFS0CLR = _IFS0_T1IF_MASK;              // Clear Timer 1 Interrupt Flag
}


static BOOL resetViaCAN(uint32_t address, uint32_t data, BOOL readAccess)
{
    if (readAccess == FALSE)
    {
        if  (data == RESET_SMM_CODE)
        {
            HWAPI_SoftReset();
        }
    }
    return TRUE;
}

/**
* The following steps are performed by this function:
*   Step 1 - Execute "unlock" sequence to access the RSWRST register.
*   Step 2 - Write a '1' to RSWRST.SWRST bit to arm the software reset.
*   Step 3 - A Read of the RSWRST register must follow the write.  This
*   action triggers the software reset, which should occur on the next
*   qclock cycle.
* The read instruction must be following with either 4 nop
* instructions (fills the instruction pipe) or a while(1)loop to
* ensure no instructions can access the bus before reset occurs.
 *****************************************************************************/
 void __attribute__((noreturn)) HWAPI_SoftReset(void)
{
	int	intStat;
	int	dmaSusp;
	volatile int* p = (volatile int*) &RSWRST;

	mSYSTEMUnlock(intStat, dmaSusp);
	RSWRSTSET=_RSWRST_SWRST_MASK;
        *p;

	while(1);
}
