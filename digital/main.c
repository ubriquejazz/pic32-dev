#include "HardwareSetup.h"
#include "Adc.h"
#include "ObjectDictionary.h"
#include "version.h"

#define SYS_FREQ (80000000L)

errorList_e error;

int32_t main(void)
{
    SYSTEMConfig(SYS_FREQ, SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
    INTConfigureSystem(INT_SYSTEM_CONFIG_MULT_VECTOR);

    HWAPI_InitialiseHardware();
    ADC_InitialiseADC();
    HWAPI_InitialiseInterfaces();

    INTEnableInterrupts();
    OBJECTDICT_setObject(MODULE_TYPE_REG, DIGITAL_BOARD_01);
    OBJECTDICT_setObject(SW_REV_REG, SOFTWARE_REVISION);  
    
    HWAPI_CheckIfServiceMode();      

    while (TRUE)
    {   
        ADC_ProcessAdcSamples();

        if (HWAPI_IsHalfSecondUp() == TRUE)
        {         
            CANAPPAPI_RequestToSendHeartBeat(CAN_1_AND_2);
            P_SM_ServiceStateMachine();
        }    
        
        CANAPPAPI_ProcessBridgeRxMessage(&error);
    }       
}