#ifndef POWER_STATE_MACHINE_H_
#define POWER_STATE_MACHINE_H_

#include "global.h"

typedef struct {
    uint16_t address;
    uint16_t value;
} fpgaTestRegisters_t;

// POWER FPGA REGISTER ADDRESSES
#define POWER_FPGA_PSU_PG_STATUS_AD         0xF004
#define POWER_FPGA_FPGA_TEST_MODE_BUILD_AD  0xFF0E
#define POWER_FPGA_PSU_ENABLE_CONTROL_AD    0xF000                                    
#define POWER_FPGA_PSU_CLOCK_CONTROL_AD     0xF001
#define POWER_FPGA_PSU_MUX_SELECT_AD        0xF005
#define POWER_FPGA_PSU_MUX_SELECT_ERROR_AD  0xF006
#define POWER_FPGA_BANK_0_VOLTAGE_AD        0xF010                                           
#define POWER_FPGA_BANK_1_VOLTAGE_AD        0xF011                                      
#define POWER_FPGA_BANK_2_VOLTAGE_AD        0xF012                                   
#define POWER_FPGA_BANK_3_VOLTAGE_AD        0xF013                                       
#define POWER_FPGA_V_GEN_VOLTAGE_AD         0xF014                                        
#define POWER_FPGA_V_BAT_VOLTAGE_AD         0xF015                                        
#define POWER_FPGA_V_THERM_VOLTAGE_AD       0xF016
#define POWER_FPGA_VLAB_0_VOLTAGE_AD        0xF018
#define POWER_FPGA_VLAB_1_VOLTAGE_AD        0xF019
#define POWER_FPGA_VLAB_2_VOLTAGE_AD        0xF01A
#define POWER_FPGA_VLAB_3_VOLTAGE_AD        0xF01B

// POWER FPGA REGISTER VALUES
#define POWER_FPGA_NUMBER_OF_REGISTERS              14
#define POWER_FPGA_PSU_ENABLE_CONTROL_AD_VALUE      0x023F                                        
#define POWER_FPGA_PSU_CLOCK_CONTROL_AD_VALUE       0x0007  
#define POWER_FPGA_PSU_MUX_SELECT_AD_VALUE          0x0000
#define POWER_FPGA_PSU_MUX_SELECT_ERROR_AD_VALUE    0x0000 
#define POWER_FPGA_BANK_0_VOLTAGE_AD_VALUE          0x0339                                                   
#define POWER_FPGA_BANK_1_VOLTAGE_AD_VALUE          0x0271                                    
#define POWER_FPGA_BANK_2_VOLTAGE_AD_VALUE          0x0339                                 
#define POWER_FPGA_BANK_3_VOLTAGE_AD_VALUE          0x0339                                      
#define POWER_FPGA_V_GEN_VOLTAGE_AD_VALUE           0x0339                                      
#define POWER_FPGA_V_BAT_VOLTAGE_AD_VALUE           0x0339                                      
#define POWER_FPGA_V_THERM_VOLTAGE_AD_VALUE         0x0000
#define POWER_FPGA_VLAB_0_VOLTAGE_AD_VALUE          0x0000
#define POWER_FPGA_VLAB_1_VOLTAGE_AD_VALUE          0x0339
#define POWER_FPGA_VLAB_2_VOLTAGE_AD_VALUE          0x0000 
#define POWER_FPGA_VLAB_3_VOLTAGE_AD_VALUE          0x0000

static const fpgaTestRegisters_t powerFpgaRegisters[POWER_FPGA_NUMBER_OF_REGISTERS] =
{
    { POWER_FPGA_PSU_CLOCK_CONTROL_AD, POWER_FPGA_PSU_CLOCK_CONTROL_AD_VALUE },
    { POWER_FPGA_PSU_MUX_SELECT_AD, POWER_FPGA_PSU_MUX_SELECT_AD_VALUE },
    { POWER_FPGA_PSU_MUX_SELECT_ERROR_AD, POWER_FPGA_PSU_MUX_SELECT_ERROR_AD_VALUE },
    { POWER_FPGA_BANK_0_VOLTAGE_AD, POWER_FPGA_BANK_0_VOLTAGE_AD_VALUE },
    { POWER_FPGA_BANK_1_VOLTAGE_AD, POWER_FPGA_BANK_1_VOLTAGE_AD_VALUE },
    { POWER_FPGA_BANK_2_VOLTAGE_AD, POWER_FPGA_BANK_2_VOLTAGE_AD_VALUE },
    { POWER_FPGA_BANK_3_VOLTAGE_AD, POWER_FPGA_BANK_3_VOLTAGE_AD_VALUE },
    { POWER_FPGA_V_GEN_VOLTAGE_AD, POWER_FPGA_V_GEN_VOLTAGE_AD_VALUE },
    { POWER_FPGA_V_BAT_VOLTAGE_AD, POWER_FPGA_V_BAT_VOLTAGE_AD_VALUE },
    { POWER_FPGA_V_THERM_VOLTAGE_AD, POWER_FPGA_V_THERM_VOLTAGE_AD_VALUE },
    { POWER_FPGA_VLAB_0_VOLTAGE_AD, POWER_FPGA_VLAB_0_VOLTAGE_AD_VALUE },
    { POWER_FPGA_VLAB_1_VOLTAGE_AD, POWER_FPGA_VLAB_1_VOLTAGE_AD_VALUE },
    { POWER_FPGA_VLAB_2_VOLTAGE_AD, POWER_FPGA_VLAB_2_VOLTAGE_AD_VALUE },
    { POWER_FPGA_VLAB_3_VOLTAGE_AD, POWER_FPGA_VLAB_3_VOLTAGE_AD_VALUE }
};

