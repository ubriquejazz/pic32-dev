#ifndef HARDWARE_SETUP_H_
#define HARDWARE_SETUP_H_

#include "global.h"
#include "ObjectDictionary.h"

#define BIT_31                       (1 << 31)
#define BIT_30                       (1 << 30)
#define BIT_29                       (1 << 29)
#define BIT_28                       (1 << 28)
#define BIT_27                       (1 << 27)
#define BIT_26                       (1 << 26)
#define BIT_25                       (1 << 25)
#define BIT_24                       (1 << 24)
#define BIT_23                       (1 << 23)
#define BIT_22                       (1 << 22)
#define BIT_21                       (1 << 21)
#define BIT_20                       (1 << 20)
#define BIT_19                       (1 << 19)
#define BIT_18                       (1 << 18)
#define BIT_17                       (1 << 17)
#define BIT_16                       (1 << 16)
#define BIT_15                       (1 << 15)
#define BIT_14                       (1 << 14)
#define BIT_13                       (1 << 13)
#define BIT_12                       (1 << 12)
#define BIT_11                       (1 << 11)
#define BIT_10                       (1 << 10)
#define BIT_9                        (1 << 9)
#define BIT_8                        (1 << 8)
#define BIT_7                        (1 << 7)
#define BIT_6                        (1 << 6)
#define BIT_5                        (1 << 5)
#define BIT_4                        (1 << 4)
#define BIT_3                        (1 << 3)
#define BIT_2                        (1 << 2)
#define BIT_1                        (1 << 1)
#define BIT_0                        (1 << 0)

// PORTA
#define mRead_PIC_JTAG_TMS()        (PORTA & (uint32_t)(_PORTA_RA0_MASK))
#define mSet_PIC_JTAG_TMS()         (LATASET = (uint32_t)(_PORTA_RA0_MASK))
#define mClear_PIC_JTAG_TMS()       (LATACLR = (uint32_t)(_PORTA_RA0_MASK))
#define mToggle_PIC_JTAG_TMS()      (LATAINV = (uint32_t)(_PORTA_RA0_MASK))

#define mRead_PIC_JTAG_TCK()        (PORTA & (uint32_t)(_PORTA_RA1_MASK))
#define mSet_PIC_JTAG_TCK()         (LATASET = (uint32_t)(_PORTA_RA1_MASK))
#define mClear_PIC_JTAG_TCK()       (LATACLR = (uint32_t)(_PORTA_RA1_MASK))
#define mToggle_PIC_JTAG_TCK()      (LATAINV = (uint32_t)(_PORTA_RA1_MASK))

#define mRead_I2C_CLK()             (PORTA & (uint32_t)(_PORTA_RA2_MASK))
#define mSet_I2C_CLK()              (LATASET = (uint32_t)(_PORTA_RA2_MASK))
#define mClear_I2C_CLK()            (LATACLR = (uint32_t)(_PORTA_RA2_MASK))
#define mToggle_I2C_CLK()           (LATAINV = (uint32_t)(_PORTA_RA2_MASK))

#define mRead_I2C_DATA()            (PORTA & (uint32_t)(_PORTA_RA3_MASK))
#define mSet_I2C_DATA()             (LATASET = (uint32_t)(_PORTA_RA3_MASK))
#define mClear_I2C_DATA()           (LATACLR = (uint32_t)(_PORTA_RA3_MASK))
#define mToggle_I2C_DATA()          (LATAINV = (uint32_t)(_PORTA_RA3_MASK))

#define mRead_PIC_JTAG_TDI()        (PORTA & (uint32_t)(_PORTA_RA4_MASK))
#define mSet_PIC_JTAG_TDI()         (LATASET = (uint32_t)(_PORTA_RA4_MASK))
#define mClear_PIC_JTAG_TDI()       (LATACLR = (uint32_t)(_PORTA_RA4_MASK))
#define mToggle_PIC_JTAG_TDI()      (LATAINV = (uint32_t)(_PORTA_RA4_MASK))

#define mRead_PIC_JTAG_TDO()        (PORTA & (uint32_t)(_PORTA_RA5_MASK))
#define mSet_PIC_JTAG_TDO()         (LATASET = (uint32_t)(_PORTA_RA5_MASK))
#define mClear_PIC_JTAG_TDO()       (LATACLR = (uint32_t)(_PORTA_RA5_MASK))
#define mToggle_PIC_JTAG_TDO()      (LATAINV = (uint32_t)(_PORTA_RA5_MASK))

#define mRead_NOT_USED_0()          (PORTA & (uint32_t)(_PORTA_RA6_MASK))
#define mSet_NOT_USED_0()           (LATASET = (uint32_t)(_PORTA_RA6_MASK))
#define mClear_NOT_USED_0()         (LATACLR = (uint32_t)(_PORTA_RA6_MASK))
#define mToggle_NOT_USED_0()        (LATAINV = (uint32_t)(_PORTA_RA6_MASK))

