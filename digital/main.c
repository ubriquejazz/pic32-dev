#include "HardwareSetup.h"

#define SYS_FREQ (80000000L)

errorList_e error;

int32_t main(void)
{
    SYSTEMConfig(SYS_FREQ, SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
    INTConfigureSystem(INT_SYSTEM_CONFIG_MULT_VECTOR);

    HWAPI_InitialiseHardware();
    HWAPI_InitialiseInterfaces();

    INTEnableInterrupts();
    OBJECTDICT_API_setObject(MODULE_TYPE_REG, DIGITAL_BOARD_01);
    OBJECTDICT_API_setObject(SW_REV_REG, SOFTWARE_REVISION);  

    // find 1-wire devices on the bus
    if (ONE_WIRE_DEVICE_API_FindDevices() != TRUE)
    {
        OBJECTDICT_API_errorHandler(ONE_WIRE_BUS_ERROR, error);
    }
    
    HWAPI_CheckIfServiceMode();      

    while (TRUE)
    {   
        ADC_API_ProcessAdcSamples();

        if (HWAPI_IsHalfSecondUp() == TRUE)
        {         
            CANAPPAPI_RequestToSendHeartBeat(CAN_1_AND_2);
            P_SM_ServiceStateMachine();
            ONE_WIRE_DEVICE_API_ProcessOneWire(ONE_TEMPERATURE_READ, 0, NULL, 0, &error);
            SHADOW_Temperature_ServiceStateMachine();
        }    
        
        CANAPPAPI_ProcessBridgeRxMessage(&error);         

        if ( ONE_WIRE_DEVICE_API_ProcessOneWire(ONE_DEVICE_PROCESS_COMMAND, 0, NULL, 0, &error) != TRUE)
        {
            OBJECTDICT_API_errorHandler(ONE_WIRE_EEPROM_ERROR, error);
        }   
        XIL_FLASH_PROG_ServiceStateMachine();
        PROM_SHADOW_ServiceStateMachine();
    }       
}