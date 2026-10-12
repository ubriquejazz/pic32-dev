#include "global.h"
#include "CANfunctions.h"
#include "CANAppLayer.h"
#include "HardwareSetup.h"
#include "Uart.h"
#include "UartCommands.h"

void 
main(void)
{
    uint32_t toggleFunction;
    errorList_e error;
    rxUartCommand_t *pRxUartCommand;

    SYSTEMConfig(SYS_FREQ, SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
    INTConfigureSystem(INT_SYSTEM_CONFIG_MULT_VECTOR);
    HW_InitialiseHardware();

    CAN1_Initialise();
    UART3_Initialise();
    INTEnableInterrupts();

    toggleFunction = 0;
    while (TRUE)
    {
        CANAPP_ProcessRxMessage(&error); 
        pRxUartCommand = UART_CMD_getCommandBuffer();
        if ( UART_ProcessRxString( &pRxUartCommand ) )
            UART_CMD_execCommand();
    }
}

	