// DIGITAL FPGA REGISTERS ADDRESS
#define FPGA_VERSION_REG        0x0A1D
#define FPGA_DUT_CONTROL_REG    0x7020
#define PWR_MODULE_CONTROL_REG  0x7021
#define COMPATIBILITY_REG       0x7022
#define PIO_OUTPUT_15_0_REG     0x6040
#define PIO_OUTPUT_31_16_REG    0x6041
#define SHIFT_01_02_REG         0x8040
#define SHIFT_03_REG            0x6050
#define SHIFT_04_REG            0x6051
#define SHIFT_05_REG            0x8042
#define IO_V_0                  0x8000 
#define IO_V_1                  0x8001 
#define IO_V_2                  0x8002 
#define IO_V_3                  0x8003 
#define IO_V_4                  0x8004 
#define IO_V_5                  0x8005 
#define IO_V_6                  0x8006 
#define IO_V_7                  0x8007 
#define IO_V_8                  0x8008 
#define IO_V_9                  0x8009 
#define IO_V_10                 0x800A 
#define IO_V_11                 0x800B 
#define IO_V_12                 0x800C 
#define IO_V_13                 0x800D 
#define IO_V_14                 0x800E 
#define IO_V_15                 0x800F 
#define DUT_CLK_REF_V           0x8010                           
#define CLK_REF_V               0x8011                                    
#define UART2_REF_V             0x8012                                         
#define SPI_CTL_REF_V           0x8013                               
#define SYS_CTL_REF_V           0x8014                               
#define PCM2_REF_V              0x8015                                
#define UART1_REF_V             0x8016                              
#define PCM1_REF_V              0x8017
#define TP411                   0x8018                                           
#define TP412                   0x8019                                           
#define I2C_REF_V               0x801A                                     
#define MSPI_REF_V              0x801B                                  
#define DUT_RST_V               0x801C                                   
#define PCM_MAS_SLA_REF_V       0x801D
#define V_REG_REF_V             0x801E
#define SPI_REF_V               0x801F                                     

// DIGITAL FPGA PIO VALUES
#define NUMBER_OF_PIO_REGISTERS         38
#define PIO_OUTPUT_15_0_REG_VALUE       0x0000
#define PIO_OUTPUT_31_16_REG_VALUE      0x0000
#define SHIFT_01_02_REG_VALUE           0x0CE1
#define SHIFT_03_REG_VALUE              0x0000
#define SHIFT_04_REG_VALUE              0x0000
#define SHIFT_05_REG_VALUE              0x0088
#define IO_V_0_VALUE                    0x0070 
#define IO_V_1_VALUE                    0x0070 
#define IO_V_2_VALUE                    0x0070 
#define IO_V_3_VALUE                    0x0070 
#define IO_V_4_VALUE                    0x0070 
#define IO_V_5_VALUE                    0x0070 
#define IO_V_6_VALUE                    0x0070 
#define IO_V_7_VALUE                    0x0070 
#define IO_V_8_VALUE                    0x0070 
#define IO_V_9_VALUE                    0x0070 
#define IO_V_10_VALUE                   0x0000 
#define IO_V_11_VALUE                   0x0000 
#define IO_V_12_VALUE                   0x0000 
#define IO_V_13_VALUE                   0x0000 
#define IO_V_14_VALUE                   0x0000 
#define IO_V_15_VALUE                   0x0000 
#define DUT_CLK_REF_V_VALUE             0x0000                           
#define CLK_REF_V_VALUE                 0x0000                                    
#define UART2_REF_V_VALUE               0x0000                                                       
#define SPI_CTL_REF_V_VALUE             0x0070                               
#define SYS_CTL_REF_V_VALUE             0x0000                               
#define PCM2_REF_V_VALUE                0x0070                                
#define UART1_REF_V_VALUE               0x0070                              
#define PCM1_REF_V_VALUE                0x0070
#define TP411_VALUE                     0x0070                                           
#define TP412_VALUE                     0x00CE                                           
#define I2C_REF_V_VALUE                 0x0000                                     
#define MSPI_REF_V_VALUE                0x0000                                  
#define DUT_RST_V_VALUE                 0x0070                                   
#define PCM_MAS_SLA_REF_V_VALUE         0x0000
#define V_REG_REF_V_VALUE               0x0000
#define SPI_REF_V_VALUE                 0x0070  