#define mRead_NOT_USED_1()          (PORTA & (uint32_t)(_PORTA_RA7_MASK))
#define mSet_NOT_USED_1()           (LATASET = (uint32_t)(_PORTA_RA7_MASK))
#define mClear_NOT_USED_1()         (LATACLR = (uint32_t)(_PORTA_RA7_MASK))
#define mToggle_NOT_USED_1()        (LATAINV = (uint32_t)(_PORTA_RA7_MASK))

#define mRead_PIC_INT_2()           (PORTA & (uint32_t)(_PORTA_RA14_MASK))
#define mSet_PIC_INT_2()            (LATASET = (uint32_t)(_PORTA_RA14_MASK))
#define mClear_PIC_INT_2()          (LATACLR = (uint32_t)(_PORTA_RA14_MASK))
#define mToggle_PIC_INT_2()         (LATAINV = (uint32_t)(_PORTA_RA14_MASK))

#define mRead_NOT_USED_2()          (PORTA & (uint32_t)(_PORTA_RA15_MASK))
#define mSet_NOT_USED_2()           (LATASET = (uint32_t)(_PORTA_RA15_MASK))
#define mClear_NOT_USED_2()         (LATACLR = (uint32_t)(_PORTA_RA15_MASK))
#define mToggle_NOT_USED_2()        (LATAINV = (uint32_t)(_PORTA_RA15_MASK))

// PORTB
#define mRead_PROGRAM_DATA()        (PORTB & (uint32_t)(_PORTB_RB0_MASK))
#define mSet_PROGRAM_DATA()         (LATBSET = (uint32_t)(_PORTB_RB0_MASK))
#define mClear_PROGRAM_DATA()       (LATBCLR = (uint32_t)(_PORTB_RB0_MASK))
#define mToggle_PROGRAM_DATA()      (LABINV = (uint32_t)(_PORTB_RB0_MASK))

#define mRead_PROGRAM_CLK()        (PORTB & (uint32_t)(_PORTB_RB1_MASK))
#define mSet_PROGRAM_CLK()         (LATBSET = (uint32_t)(_PORTB_RB1_MASK))
#define mClear_PROGRAM_CLK()       (LATBCLR = (uint32_t)(_PORTB_RB1_MASK))
#define mToggle_PROGRAM_CLK()      (LABINV = (uint32_t)(_PORTB_RB1_MASK))

// PORTC
#define mRead_XIL_PROM_A_WR_EN()        (PORTC & (uint32_t)(_PORTC_RC1_MASK))
#define mSet_XIL_PROM_A_WR_EN()         (LATCSET = (uint32_t)(_PORTC_RC1_MASK))
#define mClear_XIL_PROM_A_WR_EN()       (LATCCLR = (uint32_t)(_PORTC_RC1_MASK))
#define mToggle_XIL_PROM_A_WR_EN()      (LACINV = (uint32_t)(_PORTC_RC1_MASK))

#define mRead_XIL_PROM_B_WR_EN()        (PORTC & (uint32_t)(_PORTC_RC2_MASK))
#define mSet_XIL_PROM_B_WR_EN()         (LATCSET = (uint32_t)(_PORTC_RC2_MASK))
#define mClear_XIL_PROM_B_WR_EN()       (LATCCLR = (uint32_t)(_PORTC_RC2_MASK))
#define mToggle_XIL_PROM_B_WR_EN()      (LACINV = (uint32_t)(_PORTC_RC2_MASK))

#define mRead_XIL_PROM_B_SEL()          (PORTC & (uint32_t)(_PORTC_RC3_MASK))
#define mSet_XIL_PROM_B_SEL()           (LATCSET = (uint32_t)(_PORTC_RC3_MASK))
#define mClear_XIL_PROM_B_SEL()         (LATCCLR = (uint32_t)(_PORTC_RC3_MASK))
#define mToggle_XIL_PROM_B_SEL()        (LACINV = (uint32_t)(_PORTC_RC3_MASK))

#define mRead_SPI_1_DIN()               (PORTC & (uint32_t)(_PORTC_RC4_MASK))
#define mSet_SPI_1_DIN()                (LATCSET = (uint32_t)(_PORTC_RC4_MASK))
#define mClear_SPI_1_DIN()              (LATCCLR = (uint32_t)(_PORTC_RC4_MASK))
#define mToggle_SPI_1_DIN()             (LACINV = (uint32_t)(_PORTC_RC4_MASK))

#define mRead_XIL_PROG_B()              (PORTC & (uint32_t)(_PORTC_RC13_MASK))
#define mSet_XIL_PROG_B()               (LATCSET = (uint32_t)(_PORTC_RC13_MASK))
#define mClear_XIL_PROG_B()             (LATCCLR = (uint32_t)(_PORTC_RC13_MASK))
#define mToggle_XIL_PROG_B()            (LACINV = (uint32_t)(_PORTC_RC13_MASK))

#define mRead_XIL_DONE()                (PORTC & (uint32_t)(_PORTC_RC14_MASK))
#define mSet_XIL_DONE()                 (LATCSET = (uint32_t)(_PORTC_RC14_MASK))
#define mClear_XIL_DONE()               (LATCCLR = (uint32_t)(_PORTC_RC14_MASK))
#define mToggle_XIL_DONE()              (LACINV = (uint32_t)(_PORTC_RC14_MASK))

