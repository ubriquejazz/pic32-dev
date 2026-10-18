#ifndef POWER_STATE_MACHINE_H_
#define POWER_STATE_MACHINE_H_

#include "global.h"

// FPGA heartbeat register
#define POWER_BOARD_LED_AD      0xFF0D

//FPGA interrupt registers
//#define NUMBER_OF_INT_REGISTERS    2
//#define TEMP_MIN_INT_EN_AD         0xF130
//#define TEMP_MAX_INT_EN_AD         0xF131
//#define TEMP_MIN_INT_REQ_AD        0xF132
//#define TEMP_MAX_INT_REQ_AD        0xF133
//#define TEMP_MIN_INT_EN_AD_VALUE   0x0001
//#define TEMP_MAX_INT_EN_AD_VALUE   0x0001

//#define PSU_PIC_INT_CONTROL_AD  0xF140

//FPGA Test registers
#define FPGA_TEST_MODE_BUILD_AD 0xFF0E
#define PSU_CLOCK_CONTROL_AD    0xF001                                  
#define PSU_ENABLE_CONTROL_AD   0xF000                                    
#define DUT_FITTED_TEST_MODE_AD 0xFF0C                              
#define BANK_0_VOLTAGE_AD       0xF010                                           
#define BANK_1_VOLTAGE_AD       0xF011                                      
#define BANK_2_VOLTAGE_AD       0xF012                                   
#define BANK_3_VOLTAGE_AD       0xF013                                       
#define V_GEN_VOLTAGE_AD        0xF014                                        
#define V_BAT_VOLTAGE_AD        0xF015                                        
#define V_THERM_VOLTAGE_AD      0xF016

//FPGA Register values for FPGA test build
#define NUMBER_OF_TEST_REGISTERS        11
#define FPGA_TEST_MODE_BUILD_AD_VALUE   0xAAAA
#define PSU_CLOCK_CONTROL_AD_VALUE      0x0007
#define PSU_ENABLE_CONTROL_AD_VALUE     0x007F
#define DUT_FITTED_TEST_MODE_AD_VALUE   0x6D64
#define BANK_0_VOLTAGE_AD_VALUE         0x0339
#define BANK_1_VOLTAGE_AD_VALUE         0x0339
#define BANK_2_VOLTAGE_AD_VALUE         0x0339
#define BANK_3_VOLTAGE_AD_VALUE         0x0339
#define V_GEN_VOLTAGE_AD_VALUE          0x0339
#define V_BAT_VOLTAGE_AD_VALUE          0x0339
#define V_THERM_VOLTAGE_AD_VALUE        0x0339

typedef struct {
    uint16_t address;
    uint16_t value;
} fpgaTestRegisters_t;

static const fpgaTestRegisters_t fpgaTestRegisters[NUMBER_OF_TEST_REGISTERS] =
{
    {FPGA_TEST_MODE_BUILD_AD, FPGA_TEST_MODE_BUILD_AD_VALUE},
    {DUT_FITTED_TEST_MODE_AD, DUT_FITTED_TEST_MODE_AD_VALUE},
    {PSU_CLOCK_CONTROL_AD, PSU_CLOCK_CONTROL_AD_VALUE},
    {PSU_ENABLE_CONTROL_AD, PSU_ENABLE_CONTROL_AD_VALUE},
    {BANK_0_VOLTAGE_AD, BANK_0_VOLTAGE_AD_VALUE},
    {BANK_1_VOLTAGE_AD, BANK_1_VOLTAGE_AD_VALUE},
    {BANK_2_VOLTAGE_AD, BANK_2_VOLTAGE_AD_VALUE},
    {BANK_3_VOLTAGE_AD, BANK_3_VOLTAGE_AD_VALUE},
    {V_GEN_VOLTAGE_AD, V_GEN_VOLTAGE_AD_VALUE},
    {V_BAT_VOLTAGE_AD, V_BAT_VOLTAGE_AD_VALUE},
    {V_THERM_VOLTAGE_AD, V_THERM_VOLTAGE_AD_VALUE}
};
/*
static const fpgaTestRegisters_t fpgaIntRegisters[NUMBER_OF_INT_REGISTERS] =
{
    {TEMP_MIN_INT_EN_AD, TEMP_MIN_INT_EN_AD_VALUE},
    {TEMP_MAX_INT_EN_AD, TEMP_MIN_INT_EN_AD_VALUE}
};
*/

/** States of the Power-up Statemachine*/ 
typedef enum{
    P_SM_IDLE_STATE = 0,
    P_SM_INIT_STATE, 
    P_SM_STANDBY_STATE, 
    P_SM_WAIT_POWER_GOODS, 
    P_SM_INIT_FPGA, 
    P_SM_CHECK_TEST_MODE,
    P_SM_FULLY_POWERED_READ_ONE_WIRE,
    P_SM_FULLY_POWERED, 
    P_SM_POWER_DOWN_STATE,
    P_SM_FPGA_HOLD_IN_RESET,
    P_SM_FPGA_RELEASE_RESET,
    P_SM_ERROR_STATE
} powerStates_e; 

void P_SM_ServiceStateMachine(void);
//void FPGA_Interrupt_Initialise(void);

#endif //POWER_STATE_MACHINE_H_

