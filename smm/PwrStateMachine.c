#include "HardwareSetup.h"
#include "PwrStateMachine.h"
#include "ObjectDictionary.h"
#include "CANAppLayer.h"
#include "i2c.h"

static powerStates_e powerState;
static uint32_t powerUpBladeStatus[8];

static BOOL verifyVoltages(void);
static BOOL checkForSystemErrors(void);
static void readComPowerStatus(uint16_t);

static BOOL sendCanMessage(uint8_t, CANBoardTypes_e, 
    uint16_t slot, uint32_t address, uint32_t dataToWrite, BOOL readRegister, uint32_t *buffer);

/**
* State machine for managing the power-up sequence.
*/
void P_SM_ServiceStateMachine(void)
{
   
    objectDictionary_t* pObjectDictionary;
    static uint32_t delayVoltageRise = 0;
    static uint32_t powerTrayPowerUpStatus = 0;
    
    mToggle_PIC_LED();
    
    switch (powerState) {
    case P_SM_IDLE_STATE:
        mClear_DIGI_RESET();
        // Request power tray to switch on 5V, 12V and 24V
        if( sendCanMessage(CAN_2, PSU_TRAY_BOARD_01, 
                HWAPI_getSlotId(), POWER_UP_MSG_REG, 1, FALSE, NULL ))
        {
            sendCanMessage(CAN_2, PSU_TRAY_BOARD_01, 
                HWAPI_getSlotId(), POWER_UP_MSG_REG, 0, TRUE, &powerTrayPowerUpStatus );
            if (powerTrayPowerUpStatus)
            {
                // ********** Temporary until Config tool comes on-line ************************
                // TODO
                //TCA9555_WriteTo(I2C_OUTPUT_PORT_EXPANDER, HOLD_BLADES_IN_RESET);
                pObjectDictionary = OBJECTDICT_getObject(POWER_UP_SLOT_REG);
                pObjectDictionary->value = 0xFF;
                TCA9555_WriteTo(I2C_OUTPUT_PORT_EXPANDER, REMOVE_RESET_FROM_BLADES);
                powerState = P_SM_INIT_STATE;
            }
        }
        break;
    case P_SM_INIT_STATE:
        delayVoltageRise = 0;
        powerState = P_SM_CONFIGURE_STATE;
        break;
    case P_SM_CONFIGURE_STATE:
        pObjectDictionary = OBJECTDICT_getObject(POWER_UP_SLOT_REG);
        pObjectDictionary->function = &P_SM_PowerUpSlot;
        if (!(ONE_WIRE_DEVICE_IsOneWireOperationInProgress()))
        {
            EEPROMS_ProcessMidplaneInfo();
            // configure EEPROM select function
            EEPROMS_SelectEEProm(SMM_EEPROM);

            pObjectDictionary = OBJECTDICT_getObject(SELECT_EEPROM_REG);
            pObjectDictionary->function = &EEPROMS_CANBusSelectEEProm;
            //mClear_DIGI_RESET();
            powerState = P_SM_DELAY_STATE;
        }
        break;
    case P_SM_DELAY_STATE:
        if (delayVoltageRise >= DELAY_FOR_POWER_SUPPLY_BRING_UP)
        {
            powerState = P_SM_READY_STATE;
        }
        else
        {
            delayVoltageRise++;
        }
        break;
    case P_SM_READY_STATE:
        if (verifyVoltages())
        {
            mSet_POWER_LED();
        }
        else
        {
            mClear_POWER_LED();
        }
        if (checkForSystemErrors())
        {
            mClear_SYS_LED();
        }
        else
        {
            mToggle_SYS_LED();
        }
        readComPowerStatus(8);
        break;
    default:
        powerState = P_SM_INIT_STATE; // should never really end up here.
    }    
}