//PORTD
#define mRead_SPI_1_DOUT()              (PORTD & (uint32_t)(_PORTD_RD0_MASK))
#define mSet_SPI_1_DOUT()               (LATDSET = (uint32_t)(_PORTD_RD0_MASK))
#define mClear_SPI_1_DOUT()             (LATDCLR = (uint32_t)(_PORTD_RD0_MASK))
#define mToggle_SPI_1_DOUT()            (LATDINV = (uint32_t)(_PORTD_RD0_MASK))

#define mRead_PIC_PSU_CLK()             (PORTD & (uint32_t)(_PORTD_RD1_MASK))
#define mSet_PIC_PSU_CLK()              (LATDSET = (uint32_t)(_PORTD_RD1_MASK))
#define mClear_PIC_PSU_CLK()            (LATDCLR = (uint32_t)(_PORTD_RD1_MASK))
#define mToggle_PIC_PSU_CLK()           (LATDINV = (uint32_t)(_PORTD_RD1_MASK))

#define mRead_PIC_LED()                 (PORTD & (uint32_t)(_PORTD_RD2_MASK))
#define mSet_PIC_LED()                  (LATDSET = (uint32_t)(_PORTD_RD2_MASK))
#define mClear_PIC_LED()                (LATDCLR = (uint32_t)(_PORTD_RD2_MASK))
#define mToggle_PIC_LED()               (LATDINV = (uint32_t)(_PORTD_RD2_MASK))

#define mRead_1_WIRE_DRIVE()            (PORTD & (uint32_t)(_PORTD_RD3_MASK))
#define mSet_1_WIRE_DRIVE()             (LATDSET = (uint32_t)(_PORTD_RD3_MASK))
#define mClear_1_WIRE_DRIVE()           (LATDCLR = (uint32_t)(_PORTD_RD3_MASK))
#define mToggle_1_WIRE_DRIVE()          (LATDINV = (uint32_t)(_PORTD_RD3_MASK))

#define mRead_POWER_LED()               (PORTD & (uint32_t)(_PORTD_RD4_MASK))
#define mSet_POWER_LED()                (LATDSET = (uint32_t)(_PORTD_RD4_MASK))
#define mClear_POWER_LED()              (LATDCLR = (uint32_t)(_PORTD_RD4_MASK))
#define mToggle_POWER_LED()             (LATDINV = (uint32_t)(_PORTD_RD4_MASK))

#define mRead_XIL_INIT_DRIVE_B()        (PORTD & (uint32_t)(_PORTD_RD5_MASK))
#define mSet_XIL_INIT_DRIVE_B()         (LATDSET = (uint32_t)(_PORTD_RD5_MASK))
#define mClear_XIL_INIT_DRIVE_B()       (LATDCLR = (uint32_t)(_PORTD_RD5_MASK))
#define mToggle_XIL_INIT_DRIVE_B()      (LATDINV = (uint32_t)(_PORTD_RD5_MASK))

#define mRead_XIL_INIT_MON_B()          (PORTD & (uint32_t)(_PORTD_RD6_MASK))
#define mSet_XIL_INIT_MON_B()           (LATDSET = (uint32_t)(_PORTD_RD6_MASK))
#define mClear_XIL_INIT_MON_B()         (LATDCLR = (uint32_t)(_PORTD_RD6_MASK))
#define mToggle_XIL_INIT_MON_B()        (LATDINV = (uint32_t)(_PORTD_RD6_MASK))

#define mRead_PIC_XIL_SPI_EN_B()        (PORTD & (uint32_t)(_PORTD_RD7_MASK))
#define mSet_PIC_XIL_SPI_EN_B()         (LATDSET = (uint32_t)(_PORTD_RD7_MASK))
#define mClear_PIC_XIL_SPI_EN_B()       (LATDCLR = (uint32_t)(_PORTD_RD7_MASK))
#define mToggle_PIC_XIL_SPI_EN_B()      (LATDINV = (uint32_t)(_PORTD_RD7_MASK))

#define mRead_PIC_XIL_CFG_EN_B()        (PORTD & (uint32_t)(_PORTD_RD8_MASK))
#define mSet_PIC_XIL_CFG_EN_B()         (LATDSET = (uint32_t)(_PORTD_RD8_MASK))
#define mClear_PIC_XIL_CFG_EN_B()       (LATDCLR = (uint32_t)(_PORTD_RD8_MASK))
#define mToggle_PIC_XIL_CFG_EN_B()      (LATDINV = (uint32_t)(_PORTD_RD8_MASK))

#define mRead_SPI_1_CS_B()              (PORTD & (uint32_t)(_PORTD_RD9_MASK))
#define mSet_SPI_1_CS_B()               (LATDSET = (uint32_t)(_PORTD_RD9_MASK))
#define mClear_SPI_1_CS_B()             (LATDCLR = (uint32_t)(_PORTD_RD9_MASK))
#define mToggle_SPI_1_CS_B()            (LATDINV = (uint32_t)(_PORTD_RD9_MASK))

