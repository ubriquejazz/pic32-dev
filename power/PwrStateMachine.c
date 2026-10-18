#include "PwrStateMachine.h"
#include "HardwareSetup.h"
#include "ObjectDictionary.h"

static powerStates_e powerState;
static uint16_t fpgaHeartBeatLed;

static BOOL verifyInitVoltages(void); 
static BOOL verifyTwelveVoltsRail(void);
static BOOL verifyAllPowerRails(void);

/**
* State machine for managing the power-up sequence.
* The state machine comprises of the following states:
* - P_SM_IDLE_STATE: enters at power up.
* - P_SM_INIT_STATE: moves from idle to this state after the first time the state machine is serviced. 
* - P_SM_STANDBY_STATE: If 3V3_STBY anf 5V_FILT voltage are correct moves into this state and waits for a POWER_UP_MSG_REG and switches on the PSUs.
* - P_SM_WAIT_POWER_GOODS: Verifies all power rails are correct.
* - P_SM_INIT_FPGA: Enables the configuration of the XILINX.
* - P_SM_CHECK_TEST_MODE: Check if the XILINX has a test build and if so lodas the XILINX registers with test values.
* - P_SM_FULLY_POWERED_TEST_MODE: If XILINX test Build, enters this state and remains in this state until a power down message is received.
* - P_SM_FULLY_POWERED: If not a test build enters this state and remains in this state until a power down message is received.
*                       While in this state it services the statemachine for DUT detection.
* - P_SM_POWER_DOWN_STATE: Power down the board and the moves into P_SM_INIT_STATE.
* - P_SM_ERROR_STATE: If a voltage doesn't verify moves into this state and powers down the board.
*/
void P_SM_ServiceStateMachine(void)
{
    objectDictionary_t *powerUpMessage;
    objectDictionary_t *flashToBootFrom;
    objectDictionary_t *resetFpgaReg;
    uint16_t FpgaTestRegisterValue;

    mToggle_PIC_LED();

    switch (powerState) {
        case P_SM_IDLE_STATE:
            mClear_POWER_LED();
            mSet_XIL_PROG_B();
            fpgaHeartBeatLed = 0;
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
                    mClear_XIL_PSU_ON_B();
                    mSet_POWER_LED(); 
                    powerState = P_SM_WAIT_POWER_GOODS;
                }
            }
            else
            {
                powerState = P_SM_ERROR_STATE;
            }
            break;
        case P_SM_WAIT_POWER_GOODS:
            if (verifyAllPowerRails() == TRUE)
            {
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
                if (powerUpMessage->value)      // received message to power down
                {
                    mSet_XIL_PROG_B();          // enable confuguration of the FPGA
                    if (mRead_XIL_DONE())       // wait for configuration to be downloaded to the FPGA
                    {
                        SPIOne_Initialise();    // need to re-initialise the SPI channel because there is no 
                                                // pull down on the frame sync line and before the FPGA gets initialised
                                                // this line floats causing a buffer overflow.
                        OBJECTDICT_setObject(FPGA_READY_MSG_REG, 1);
                        powerState = P_SM_CHECK_TEST_MODE;
                    }    
                }
                else
                {
                    powerState = P_SM_POWER_DOWN_STATE; 
                }
            } 
            break;

        case P_SM_CHECK_TEST_MODE:
            mSet_PIC_INT_2();   // stop holding the FPGA registers in reset
            powerState = P_SM_FULLY_POWERED_READ_ONE_WIRE;
            break;

        case P_SM_FULLY_POWERED_READ_ONE_WIRE:
            powerState = P_SM_FULLY_POWERED;
            break;
             
        case P_SM_FULLY_POWERED:
            mSet_PIC_INT_2();   // stop holding the FPGA registers in reset
            //initialiseFpgaInterrupts();
            resetFpgaReg = OBJECTDICT_getObject(FPGA_RESET_REG);
            if (resetFpgaReg->value)
            {
                powerState = P_SM_FPGA_HOLD_IN_RESET;
            }
            else
            {
    //      `     TODO re-enable this code when %v hardware bug is fixed
    //            if (verifyAllPowerRails() == FALSE) 
    //            {
    //                powerState = P_SM_ERROR_STATE;
    //            }
    //            else
                verifyAllPowerRails();
    //          if (intFromFPGA == TRUE)
    //          {
    //               processIntFromFPGA();
    //          }

                {            
                    powerUpMessage = OBJECTDICT_getObject(POWER_UP_MSG_REG);
                    if (powerUpMessage->value == FALSE) // received message to power down
                    {
                        powerState = P_SM_POWER_DOWN_STATE;
                    }
                    
                    if (fpgaHeartBeatLed) // toggle fpga led
                    {
                        fpgaHeartBeatLed = 0;
                    }
                    else
                    {
                        fpgaHeartBeatLed = 1;
                    }
                    
                    FPGA_API_Write(POWER_BOARD_LED_AD, fpgaHeartBeatLed);
                } 
            }
            break;
        case P_SM_POWER_DOWN_STATE:
            mClear_XIL_PROG_B();        // hold FPGA in reset
            mClear_PIC_INT_2();         // hold the register bits in the fpga to '0'
            mClear_POWER_LED();
            mSet_XIL_PSU_ON_B(); 
            OBJECTDICT_setObject(POWER_UP_MSG_REG, 0);
            OBJECTDICT_setObject(FPGA_READY_MSG_REG, 0);  
            powerState = P_SM_INIT_STATE;
            break;

        case P_SM_FPGA_HOLD_IN_RESET:
            mClear_XIL_PROG_B();    // disable configuration of the FPGA
            mClear_PIC_INT_2();     // hold the FPGA registers in reset
            //PROM_SHADOW_DisableShadowing();
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

        case P_SM_ERROR_STATE:
            mClear_XIL_PROG_B();        // hold FPGA in reset
            mClear_PIC_INT_2();         // hold the register bits in the fpga to '0'
            mClear_POWER_LED();
            mSet_XIL_PSU_ON_B();
            OBJECTDICT_setObject(POWER_UP_MSG_REG, 0);
            OBJECTDICT_setObject(FPGA_READY_MSG_REG, 0);  
            powerState = P_SM_INIT_STATE;
            break;

        default:
            powerState = P_SM_ERROR_STATE;
            break;
    }
}