/**
* Verifies the StandBy voltages of the board
* Verifies that V_FAN, 5V_STBY, 5V_MEAS, 3V3_MEAS and 12V_MEAS power supplies are within the
* required range and if not calls the errorhandling function to update the POWER ERROR reegister
*
* @return TRUE if all voltages verified correctly.  
*/
static BOOL 
verifyVoltages(void)
{
    objectDictionary_t *powerRail;    
    BOOL success;

    success = TRUE;
    
    powerRail = OBJECTDICT_getObject(V_FAN_MEAS);
    if( (powerRail->value < V_FAN_MEAS_MIN) || (powerRail->value > V_FAN_MEAS_MAX ) )
    {
        OBJECTDICT_errorHandler(SMM_BLADE_BOARD_FAN_SUPPLY_ERROR, 0);  
        success = FALSE;
    }

    powerRail = OBJECTDICT_getObject(V_5V_STBY_MEAS);
    if( (powerRail->value < V_5V_STBY_MEAS_MIN) || (powerRail->value > V_5V_STBY_MEAS_MAX ) )
    {
        OBJECTDICT_errorHandler(SMM_BLADE_BOARD_5V_STBY_MEAS_ERROR, 0);  
        success = FALSE;
    }

    powerRail = OBJECTDICT_getObject(V_5V_MEAS);
    if( (powerRail->value < V_5V_MEAS_MIN) || (powerRail->value > V_5V_MEAS_MAX ) )
    {
        OBJECTDICT_errorHandler(SMM_BLADE_BOARD_5V_MEAS_ERROR, 0);  
        success = FALSE;
    }

    powerRail = OBJECTDICT_getObject(V_3V3_MEAS);
    if( (powerRail->value < V_3V3_MEAS_MIN) || (powerRail->value > V_3V3_MEAS_MAX ) )
    {
        OBJECTDICT_errorHandler(SMM_BLADE_BOARD_3V3_MEAS_ERROR, 0);  
        success = FALSE;
    }
    
    powerRail = OBJECTDICT_getObject(V_12V_MEAS);
    if( (powerRail->value < V_12V_MEAS_MIN) || (powerRail->value > V_12V_MEAS_MAX ) )
    {
        OBJECTDICT_errorHandler(SMM_BLADE_BOARD_12V_MEAS_ERROR, 0);  
        success = FALSE;
    }
    
    return success;
}
    
static BOOL 
checkForSystemErrors(void)
{
    objectDictionary_t *heartbeats;
    BOOL systemOK;
    
    systemOK = TRUE;
    
    heartbeats = OBJECTDICT_getObject(COM_HEARTBEAT_STATUS_REG);
    if (heartbeats->value & 0xFF00)
    {
        systemOK = FALSE;
    }
    
    heartbeats = OBJECTDICT_getObject(POWER_HEARTBEAT_STATUS_REG);
    if (heartbeats->value & 0xFF00)
    {
        systemOK = FALSE;
    }
    
    heartbeats = OBJECTDICT_getObject(DIGITAL_HEARTBEAT_STATUS_REG);
    if (heartbeats->value & 0xFF00)
    {
        systemOK = FALSE;
    }
    
    heartbeats = OBJECTDICT_getObject(EXP_HEARTBEAT_STATUS_REG);
    if (heartbeats->value & 0xFF00)
    {
        systemOK = FALSE;
    }
    
    heartbeats = OBJECTDICT_getObject(POWER_TRAY_HEARTBEAT_STATUS_REG);
    if (heartbeats->value & 0xFF00)
    {
        systemOK = FALSE;
    }
    
    return systemOK;    
}    

BOOL 
P_SM_PowerUpSlot(uint32_t address, uint32_t data, BOOL readAccess)
{
    BOOL  success;
    uint16_t i2cBufferOutputValue;
    
    if (!(readAccess))
    {
        i2cBufferOutputValue = (uint16_t)(data & (0x00FF));                         // We're only interested  at the lower 8-bits to identify which of the 8 slots are to power_up
        i2cBufferOutputValue = i2cBufferOutputValue | (i2cBufferOutputValue << 8);  // The i2c buffer controls power enable and resets. So need to remove the reset as well as enable power.
        i2cBufferOutputValue = ~i2cBufferOutputValue;                               // A logic '0' actually enables the power.
        if (TCA9555_WriteTo(I2C_OUTPUT_PORT_EXPANDER, i2cBufferOutputValue))
        {   
            success = TRUE;
        }
        else
        {
            success = FALSE;
        }
    }
    else
    {
        success = TRUE;
    }
    
    return success;
}


static BOOL 
sendCanMessage(uint8_t canInterface, CANBoardTypes_e boardType, 
    uint16_t slot, uint32_t address, uint32_t dataToWrite, BOOL readRegister, uint32_t *buffer)
{
    uint32_t nodeId;
    BOOL success;

    nodeId = MIDPLANE_CFG_GetNodeId(boardType, slot);
    if (readRegister)
    {
        success = CANAPP_RequestToReadObject(canInterface, LOCAL_OBJECT, address, 0, nodeId, buffer, FALSE);    
    }
    else
    {
        success = CANAPP_RequestToWriteObject(canInterface, LOCAL_OBJECT, address, 0, nodeId, dataToWrite);
    } 
                
    return success;
}

static void 
readComPowerStatus(uint16_t max_com_slots)
{
    BOOL success;
    static uint16_t slotIndex = 0;
    uint32_t loopCounter;
    
    success = TRUE;
    loopCounter = 0;
    while (success)
    {
        success = sendCanMessage(CAN_1, COM_BOARD_01, slotIndex, 
            POWER_UP_MSG_REG, 0, TRUE, &powerUpBladeStatus[slotIndex] );
        if (success)
        {
            if (slotIndex == max_com_slots-1)
            {
                slotIndex = 0;
            }
            else
            {
                slotIndex++;
            }    
        }
        loopCounter++;
        if (loopCounter >= max_com_slots)
        {
            break;      //all COMS nave been interrogated
        }
    }
}