#define mRead_SPI_1_CLK_B()             (PORTD & (uint32_t)(_PORTD_RD10_MASK))
#define mSet_SPI_1_CLK_B()              (LATDSET = (uint32_t)(_PORTD_RD10_MASK))
#define mClear_SPI_1_CLK_B()            (LATDCLR = (uint32_t)(_PORTD_RD10_MASK))
#define mToggle_SPI_1_CLK_B()           (LATDINV = (uint32_t)(_PORTD_RD10_MASK))

#define mRead_PIC_INPUT_CAPTURE()       (PORTD & (uint32_t)(_PORTD_RD11_MASK))
#define mSet_PIC_INPUT_CAPTURE()        (LATDSET = (uint32_t)(_PORTD_RD11_MASK))
#define mClear_PIC_INPUT_CAPTURE()      (LATDCLR = (uint32_t)(_PORTD_RD11_MASK))
#define mToggle_PIC_INPUT_CAPTURE()     (LATDINV = (uint32_t)(_PORTD_RD11_MASK))

#define mRead_1_WIRE()                  (PORTD & (uint32_t)(_PORTD_RD12_MASK))
#define mSet_1_WIRE()                   (LATDSET = (uint32_t)(_PORTD_RD12_MASK))
#define mClear_1_WIRE()                 (LATDCLR = (uint32_t)(_PORTD_RD12_MASK))
#define mToggle_1_WIRE()                (LATDINV = (uint32_t)(_PORTD_RD12_MASK))

#define mRead_NOT_USED_3()              (PORTD & (uint32_t)(_PORTD_RD13_MASK))
#define mSet_NOT_USED_3()               (LATDSET = (uint32_t)(_PORTD_RD13_MASK))
#define mClear_NOT_USED_3()             (LATDCLR = (uint32_t)(_PORTD_RD13_MASK))
#define mToggle_NOT_USED_3()            (LATDINV = (uint32_t)(_PORTD_RD13_MASK))

#define mRead_UART_1A_CTS()             (PORTD & (uint32_t)(_PORTD_RD14_MASK))
#define mSet_UART_1A_CTS()              (LATDSET = (uint32_t)(_PORTD_RD14_MASK))
#define mClear_UART_1A_CTS()            (LATDCLR = (uint32_t)(_PORTD_RD14_MASK))
#define mToggle_UART_1A_CTS()           (LATDINV = (uint32_t)(_PORTD_RD14_MASK))

#define mRead_UART_1A_RTS()             (PORTD & (uint32_t)(_PORTD_RD15_MASK))
#define mSet_UART_1A_RTS()              (LATDSET = (uint32_t)(_PORTD_RD15_MASK))
#define mClear_UART_1A_RTS()            (LATDCLR = (uint32_t)(_PORTD_RD15_MASK))
#define mToggle_UART_1A_RTS()           (LATDINV = (uint32_t)(_PORTD_RD15_MASK))

// PORTE
#define mRead_SLOT_ID_0()               (PORTE & (uint32_t)(_PORTE_RE0_MASK))
#define mSet_SLOT_ID_0()                (LATESET = (uint32_t)(_PORTE_RE0_MASK))
#define mClear_SLOT_ID_0()              (LATECLR = (uint32_t)(_PORTE_RE0_MASK))
#define mToggle_SLOT_ID_0()             (LATEINV = (uint32_t)(_PORTE_RE0_MASK))

#define mRead_SLOT_ID_1()               (PORTE & (uint32_t)(_PORTE_RE1_MASK))
#define mSet_SLOT_ID_1()                (LATESET = (uint32_t)(_PORTE_RE1_MASK))
#define mClear_SLOT_ID_1()              (LATECLR = (uint32_t)(_PORTE_RE1_MASK))
#define mToggle_SLOT_ID_1()             (LATEINV = (uint32_t)(_PORTE_RE1_MASK))

#define mRead_SLOT_ID_2()               (PORTE & (uint32_t)(_PORTE_RE2_MASK))
#define mSet_SLOT_ID_2()                (LATESET = (uint32_t)(_PORTE_RE2_MASK))
#define mClear_SLOT_ID_2()              (LATECLR = (uint32_t)(_PORTE_RE2_MASK))
#define mToggle_SLOT_ID_2()             (LATEINV = (uint32_t)(_PORTE_RE2_MASK))

#define mRead_MIDPLANE_ID_0()           (PORTE & (uint32_t)(_PORTE_RE3_MASK))
#define mSet_MIDPLANE_ID_0()            (LATESET = (uint32_t)(_PORTE_RE3_MASK))
#define mClear_MIDPLANE_ID_0()          (LATECLR = (uint32_t)(_PORTE_RE3_MASK))
#define mToggle_MIDPLANE_ID_0()         (LATEINV = (uint32_t)(_PORTE_RE3_MASK))

