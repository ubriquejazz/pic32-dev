#include "PwrStateMachine.h"
#include "HardwareSetup.h"
#include "ObjectDictionary.h"

static powerStates_e powerState;

static BOOL verifyInitVoltages(void);
static BOOL verifyTwelveVoltsRail(void);
static BOOL verifyAllPowerRails(void);

/**
* State Machine for managing the power status of the Digital board
* The state machine comprises of the following states:
* - P_SM_IDLE_STATE: enters at power up
* - P_SM_INIT_STATE: moves from idle to this state after the first time the state machine is serviced 
* - P_SM_STANDBY_STATE: If 3V3_STBY voltage is correct moves into this state and waits for POWER_UP_MSG_REG  
* - P_SM_DELAY_12V_ON_STATE: Delay for the 12V to ramp-up  
* - P_SM_12V_ON_STATE: Switch on the Digital power 
* - P_SM_POWER_ON_STATE: Veifies all Power supplies are within limits 
* - P_SM_INIT_FPGA: Enables the FPGA configuration and waits for the XILINX DONE to be asserted      
* - P_SM_FULLY_POWERED: Remains in this state until a power down message is received  
* - P_SM_POWER_DOWN_STATE: Power down the board and the moves into P_SM_INIT_STATE.
* - P_SM_ERROR_STATE: If a voltage doesn't verify moves into this state and powers down the board
*/
void P_SM_ServiceStateMachine(void)
{
    objectDictionary_t *powerUpMessage;
    objectDictionary_t *flashToBootFrom;
    objectDictionary_t *resetFpgaReg;

    mToggle_PIC_LED();

    switch (powerState) {
        case P_SM_IDLE_STATE:
            mClear_POWER_LED();
            mClear_DIG_12V_ON();        // switch off 12V supply to ppower board
            mSet_XIL_PROG_B();
            powerState = P_SM_INIT_STATE;
            break;
        case P_SM_INIT_STATE:
            if (verifyInitVoltages() == TRUE)
            {  
                powerState = P_SM_STANDBY_STATE;
            }
            else
            {
                powerState = P_SM_ERROR_STATE;
            }
            break;
        case P_SM_STANDBY_STATE:
            if (verifyInitVoltages() == TRUE) 
            {
                powerUpMessage = OBJECTDICT_getObject(POWER_UP_MSG_REG);
                if (powerUpMessage->value == TRUE)
                {
                    mSet_XIL_INIT_DRIVE_B();
                    mClear_XIL_PROG_B();        // hold FPGA in reset
                    mClear_PIC_INT_2();         // hold the register bits in the fpga to '0'
                    mSet_DIG_12V_ON();          // switch on 12V supply       
                    powerState = P_SM_DELAY_12V_ON_STATE;
                }
            }
            else
            {
                powerState = P_SM_ERROR_STATE;
            }
            break;
        case P_SM_DELAY_12V_ON_STATE:
                powerState = P_SM_12V_ON_STATE;
            break;
        case P_SM_12V_ON_STATE:
                mSet_DIG_PWR_ON();
                mSet_POWER_LED();
                powerState = P_SM_POWER_ON_STATE;
            break;
        case P_SM_POWER_ON_STATE:
            if (verifyAllPowerRails() == TRUE)
            {
                flashToBootFrom = OBJECTDICT_getObject(FPGA_BOOT_FLASH_REG);
                XILFLASH_API_SelectFlash(flashToBootFrom->value);
                powerState = P_SM_INIT_FPGA;
            }
            else
            {
                powerState = P_SM_ERROR_STATE;
            }
            break;
        case P_SM_INIT_FPGA:
            resetFpgaReg = OBJECTDICT_getObject(FPGA_RESET_REG);
            if (resetFpgaReg->value)
            {
                powerState = P_SM_FPGA_HOLD_IN_RESET;
            }
            else
            {
                powerUpMessage = OBJECTDICT_getObject(POWER_UP_MSG_REG);
                if (powerUpMessage->value)      // received message to power up
                {
                    mSet_XIL_PROG_B();          // enable configuration of the FPGA
                    if (mRead_XIL_DONE())       // wait for configuration to be downloaded to the FPGA
                    {
                        OBJECTDICT_setObject(FPGA_READY_MSG_REG, 1);
                        powerState = P_SM_FULLY_POWERED_READ_ONE_WIRE;
                    }    
                }
                else
                {
                    powerState = P_SM_POWER_DOWN_STATE; 
                }
            }
            break;
        case P_SM_FULLY_POWERED_READ_ONE_WIRE:
            mSet_PIC_INT_2();   // stop holding the FPGA registers in reset
            powerState = P_SM_FULLY_POWERED;
            break;
        case P_SM_FULLY_POWERED:
            resetFpgaReg = OBJECTDICT_getObject(FPGA_RESET_REG);
            if (resetFpgaReg->value)
            {
                powerState = P_SM_FPGA_HOLD_IN_RESET;
            }
            else
            {
                mSet_PIC_INT_2();   // stop holding the FPGA registers in reset
                if (verifyAllPowerRails() == FALSE)
                {
                    powerState = P_SM_ERROR_STATE;
                }
                else
                {            
                    powerUpMessage = OBJECTDICT_getObject(POWER_UP_MSG_REG);
                    if (!(powerUpMessage->value)) // received message to power down
                    {
                        powerState = P_SM_POWER_DOWN_STATE;
                    }
                } 
            }
            break;
        case P_SM_FPGA_HOLD_IN_RESET:
            mClear_XIL_PROG_B();    // disable configuration of the FPGA
            mClear_PIC_INT_2();     // hold the FPGA registers in reset
            OBJECTDICT_setObject(FPGA_READY_MSG_REG, 0);
            flashToBootFrom = OBJECTDICT_getObject(FPGA_BOOT_FLASH_REG);
            XILFLASH_API_SelectFlash(flashToBootFrom->value);
            powerState = P_SM_FPGA_RELEASE_RESET; 
            break;
        case P_SM_FPGA_RELEASE_RESET:
            mSet_XIL_PROG_B();          // enable configuration of the FPGA
            OBJECTDICT_setObject(FPGA_RESET_REG, 0);
            powerState = P_SM_INIT_FPGA;
            break;    
        case P_SM_POWER_DOWN_STATE:
            mClear_XIL_PROG_B();        // hold FPGA in reset
            mClear_PIC_INT_2();         // hold the register bits in the fpga to '0'
            mClear_POWER_LED();
            mClear_DIG_PWR_ON();        // switch off digital PSUs    
            mClear_DIG_12V_ON();        // switch off 12V supply 

            OBJECTDICT_setObject(POWER_UP_MSG_REG, 0);
            OBJECTDICT_setObject(FPGA_READY_MSG_REG, 0);  
            powerState = P_SM_INIT_STATE;
            break;
        case P_SM_ERROR_STATE:
            mClear_XIL_PROG_B();        // hold FPGA in reset
            mClear_PIC_INT_2();         // hold the register bits in the fpga to '0'
            mClear_POWER_LED();
            mClear_DIG_PWR_ON();        // switch off digital PSUs    
            mClear_DIG_12V_ON();        // switch off 12V supply

            OBJECTDICT_setObject(POWER_UP_MSG_REG, 0);
            OBJECTDICT_setObject(FPGA_READY_MSG_REG, 0);  
            powerState = P_SM_INIT_STATE;
            break;
        default:
            powerState = P_SM_ERROR_STATE;
            break;
    }
}

