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

    OBJECTDICT_setObject(MODULE_TYPE_REG, DIGITAL_BOARD);
    OBJECTDICT_setObject(SW_REV_REG, SOFTWARE_REVISION);  
    
    HWAPI_CheckIfServiceMode();      

    while (TRUE)
    {   
        ADC_ProcessAdcSamples();

        if (HWAPI_IsHalfSecondUp() == TRUE)
        {         
            CANAPP_RequestToSendHeartBeat(CAN_1_AND_2);
            P_SM_ServiceStateMachine();
        }    
        
        if ( !CANAPP_ProcessRxMessage(&error) )
        {
            OBJECTDICT_errorHandler(CAN_ERROR, error);
        }       
    }       
}