#define mRead_MIDPLANE_ID_1()           (PORTE & (uint32_t)(_PORTE_RE4_MASK))
#define mSet_MIDPLANE_ID_1()            (LATESET = (uint32_t)(_PORTE_RE4_MASK))
#define mClear_MIDPLANE_ID_1()          (LATECLR = (uint32_t)(_PORTE_RE4_MASK))
#define mToggle_MIDPLANE_ID_1()         (LATEINV = (uint32_t)(_PORTE_RE4_MASK))

#define mRead_MIDPLANE_ID_2()           (PORTE & (uint32_t)(_PORTE_RE5_MASK))
#define mSet_MIDPLANE_ID_2()            (LATESET = (uint32_t)(_PORTE_RE5_MASK))
#define mClear_MIDPLANE_ID_2()          (LATECLR = (uint32_t)(_PORTE_RE5_MASK))
#define mToggle_MIDPLANE_ID_2()         (LATEINV = (uint32_t)(_PORTE_RE5_MASK))

#define mRead_PIC_XIL_M0()              (PORTE & (uint32_t)(_PORTE_RE6_MASK))
#define mSet_PIC_XIL_M0()               (LATESET = (uint32_t)(_PORTE_RE6_MASK))
#define mClear_PIC_XIL_M0()             (LATECLR = (uint32_t)(_PORTE_RE6_MASK))
#define mToggle_PIC_XIL_M0()            (LATEINV = (uint32_t)(_PORTE_RE6_MASK))

#define mRead_PIC_XIL_M1()              (PORTE & (uint32_t)(_PORTE_RE7_MASK))
#define mSet_PIC_XIL_M1()               (LATESET = (uint32_t)(_PORTE_RE7_MASK))
#define mClear_PIC_XIL_M1()             (LATECLR = (uint32_t)(_PORTE_RE7_MASK))
#define mToggle_PIC_XIL_M1()            (LATEINV = (uint32_t)(_PORTE_RE7_MASK))

#define mRead_PIC_INT_0()               (PORTE & (uint32_t)(_PORTE_RE8_MASK))
#define mSet_PIC_INT_0()                (LATESET = (uint32_t)(_PORTE_RE8_MASK))
#define mClear_PIC_INT_0()              (LATECLR = (uint32_t)(_PORTE_RE8_MASK))
#define mToggle_PIC_INT_0()             (LATEINV = (uint32_t)(_PORTE_RE8_MASK))

#define mRead_PG_INT_B()                (PORTE & (uint32_t)(_PORTE_RE9_MASK))
#define mSet_PG_INT_B()                 (LATESET = (uint32_t)(_PORTE_RE9_MASK))
#define mClear_PG_INT_B()               (LATECLR = (uint32_t)(_PORTE_RE9_MASK))
#define mToggle_PG_INT_B()              (LATEINV = (uint32_t)(_PORTE_RE9_MASK))

//PORT F
#define mRead_CAN1_RX()                 (PORTF & (uint32_t)(_PORTF_RF0_MASK))
#define mSet_CAN1_RX()                  (LATFSET = (uint32_t)(_PORTF_RF0_MASK))
#define mClear_CAN1_RX()                (LATFCLR = (uint32_t)(_PORTF_RF0_MASK))
#define mToggle_CAN1_RX()               (LATFINV = (uint32_t)(_PORTF_RF0_MASK))

#define mRead_CAN1_TX()                 (PORTF & (uint32_t)(_PORTF_RF1_MASK))
#define mSet_CAN1_TX()                  (LATFSET = (uint32_t)(_PORTF_RF1_MASK))
#define mClear_CAN1_TX()                (LATFCLR = (uint32_t)(_PORTF_RF1_MASK))
#define mToggle_CAN1_TX()               (LATFINV = (uint32_t)(_PORTF_RF1_MASK))

#define mRead_UART_1A_RX()              (PORTF & (uint32_t)(_PORTF_RF2_MASK))
#define mSet_UART_1A_RX()               (LATFSET = (uint32_t)(_PORTF_RF2_MASK))
#define mClear_UART_1A_RX()             (LATFCLR = (uint32_t)(_PORTF_RF2_MASK))
#define mToggle_UART_1A_RX()            (LATFINV = (uint32_t)(_PORTF_RF2_MASK))

#define mRead_NOT_USED_4()              (PORTF & (uint32_t)(_PORTF_RF3_MASK))
#define mSet_NOT_USED_4()               (LATFSET = (uint32_t)(_PORTF_RF3_MASK))
#define mClear_NOT_USED_4()             (LATFCLR = (uint32_t)(_PORTF_RF3_MASK))
#define mToggle_NOT_USED_4()            (LATFINV = (uint32_t)(_PORTF_RF3_MASK))

#define mRead_SPI_3_DIN()               (PORTF & (uint32_t)(_PORTF_RF4_MASK))
#define mSet_SPI_3_DIN()                (LATFSET = (uint32_t)(_PORTF_RF4_MASK))
#define mClear_SPI_3_DIN()              (LATFCLR = (uint32_t)(_PORTF_RF4_MASK))
#define mToggle_SPI_3_DIN()             (LATFINV = (uint32_t)(_PORTF_RF4_MASK))