static BOOL 
verifyInitVoltages(void)
{
    objectDictionary_t *powerRail;    
    BOOL success;

    success = TRUE;

    powerRail = OBJECTDICT_getObject(ATOD_3V3_STBY);
    if( (powerRail->value < ATOD_3V3_STBY_MIN) || (powerRail->value > ATOD_3V3_STBY_MAX ) )
    {
        OBJECTDICT_errorHandler(DIGITAL_BOARD_ATOD_3V3_STBY_ERROR, 0);  
        success = FALSE;
    }

    return success;
}

static BOOL 
verifyTwelveVoltsRail(void)
{
    objectDictionary_t *powerRail;    
    BOOL success;

    success = TRUE;

    powerRail = OBJECTDICT_getObject(V_MEAS_12V);
    if( (powerRail->value < V_MEAS_12V_MIN) || (powerRail->value > V_MEAS_12V_MAX ) )
    {
        OBJECTDICT_errorHandler(DIGITAL_BOARD_V_MEAS_12V_ERROR, 0);  
        success = FALSE;
    }
    return success;
}

static BOOL 
verifyAllPowerRails(void)
{
    objectDictionary_t *powerRail;    
    BOOL success;

    success = TRUE;

    if (verifyInitVoltages() == FALSE)
    {
        success = FALSE;
    }
    if (verifyTwelveVoltsRail() == FALSE)
    {
        success = FALSE;
    }
    
    powerRail = OBJECTDICT_getObject(PCI_VCC_MON);
    if( (powerRail->value < PCI_VCC_MON_MIN) || (powerRail->value > PCI_VCC_MON_MAX ) )
    {
        OBJECTDICT_errorHandler(DIGITAL_BOARD_PCI_VCC_MON_ERROR, 0);  
        success = FALSE;
    }
    
    powerRail = OBJECTDICT_getObject(PCI_PLL_MON);
    if( (powerRail->value < PCI_PLL_MON_MIN) || (powerRail->value > PCI_PLL_MON_MAX ) )
    {
        OBJECTDICT_errorHandler(DIGITAL_BOARD_PCI_PLL_MON_ERROR, 0);  
        success = FALSE;
    }

    powerRail = OBJECTDICT_getObject(PCI_TX_MON);
    if( (powerRail->value < PCI_TX_MON_MIN) || (powerRail->value > PCI_TX_MON_MAX ) )
    {
        OBJECTDICT_errorHandler(DIGITAL_BOARD_PCI_TX_MON_ERROR, 0);  
        success = FALSE;
    }

    powerRail = OBJECTDICT_getObject(PCI_RX_MON);
    if( (powerRail->value < PCI_RX_MON_MIN) || (powerRail->value > PCI_RX_MON_MAX ) )
    {
        OBJECTDICT_errorHandler(DIGITAL_BOARD_PCI_RX_MON_ERROR, 0);  
        success = FALSE;
    }
    
    powerRail = OBJECTDICT_getObject(AUR_VCC_MON);
    if( (powerRail->value < AUR_VCC_MON_MIN) || (powerRail->value > AUR_VCC_MON_MAX ) )
    {
        OBJECTDICT_errorHandler(DIGITAL_BOARD_AUR_VCC_MON_ERROR, 0);  
        success = FALSE;
    }
    
    powerRail = OBJECTDICT_getObject(AUR_PLL_MON);
    if( (powerRail->value < AUR_PLL_MON_MIN) || (powerRail->value > AUR_PLL_MON_MAX ) )
    {
        OBJECTDICT_errorHandler(DIGITAL_BOARD_AUR_PLL_MON_ERROR, 0);  
        success = FALSE;
    }
    
    powerRail = OBJECTDICT_getObject(AUR_TX_MON);
    if( (powerRail->value < AUR_TX_MON_MIN) || (powerRail->value > AUR_TX_MON_MAX ) )
    {
        OBJECTDICT_errorHandler(DIGITAL_BOARD_AUR_TX_MON_ERROR, 0);  
        success = FALSE;
    }
    
    powerRail = OBJECTDICT_getObject(AUR_RX_MON);
    if( (powerRail->value < AUR_RX_MON_MIN) || (powerRail->value > AUR_RX_MON_MAX ) )
    {
        OBJECTDICT_errorHandler(DIGITAL_BOARD_AUR_RX_MON_ERROR, 0);  
        success = FALSE;
    }

    powerRail = OBJECTDICT_getObject(V_MEAS_NEG_5V);
    if( (powerRail->value < V_MEAS_NEG_5V_MIN) || (powerRail->value > V_MEAS_NEG_5V_MAX ) )
    {
        OBJECTDICT_errorHandler(DIGITAL_BOARD_V_MEAS_NEG_5V_ERROR, 0);  
        success = FALSE;
    }

    powerRail = OBJECTDICT_getObject(V_MEAS_5V);
    if( (powerRail->value < V_MEAS_5V_MIN) || (powerRail->value > V_MEAS_5V_MAX ) )
    {
        OBJECTDICT_errorHandler(DIGITAL_BOARD_V_MEAS_5V_ERROR, 0);  
        success = FALSE;
    }

    powerRail = OBJECTDICT_getObject(V_MEAS_3V3);
    if( (powerRail->value < V_MEAS_3V3_MIN) || (powerRail->value > V_MEAS_3V3_MAX ) )
    {
        OBJECTDICT_errorHandler(DIGITAL_BOARD_V_MEAS_3V3_ERROR, 0);  
        success = FALSE;
    }

    powerRail = OBJECTDICT_getObject(V_MEAS_2V5);
    if( (powerRail->value < V_MEAS_2V5_MIN) || (powerRail->value > V_MEAS_2V5_MAX ) )
    {
        OBJECTDICT_errorHandler(DIGITAL_BOARD_V_MEAS_2V5_ERROR, 0);  
        success = FALSE;
    }

    powerRail = OBJECTDICT_getObject(V_MEAS_GROUND);
    if( (powerRail->value < V_MEAS_GROUND_MIN) || (powerRail->value > V_MEAS_GROUND_MAX ) )
    {
        OBJECTDICT_errorHandler(DIGITAL_BOARD_V_MEAS_GROUND_ERROR, 0);  
        success = FALSE;
    }

    powerRail = OBJECTDICT_getObject(V_MEAS_1V);
    if( (powerRail->value < V_MEAS_1V_MIN) || (powerRail->value > V_MEAS_1V_MAX ) )
    {
        OBJECTDICT_errorHandler(DIGITAL_BOARD_V_MEAS_1V_ERROR, 0);  
        success = FALSE;
    }

    return success;
}