static const fpgaTestRegisters_t digitalFpgaRegisters[NUMBER_OF_PIO_REGISTERS] =
{
    {PIO_OUTPUT_15_0_REG, PIO_OUTPUT_15_0_REG_VALUE},
    {PIO_OUTPUT_31_16_REG, PIO_OUTPUT_31_16_REG_VALUE},
    {SHIFT_01_02_REG, SHIFT_01_02_REG_VALUE},
    {SHIFT_03_REG, SHIFT_03_REG_VALUE},
    {SHIFT_04_REG, SHIFT_04_REG_VALUE},
    {SHIFT_05_REG, SHIFT_05_REG_VALUE},
    {IO_V_0, IO_V_0_VALUE},
    {IO_V_1, IO_V_1_VALUE},
    {IO_V_2, IO_V_2_VALUE},
    {IO_V_3, IO_V_3_VALUE},
    {IO_V_4, IO_V_4_VALUE},
    {IO_V_5, IO_V_5_VALUE},
    {IO_V_6, IO_V_6_VALUE},
    {IO_V_7, IO_V_7_VALUE},
    {IO_V_8, IO_V_8_VALUE},
    {IO_V_9, IO_V_9_VALUE},
    {IO_V_10, IO_V_10_VALUE},
    {IO_V_11, IO_V_11_VALUE},
    {IO_V_12, IO_V_12_VALUE },
    {IO_V_13, IO_V_13_VALUE},
    {IO_V_14, IO_V_14_VALUE},
    {IO_V_15, IO_V_15_VALUE},
    {DUT_CLK_REF_V, DUT_CLK_REF_V_VALUE},
    {CLK_REF_V, CLK_REF_V_VALUE},
    {UART2_REF_V, UART2_REF_V_VALUE},
    {SPI_CTL_REF_V, SPI_CTL_REF_V_VALUE},
    {SYS_CTL_REF_V, SYS_CTL_REF_V_VALUE},
    {PCM2_REF_V, PCM2_REF_V_VALUE},
    {UART1_REF_V, UART1_REF_V_VALUE},
    {PCM1_REF_V, PCM1_REF_V_VALUE},
    {TP411, TP411_VALUE},
    {TP412, TP412_VALUE},
    {I2C_REF_V, I2C_REF_V_VALUE},
    {MSPI_REF_V, MSPI_REF_V_VALUE},
    {DUT_RST_V, DUT_RST_V_VALUE },
    {PCM_MAS_SLA_REF_V, PCM_MAS_SLA_REF_V_VALUE},
    {V_REG_REF_V, V_REG_REF_V_VALUE},
    {SPI_REF_V, SPI_REF_V_VALUE}
};

typedef union {
	struct {
        unsigned DUT_DETECT:1;
        unsigned ADP_DETECT:1;
        unsigned DUT_RESET:1;
        unsigned DUT_BUFFERS_ENABLE:1;
        unsigned DUT_12V_ENABLE:1;
        unsigned DUT_12V_PSU_OK:1;
        unsigned DUT_3V3_ENABLE:1;
        unsigned DUT_3V3_PSU_OK:1;
        unsigned DIGITAL_MODULE_READY:1;
        unsigned POWER_MODULE_READY:1;
        unsigned:6;
    };
    uint16_t word;
} fpgaDutControlReg_t;

typedef union {
	struct {
        unsigned COMPATIBILITY_0:1;
        unsigned COMPATIBILITY_1:1;
        unsigned COMPATIBILITY_2:1;
        unsigned :5;
        unsigned VARIANT_0:1;
        unsigned VARIANT_1:1;
        unsigned VARIANT_2:1;
        unsigned:5;
    };
    uint16_t word;
} compatibilityReg_t;

typedef union {
	struct {
        unsigned PG_BANK_0:1;
        unsigned PG_BANK_1:1;
        unsigned PG_BANK_2:1;
        unsigned PG_BANK_3:1;
        unsigned PG_VGEN:1;
        unsigned PG_VBAT:1;
        unsigned PG_VTHERM:1;
        unsigned :1;
        unsigned PG_VLAB_0:1;
        unsigned PG_VLAB_1:1;
        unsigned PG_VLAB_2:1;
        unsigned PG_VLAB_3:1;
        unsigned :4;
    };
    uint16_t word;
} powerFpgaPgStatusReg_t;
    
typedef enum{
    P_SM_IDLE_STATE = 0,
    P_SM_INIT_STATE, 
    P_SM_STANDBY_STATE, 
    P_SM_DELAY_12V_ON_STATE, 
    P_SM_12V_ON_STATE, 
    P_SM_POWER_ON_STATE, 
    P_SM_INIT_FPGA,
    P_SM_FULLY_POWERED_READ_ONE_WIRE,
    P_SM_FULLY_POWERED,     
    P_SM_POWER_DOWN_STATE,
    P_SM_FPGA_HOLD_IN_RESET,
    P_SM_FPGA_RELEASE_RESET,
    P_SM_ERROR_STATE
} powerStates_e; 

void P_SM_ServiceStateMachine(void);

#endif //POWER_STATE_MACHINE_H_