#define mRead_SPI_3_DOUT()              (PORTF & (uint32_t)(_PORTF_RF5_MASK))
#define mSet_SPI_3_DOUT()               (LATFSET = (uint32_t)(_PORTF_RF5_MASK))
#define mClear_SPI_3_DOUT()             (LATFCLR = (uint32_t)(_PORTF_RF5_MASK))
#define mToggle_SPI_3_DOUT()            (LATFINV = (uint32_t)(_PORTF_RF5_MASK))

#define mRead_UART_1A_TX()              (PORTF & (uint32_t)(_PORTF_RF8_MASK))
#define mSet_UART_1A_TX()               (LATFSET = (uint32_t)(_PORTF_RF8_MASK))
#define mClear_UART_1A_TX()             (LATFCLR = (uint32_t)(_PORTF_RF8_MASK))
#define mToggle_UART_1A_TX()            (LATFINV = (uint32_t)(_PORTF_RF8_MASK))

#define mRead_SPI_3_CS_B()              (PORTF & (uint32_t)(_PORTF_RF12_MASK))
#define mSet_SPI_3_CS_B()               (LATFSET = (uint32_t)(_PORTF_RF12_MASK))
#define mClear_SPI_3_CS_B()             (LATFCLR = (uint32_t)(_PORTF_RF12_MASK))
#define mToggle_SPI_3_CS_B()            (LATFINV = (uint32_t)(_PORTF_RF12_MASK))

#define mRead_SPI_3_CLK()               (PORTF & (uint32_t)(_PORTF_RF13_MASK))
#define mSet_SPI_3_CLK()                (LATFSET = (uint32_t)(_PORTF_RF13_MASK))
#define mClear_SPI_3_CLK()              (LATFCLR = (uint32_t)(_PORTF_RF13_MASK))
#define mToggle_SPI_3_CLK()             (LATFINV = (uint32_t)(_PORTF_RF13_MASK))

// PORTG
#define mRead_CAN_2_RX()                (PORTG & (uint32_t)(_PORTG_RG0_MASK))
#define mSet_CAN_2_RX()                 (LATGSET = (uint32_t)(_PORTG_RG0_MASK))
#define mClear_CAN_2_RX()               (LATGCLR = (uint32_t)(_PORTG_RG0_MASK))
#define mToggle_CAN_2_RX()              (LATGINV = (uint32_t)(_PORTG_RG0_MASK))

#define mRead_CAN_2_TX()                (PORTG & (uint32_t)(_PORTG_RG1_MASK))
#define mSet_CAN_2_TX()                 (LATGSET = (uint32_t)(_PORTG_RG1_MASK))
#define mClear_CAN_2_TX()               (LATGCLR = (uint32_t)(_PORTG_RG1_MASK))
#define mToggle_CAN_2_TX()              (LATGINV = (uint32_t)(_PORTG_RG1_MASK))

#define mRead_PIC_USB_D_P()             (PORTG & (uint32_t)(_PORTG_RG2_MASK))
#define mSet_PIC_USB_D_P()              (LATGSET = (uint32_t)(_PORTG_RG2_MASK))
#define mClear_PIC_USB_D_P()            (LATGCLR = (uint32_t)(_PORTG_RG2_MASK))
#define mToggle_PIC_USB_D_P()           (LATGINV = (uint32_t)(_PORTG_RG2_MASK))

#define mRead_PIC_USB_D_N()             (PORTG & (uint32_t)(_PORTG_RG3_MASK))
#define mSet_PIC_USB_D_N()              (LATGSET = (uint32_t)(_PORTG_RG3_MASK))
#define mClear_PIC_USB_D_N()            (LATGCLR = (uint32_t)(_PORTG_RG3_MASK))
#define mToggle_PIC_USB_D_N()           (LATGINV = (uint32_t)(_PORTG_RG3_MASK))

#define mRead_PIC_INT_1()               (PORTG & (uint32_t)(_PORTG_RG6_MASK))
#define mSet_PIC_INT_1()                (LATGSET = (uint32_t)(_PORTG_RG6_MASK))
#define mClear_PIC_INT_1()              (LATGCLR = (uint32_t)(_PORTG_RG6_MASK))
#define mToggle_PIC_INT_1()             (LATGINV = (uint32_t)(_PORTG_RG6_MASK))

#define mRead_UART_2A_RX()              (PORTG & (uint32_t)(_PORTG_RG7_MASK))
#define mSet_UART_2A_RX()               (LATGSET = (uint32_t)(_PORTG_RG7_MASK))
#define mClear_UART_2A_RX()             (LATGCLR = (uint32_t)(_PORTG_RG7_MASK))
#define mToggle_UART_2A_RX()            (LATGINV = (uint32_t)(_PORTG_RG7_MASK))