/**
* Verifies the StandBy voltages of the board
* Verifies that 3V3_STBY and 5V_FILT power supplies are within the
* required range and if not calls the errorhandling function to update the POWER ERROR reegister
*
* @return TRUE if all voltages veerified correctly.  
*/
static BOOL 
verifyInitVoltages(void)
{
    objectDictionary_t *powerRail;    
    BOOL success;

    success = TRUE;

    powerRail = OBJECTDICT_getObject(V_MEAS_5V_FILT);
    if( (powerRail->value < V_MEAS_5V_FILT_MIN) || (powerRail->value > V_MEAS_5V_FILT_MAX ) )
    {
        OBJECTDICT_errorHandler(POWER_BOARD_V_MEAS_5V_FILT_ERROR, 0);  
        success = FALSE;
    }

    powerRail = OBJECTDICT_getObject(V_MEAS_3V3_STBY);
    if( (powerRail->value <  V_MEAS_3V3_STBY_MIN) || (powerRail->value >  V_MEAS_3V3_STBY_MAX ) )
    {
        OBJECTDICT_errorHandler(POWER_BOARD_V_MEAS_3V3_STBY_ERROR, 0);  
        success = FALSE;
    }
    
    return success;
}

/**
* Verifies the StandBy voltages of the board
* Verifies that 3V3_STBY and 5V_FILT power supplies are within the
* required range and if not calls the errorhandling function to update the POWER ERROR reegister
*
* @return TRUE if all voltages veerified correctly.  
*/
static BOOL 
verifyTwelveVoltsRail(void)
{
    objectDictionary_t *powerRail;    
    BOOL success;

    success = TRUE;

    powerRail = OBJECTDICT_getObject(V_MEAS_12V);
    if( (powerRail->value < V_MEAS_12V_MIN) || (powerRail->value > V_MEAS_12V_MAX ) )
    {
        OBJECTDICT_errorHandler(POWER_BOARD_V_MEAS_12V_ERROR, 0);  
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
    
    powerRail = OBJECTDICT_getObject(V_MEAS_1V2);
    if( (powerRail->value < V_MEAS_1V2_MIN) || (powerRail->value > V_MEAS_1V2_MAX ) )
    {
        OBJECTDICT_errorHandler(POWER_BOARD_V_MEAS_1V2_ERROR, 0);  
        success = FALSE;
    }

    powerRail = OBJECTDICT_getObject(V_MEAS_2V5);
    if( (powerRail->value < V_MEAS_2V5_MIN) || (powerRail->value > V_MEAS_2V5_MAX ) )
    {
        OBJECTDICT_errorHandler(POWER_BOARD_V_MEAS_2V5_ERROR, 0);  
        success = FALSE;
    }

    powerRail = OBJECTDICT_getObject(V_MEAS_3V3);
    if( (powerRail->value < V_MEAS_3V3_MIN) || (powerRail->value > V_MEAS_3V3_MAX ) )
    {
        OBJECTDICT_errorHandler(POWER_BOARD_V_MEAS_3V3_ERROR, 0);  
        success = FALSE;
    }

    powerRail = OBJECTDICT_getObject(V_MEAS_5V);
    if( (powerRail->value < V_MEAS_5V_MIN) || (powerRail->value > V_MEAS_5V_MAX ) )
    {
        OBJECTDICT_errorHandler(POWER_BOARD_V_MEAS_5V_ERROR, 0);  
        success = FALSE;
    }

    powerRail = OBJECTDICT_getObject(V_MEAS_NEG_5V);
    if( (powerRail->value < V_MEAS_NEG_5V_MIN) || (powerRail->value > V_MEAS_NEG_5V_MAX ) )
    {
        OBJECTDICT_errorHandler(POWER_BOARD_V_MEAS_NEG_5V_ERROR, 0);  
        success = FALSE;
    }

    powerRail = OBJECTDICT_getObject(V_MEAS_1V5);
    if( (powerRail->value < V_MEAS_1V5_MIN) || (powerRail->value > V_MEAS_1V5_MAX ) )
    {
        OBJECTDICT_errorHandler(POWER_BOARD_V_MEAS_1V5_ERROR, 0);  
        success = FALSE;
    }

    powerRail = OBJECTDICT_getObject(V_MEAS_VMGT);
    if( (powerRail->value < V_MEAS_VMGT_MIN) || (powerRail->value > V_MEAS_VMGT_MAX ) )
    {
        OBJECTDICT_errorHandler(POWER_BOARD_V_MEAS_VMGT_ERROR, 0);  
        success = FALSE;
    }

    powerRail = OBJECTDICT_getObject(V_MEAS_VTT);
    if( (powerRail->value < V_MEAS_VTT_MIN) || (powerRail->value > V_MEAS_VTT_MAX ) )
    {
        OBJECTDICT_errorHandler(POWER_BOARD_V_MEAS_VTT_ERROR, 0);  
        success = FALSE;
    }

    powerRail = OBJECTDICT_getObject(V_MEAS_NEG_3V);
    if( (powerRail->value < V_MEAS_NEG_3V_MIN) || (powerRail->value > V_MEAS_NEG_3V_MAX ) )
    {
        OBJECTDICT_errorHandler(POWER_BOARD_V_MEAS_NEG_3V_ERROR, 0);  
        success = FALSE;
    }

    return success;
}
