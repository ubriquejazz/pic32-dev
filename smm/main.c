#include "HardwareSetup.h"
#include "adc.h"
#include "PwrStateMachine.h"
#include "ObjectDictionary.h"
#include "version.h"

#define SYS_FREQ (80000000L)

errorList_e error;

int32_t main(void)
{		
    SYSTEMConfig(SYS_FREQ, SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
    INTConfigureSystem(INT_SYSTEM_CONFIG_MULT_VECTOR);
    HWAPI_InitialiseHardware();
    ADC_Initialise();
    HWAPI_InitialiseInterfaces();
    INTEnableInterrupts();

    mSet_DIGI_RESET();
    mSet_PIC_SMMIO_0(); // Temporary, because this pin drives the compatibility input pin on the digital boards
    mSet_PIC_SMMIO_1(); // Temporary, because this pin drives the compatibility input pin on the digital boards
    
    OBJECTDICT_setObject(MODULE_TYPE_REG, SMM_BLADE_01);
    OBJECTDICT_setObject(SW_REV_REG, SOFTWARE_REVISION);  
    
    while(TRUE)
    {
        ADC_ProcessAdcSamples();
        if (HWAPI_IsHalfSecondUp() == TRUE)
        {                         
            CANAPP_RequestToSendBroadcast (CAN_1, CMD_BROADCAST_MIDPLANE_CONFIG, MIDPLANE_CONFIG_2);
            P_SM_ServiceStateMachine(); 
            HEARTBEAT_ProcessHeartBeats();
        }
        UART_CMD_ProcessRxString();
        CANAPP_ProcessBridgeRxMessage(&error);
    }
}