#define mRead_UART_2A_TX()              (PORTG & (uint32_t)(_PORTG_RG8_MASK))
#define mSet_UART_2A_TX()               (LATGSET = (uint32_t)(_PORTG_RG8_MASK))
#define mClear_UART_2A_TX()             (LATGCLR = (uint32_t)(_PORTG_RG8_MASK))
#define mToggle_UART_2A_TX()            (LATGINV = (uint32_t)(_PORTG_RG8_MASK))

#define mRead_NOT_USED_5()              (PORTG & (uint32_t)(_PORTG_RG9_MASK))
#define mSet_NOT_USED_5()               (LATGSET = (uint32_t)(_PORTG_RG9_MASK))
#define mClear_NOT_USED_5()             (LATGCLR = (uint32_t)(_PORTG_RG9_MASK))
#define mToggle_NOT_USED_5()            (LATGINV = (uint32_t)(_PORTG_RG9_MASK))

#define mRead_XIL_PSU_ON_B()            (PORTG & (uint32_t)(_PORTG_RG12_MASK))
#define mSet_XIL_PSU_ON_B()             (LATGSET = (uint32_t)(_PORTG_RG12_MASK))
#define mClear_XIL_PSU_ON_B()           (LATGCLR = (uint32_t)(_PORTG_RG12_MASK))
#define mToggle_XIL_PSU_ON_B()          (LATGINV = (uint32_t)(_PORTG_RG12_MASK))

#define mRead_DIG_REQ_ON_B()            (PORTG & (uint32_t)(_PORTG_RG13_MASK))
#define mSet_DIG_REQ_ON_B()             (LATGSET = (uint32_t)(_PORTG_RG13_MASK))
#define mClear_DIG_REQ_ON_B()           (LATGCLR = (uint32_t)(_PORTG_RG13_MASK))
#define mToggle_DIG_REQ_ON_B()          (LATGINV = (uint32_t)(_PORTG_RG13_MASK))

#define mRead_SERVICE_B()               (PORTG & (uint32_t)(_PORTG_RG14_MASK))
#define mSet_SERVICE_B()                (LATGSET = (uint32_t)(_PORTG_RG14_MASK))
#define mClear_SERVICE_B()              (LATGCLR = (uint32_t)(_PORTG_RG14_MASK))
#define mToggle_SERVICE_B()             (LATGINV = (uint32_t)(_PORTG_RG14_MASK))

#define mRead_RST_PERIF_B()             (PORTG & (uint32_t)(_PORTG_RG15_MASK))
#define mSet_1_RST_PERIF_B()            (LATGSET = (uint32_t)(_PORTG_RG15_MASK))
#define mClear_1_RST_PERIF_B()          (LATGCLR = (uint32_t)(_PORTG_RG15_MASK))
#define mToggle_1_RST_PERIF_B()         (LATGINV = (uint32_t)(_PORTG_RG15_MASK))

// ADC CHANNELS             // Index to Object Dictionary
#define V_MEAS_12V          (ADC0_REG)
#define V_MEAS_5V_FILT      (ADC1_REG)
#define V_MEAS_3V3_STBY     (ADC2_REG)
#define V_MEAS_1V2          (ADC3_REG)
#define V_MEAS_2V5          (ADC4_REG)
#define V_MEAS_3V3          (ADC5_REG)
#define V_MEAS_5V           (ADC6_REG)
#define V_MEAS_NEG_5V       (ADC7_REG)
#define V_MEAS_1V5          (ADC8_REG)
#define V_MEAS_VMGT         (ADC9_REG)
#define V_MEAS_VTT          (ADCA_REG)
#define V_MEAS_NEG_3V       (ADCB_REG)
#define V_MEAS_NOT_USED_0   (ADCC_REG)
#define V_MEAS_NOT_USED_1   (ADCD_REG)

//ADC limits
#define ADC_RESOLUTION  2441L // in uVolts
// Nominal = ( ((pullDownR * VoltageInUVolts)/(pullDownR+pullUpR)) / (ADC_RESOLUTION)
// Max = (Nominal) * (1.05) // +5%
// Min = (Nominal) * (0.95) // -5%
 
//V_MEAS_12V
#define V_MEAS_12V_NOMINAL          (((22 * 12000000L)/(22 + 100)) / (ADC_RESOLUTION))
#define V_MEAS_12V_MAX              ((V_MEAS_12V_NOMINAL * 105L) / 100)
#define V_MEAS_12V_MIN              ((V_MEAS_12V_NOMINAL * 95L) / 100)

//V_MEAS_5V_FILT
#define V_MEAS_5V_FILT_NOMINAL      (((22 * 5000000L)/(22 + 27)) / (ADC_RESOLUTION))
#define V_MEAS_5V_FILT_MAX          ((V_MEAS_5V_FILT_NOMINAL * 120L) / 100)
#define V_MEAS_5V_FILT_MIN          ((V_MEAS_5V_FILT_NOMINAL * 80L) / 100)

//V_MEAS_3V3_STBY
#define V_MEAS_3V3_STBY_NOMINAL     (((22 * 3300000L)/(22 + 10)) / (ADC_RESOLUTION))
#define V_MEAS_3V3_STBY_MAX         ((V_MEAS_3V3_STBY_NOMINAL * 105L) / 100)
#define V_MEAS_3V3_STBY_MIN         ((V_MEAS_3V3_STBY_NOMINAL * 95L) / 100)

//V_MEAS_1V2
#define V_MEAS_1V2_NOMINAL          ((1200000L) / (ADC_RESOLUTION))
#define V_MEAS_1V2_MAX              ((V_MEAS_1V2_NOMINAL * 105L) / 100)
#define V_MEAS_1V2_MIN              ((V_MEAS_1V2_NOMINAL * 95L) / 100)

//V_MEAS_2V5
#define V_MEAS_2V5_NOMINAL          (((22 * 2500000L)/(22 + 10)) / (ADC_RESOLUTION))
#define V_MEAS_2V5_MAX              ((V_MEAS_2V5_NOMINAL * 105L) / 100)
#define V_MEAS_2V5_MIN              ((V_MEAS_2V5_NOMINAL * 95L) / 100)

//V_MEAS_3V3
#define V_MEAS_3V3_NOMINAL          (((22 * 3300000L)/(22 + 10)) / (ADC_RESOLUTION))
#define V_MEAS_3V3_MAX              ((V_MEAS_3V3_NOMINAL * 105L) / 100)
#define V_MEAS_3V3_MIN              ((V_MEAS_3V3_NOMINAL * 95L) / 100)

//V_MEAS_5V
#define V_MEAS_5V_NOMINAL           (((22 * 5000000L)/(22 + 27)) / (ADC_RESOLUTION))
#define V_MEAS_5V_MAX               ((V_MEAS_5V_NOMINAL * 105L) / 100)
#define V_MEAS_5V_MIN               ((V_MEAS_5V_NOMINAL * 95L) / 100)

//V_MEAS_NEG_5V
#define V_MEAS_NEG_5V_NOMINAL       ((((22 * 10000000L)/(22 + 10))-5000000) / (ADC_RESOLUTION))
#define V_MEAS_NEG_5V_MAX           ((V_MEAS_NEG_5V_NOMINAL * 110L) / 100)
#define V_MEAS_NEG_5V_MIN           ((V_MEAS_NEG_5V_NOMINAL * 90L) / 100)

//V_MEAS_1V5
#define V_MEAS_1V5_NOMINAL          ((1500000L) / (ADC_RESOLUTION))
#define V_MEAS_1V5_MAX              ((V_MEAS_1V5_NOMINAL * 105L) / 100)
#define V_MEAS_1V5_MIN              ((V_MEAS_1V5_NOMINAL * 95L) / 100)

//V_MEAS_VMGT
#define V_MEAS_VMGT_NOMINAL          ((1200000L) / (ADC_RESOLUTION))
#define V_MEAS_VMGT_MAX              ((V_MEAS_VMGT_NOMINAL * 105L) / 100)
#define V_MEAS_VMGT_MIN              ((V_MEAS_VMGT_NOMINAL * 95L) / 100)

//V_MEAS_VTT
#define V_MEAS_VTT_NOMINAL          ((750000L) / (ADC_RESOLUTION))
#define V_MEAS_VTT_MAX              ((V_MEAS_VTT_NOMINAL * 105L) / 100)
#define V_MEAS_VTT_MIN              ((V_MEAS_VTT_NOMINAL * 95L) / 100)

//V_MEAS_NEG_3V
#define V_MEAS_NEG_3V_NOMINAL       ((((22 * 8000000L)/(22 + 10))-3000000) / (ADC_RESOLUTION))
#define V_MEAS_NEG_3V_MAX           ((V_MEAS_NEG_3V_NOMINAL * 105L) / 100)
#define V_MEAS_NEG_3V_MIN           ((V_MEAS_NEG_3V_NOMINAL * 95L) / 100)

// Timer 1
//#define COUNT_100MS_TICK  31250  // 100ms =  (1/PCLK)*TimerPrescaler*count
#define COUNT_50MS_TICK  15625      // 50ms =  (1/PCLK)*TimerPrescaler*count
//#define ONE_SECOND_100MSEC 10    
#define HALF_SECOND_50MSEC 10

// Timer 3
#define TIMER3_DEBOUNCE_TIME  12500        // 40ms =  (1/PCLK)*TimerPrescaler*count

#define NUMBER_OF_I2C_PORT_EXPANDERS 2

void HWAPI_InitialiseHardware(void);
BOOL HWAPI_IsHalfSecondUp(void);
uint32_t HWAPI_GetMilliSecCount(void);
uint16_t HWAPI_getNodeId(void);
void HWAPI_InitialiseInterfaces(void);
void HWAPI_CheckIfServiceMode(void);

// Re-define General purpose object dictionary registers
#define FPGA_BOOT_FLASH_REG     GP_REG_0
#define FPGA_RESET_REG          GP_REG_1
#define PIC_RESET_REG           GP_REG_F

#endif //HARDWARE_SETUP_H_

