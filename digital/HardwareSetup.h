#ifndef HARDWARE_SETUP_H_
#define HARDWARE_SETUP_H_

#include "global.h"

//PORT A
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

#define mRead_PSU_12V_PG()          (PORTA & (uint32_t)(_PORTA_RA6_MASK))
#define mSet_PSU_12V_PG()           (LATASET = (uint32_t)(_PORTA_RA6_MASK))
#define mClear_PSU_12V_PG()         (LATACLR = (uint32_t)(_PORTA_RA6_MASK))
#define mToggle_PSU_12V_PG()        (LATAINV = (uint32_t)(_PORTA_RA6_MASK))

#define mRead_SERVICE_B()           (PORTA & (uint32_t)(_PORTA_RA7_MASK))
#define mSet_SERVICE_B()            (LATASET = (uint32_t)(_PORTA_RA7_MASK))
#define mClear_SERVICE_B()          (LATACLR = (uint32_t)(_PORTA_RA7_MASK))
#define mToggle_SERVICE_B()         (LATAINV = (uint32_t)(_PORTA_RA7_MASK))

#define mRead_I2C_CLK_PORT_EXP()    (PORTA & (uint32_t)(_PORTA_RA14_MASK))
#define mSet_I2C_CLK_PORT_EXP()     (LATASET = (uint32_t)(_PORTA_RA14_MASK))
#define mClear_I2C_CLK_PORT_EXP()   (LATACLR = (uint32_t)(_PORTA_RA14_MASK))
#define mToggle_I2C_CLK_PORT_EXP()  (LATAINV = (uint32_t)(_PORTA_RA14_MASK))

#define mRead_I2C_DATA_PORT_EXP()   (PORTA & (uint32_t)(_PORTA_RA15_MASK))
#define mSet_I2C_DATA_PORT_EXP()    (LATASET = (uint32_t)(_PORTA_RA15_MASK))
#define mClear_I2C_DATA_PORT_EXP()  (LATACLR = (uint32_t)(_PORTA_RA15_MASK))
#define mToggle_I2C_DATA_PORT_EXP() (LATAINV = (uint32_t)(_PORTA_RA15_MASK))

// PORTB
#define mRead_PROGRAM_DATA()        (PORTB & (uint32_t)(_PORTB_RB0_MASK))
#define mSet_PROGRAM_DATA()         (LATBSET = (uint32_t)(_PORTB_RB0_MASK))
#define mClear_PROGRAM_DATA()       (LATBCLR = (uint32_t)(_PORTB_RB0_MASK))
#define mToggle_PROGRAM_DATA()      (LABINV = (uint32_t)(_PORTB_RB0_MASK))

#define mRead_PROGRAM_CLK()         (PORTB & (uint32_t)(_PORTB_RB1_MASK))
#define mSet_PROGRAM_CLK()          (LATBSET = (uint32_t)(_PORTB_RB1_MASK))
#define mClear_PROGRAM_CLK()        (LATBCLR = (uint32_t)(_PORTB_RB1_MASK))
#define mToggle_PROGRAM_CLK()       (LABINV = (uint32_t)(_PORTB_RB1_MASK))

#define mRead_PIC_PERIF_RST_B()     (PORTB & (uint32_t)(_PORTB_RB7_MASK))
#define mSet_PIC_PERIF_RST_B()      (LATBSET = (uint32_t)(_PORTB_RB7_MASK))
#define mClear_PIC_PERIF_RST_B()    (LATBCLR = (uint32_t)(_PORTB_RB7_MASK))
#define mToggle_PIC_PERIF_RST_B()   (LABINV = (uint32_t)(_PORTB_RB7_MASK))

#define mRead_M2_OVRD()             (PORTB & (uint32_t)(_PORTB_RB8_MASK))
#define mSet_M2_OVRD()              (LATBSET = (uint32_t)(_PORTB_RB8_MASK))
#define mClear_M2_OVRD()            (LATBCLR = (uint32_t)(_PORTB_RB8_MASK))
#define mToggle_M2_OVRD()           (LABINV = (uint32_t)(_PORTB_RB8_MASK))

#define mRead_M1_OVRD()             (PORTB & (uint32_t)(_PORTB_RB9_MASK))
#define mSet_M1_OVRD()              (LATBSET = (uint32_t)(_PORTB_RB9_MASK))
#define mClear_M1_OVRD()            (LATBCLR = (uint32_t)(_PORTB_RB9_MASK))
#define mToggle_M1_OVRD()           (LABINV = (uint32_t)(_PORTB_RB9_MASK))

#define mRead_M0_OVRD()             (PORTB & (uint32_t)(_PORTB_RB10_MASK))
#define mSet_M0_OVRD()              (LATBSET = (uint32_t)(_PORTB_RB10_MASK))
#define mClear_M0_OVRD()            (LATBCLR = (uint32_t)(_PORTB_RB10_MASK))
#define mToggle_M0_OVRD()           (LABINV = (uint32_t)(_PORTB_RB10_MASK))

#define mRead_PIC_INT_2()           (PORTB & (uint32_t)(_PORTB_RB11_MASK))
#define mSet_PIC_INT_2()            (LATBSET = (uint32_t)(_PORTB_RB11_MASK))
#define mClear_PIC_INT_2()          (LATBCLR = (uint32_t)(_PORTB_RB11_MASK))
#define mToggle_PIC_INT_2()         (LABINV = (uint32_t)(_PORTB_RB811_MASK))

#define mRead_PIC_INT_3()           (PORTB & (uint32_t)(_PORTB_RB12_MASK))
#define mSet_PIC_INT_3()            (LATBSET = (uint32_t)(_PORTB_RB12_MASK))
#define mClear_PIC_INT_3()          (LATBCLR = (uint32_t)(_PORTB_RB12_MASK))
#define mToggle_PIC_INT_3()         (LABINV = (uint32_t)(_PORTB_RB812_MASK))

#define mRead_PIC_JTAG_DRIVE_TMS()   (PORTB & (uint32_t)(_PORTB_RB13_MASK))
#define mSet_PIC_JTAG_DRIVE_TMS()    (LATBSET = (uint32_t)(_PORTB_RB13_MASK))
#define mClear_PIC_JTAG_DRIVE_TMS()  (LATBCLR = (uint32_t)(_PORTB_RB13_MASK))
#define mToggle_PIC_JTAG_DRIVE_TMS() (LABINV = (uint32_t)(_PORTB_RB813_MASK))

#define mRead_PIC_JTAG_DRIVE_TCK()   (PORTB & (uint32_t)(_PORTB_RB14_MASK))
#define mSet_PIC_JTAG_DRIVE_TCK()    (LATBSET = (uint32_t)(_PORTB_RB14_MASK))
#define mClear_PIC_JTAG_DRIVE_TCK()  (LATBCLR = (uint32_t)(_PORTB_RB14_MASK))
#define mToggle_PIC_JTAG_DRIVE_TCK() (LABINV = (uint32_t)(_PORTB_RB814_MASK))

#define mRead_PIC_JTAG_DRIVE_TDI()   (PORTB & (uint32_t)(_PORTB_RB15_MASK))
#define mSet_PIC_JTAG_DRIVE_TDI()    (LATBSET = (uint32_t)(_PORTB_RB15_MASK))
#define mClear_PIC_JTAG_DRIVE_TDI()  (LATBCLR = (uint32_t)(_PORTB_RB15_MASK))
#define mToggle_PIC_JTAG_DRIVE_TDI() (LABINV = (uint32_t)(_PORTB_RB815_MASK))

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

#define mRead_PIC_JTAG_DRIVE_TDO()      (PORTD & (uint32_t)(_PORTD_RD13_MASK))
#define mSet_PIC_JTAG_DRIVE_TDO()       (LATDSET = (uint32_t)(_PORTD_RD13_MASK))
#define mClear_PIC_JTAG_DRIVE_TDO()     (LATDCLR = (uint32_t)(_PORTD_RD13_MASK))
#define mToggle_PIC_JTAG_DRIVE_TDO()    (LATDINV = (uint32_t)(_PORTD_RD13_MASK))

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

#define mRead_DIG_12V_ON()              (PORTE & (uint32_t)(_PORTE_RE6_MASK))
#define mSet_DIG_12V_ON()               (LATESET = (uint32_t)(_PORTE_RE6_MASK))
#define mClear_DIG_12V_ON()             (LATECLR = (uint32_t)(_PORTE_RE6_MASK))
#define mToggle_DIG_12V_ON()            (LATEINV = (uint32_t)(_PORTE_RE6_MASK))

#define mRead_DIG_PWR_ON()              (PORTE & (uint32_t)(_PORTE_RE7_MASK))
#define mSet_DIG_PWR_ON()               (LATESET = (uint32_t)(_PORTE_RE7_MASK))
#define mClear_DIG_PWR_ON()             (LATECLR = (uint32_t)(_PORTE_RE7_MASK))
#define mToggle_DIG_PWR_ON()            (LATEINV = (uint32_t)(_PORTE_RE7_MASK))

#define mRead_PIC_INT_1()               (PORTE & (uint32_t)(_PORTE_RE8_MASK))
#define mSet_PIC_INT_1()                (LATESET = (uint32_t)(_PORTE_RE8_MASK))
#define mClear_PIC_INT_1()              (LATECLR = (uint32_t)(_PORTE_RE8_MASK))
#define mToggle_PIC_INT_1()             (LATEINV = (uint32_t)(_PORTE_RE8_MASK))

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

#define mRead_PSU_OK()                  (PORTF & (uint32_t)(_PORTF_RF3_MASK))
#define mSet_PSU_OK()                   (LATFSET = (uint32_t)(_PORTF_RF3_MASK))
#define mClear_PSU_OK()                 (LATFCLR = (uint32_t)(_PORTF_RF3_MASK))
#define mToggle_PSU_OK()                (LATFINV = (uint32_t)(_PORTF_RF3_MASK))

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

#define mRead_EXP_FITTED_B()            (PORTG & (uint32_t)(_PORTG_RG6_MASK))
#define mSet_EXP_FITTED_B()             (LATGSET = (uint32_t)(_PORTG_RG6_MASK))
#define mClear_EXP_FITTED_B()           (LATGCLR = (uint32_t)(_PORTG_RG6_MASK))
#define mToggle_EXP_FITTED_B()          (LATGINV = (uint32_t)(_PORTG_RG6_MASK))

#define mRead_UART_2A_RX()              (PORTG & (uint32_t)(_PORTG_RG7_MASK))
#define mSet_UART_2A_RX()               (LATGSET = (uint32_t)(_PORTG_RG7_MASK))
#define mClear_UART_2A_RX()             (LATGCLR = (uint32_t)(_PORTG_RG7_MASK))
#define mToggle_UART_2A_RX()            (LATGINV = (uint32_t)(_PORTG_RG7_MASK))

#define mRead_UART_2A_TX()              (PORTG & (uint32_t)(_PORTG_RG8_MASK))
#define mSet_UART_2A_TX()               (LATGSET = (uint32_t)(_PORTG_RG8_MASK))
#define mClear_UART_2A_TX()             (LATGCLR = (uint32_t)(_PORTG_RG8_MASK))
#define mToggle_UART_2A_TX()            (LATGINV = (uint32_t)(_PORTG_RG8_MASK))

#define mRead_ADP_DETECT_B()            (PORTG & (uint32_t)(_PORTG_RG9_MASK))
#define mSet_ADP_DETECT_B()             (LATGSET = (uint32_t)(_PORTG_RG9_MASK))
#define mClear_ADP_DETECT_B()           (LATGCLR = (uint32_t)(_PORTG_RG9_MASK))
#define mToggle_ADP_DETECT_B()          (LATGINV = (uint32_t)(_PORTG_RG9_MASK))

#define mRead_DUT_DETECT_B()            (PORTG & (uint32_t)(_PORTG_RG12_MASK))
#define mSet_DUT_DETECT_B()             (LATGSET = (uint32_t)(_PORTG_RG12_MASK))
#define mClear_DUT_DETECT_B()           (LATGCLR = (uint32_t)(_PORTG_RG12_MASK))
#define mToggle_DUT_DETECT_B()          (LATGINV = (uint32_t)(_PORTG_RG12_MASK))

#define mRead_PIC_ANA_MUX_A()           (PORTG & (uint32_t)(_PORTG_RG13_MASK))
#define mSet_PIC_ANA_MUX_A()            (LATGSET = (uint32_t)(_PORTG_RG13_MASK))
#define mClear_PIC_ANA_MUX_A()          (LATGCLR = (uint32_t)(_PORTG_RG13_MASK))
#define mToggle_PIC_ANA_MUX_A()         (LATGINV = (uint32_t)(_PORTG_RG13_MASK))

#define mRead_PIC_ANA_MUX_B()           (PORTG & (uint32_t)(_PORTG_RG14_MASK))
#define mSet_PIC_ANA_MUX_B()            (LATGSET = (uint32_t)(_PORTG_RG14_MASK))
#define mClear_PIC_ANA_MUX_B()          (LATGCLR = (uint32_t)(_PORTG_RG14_MASK))
#define mToggle_PIC_ANA_MUX_B()         (LATGINV = (uint32_t)(_PORTG_RG14_MASK))

#define mRead_PIC_ANA_MUX_C()           (PORTG & (uint32_t)(_PORTG_RG15_MASK))
#define mSet_PIC_ANA_MUX_C()            (LATGSET = (uint32_t)(_PORTG_RG15_MASK))
#define mClear_PIC_ANA_MUX_C()          (LATGCLR = (uint32_t)(_PORTG_RG15_MASK))
#define mToggle_PIC_ANA_MUX_C()         (LATGINV = (uint32_t)(_PORTG_RG15_MASK))

//ADC CHANNELS              //Index to Object Dictionary
#define ATOD_3V3_STBY       (ADC0_REG)
#define DUT_3V3_I_MON       (ADC1_REG)
#define V_MEAS_12V          (ADC2_REG)       
#define PCI_VCC_MON         (ADC0_MUX_REG)
#define PCI_PLL_MON         (ADC1_MUX_REG)
#define PCI_TX_MON          (ADC2_MUX_REG)
#define PCI_RX_MON          (ADC3_MUX_REG)
#define AUR_VCC_MON         (ADC4_MUX_REG)
#define AUR_PLL_MON         (ADC5_MUX_REG)
#define AUR_TX_MON          (ADC6_MUX_REG)
#define AUR_RX_MON          (ADC7_MUX_REG)
#define V_MEAS_NEG_5V       (ADC8_MUX_REG)
#define V_MEAS_5V           (ADC9_MUX_REG)
#define V_MEAS_3V3          (ADCA_MUX_REG)
#define V_MEAS_2V5          (ADCB_MUX_REG)
#define V_MEAS_GROUND       (ADCC_MUX_REG)
#define V_MEAS_1V           (ADCD_MUX_REG)
#define PSU_12V_I_MON       (ADCE_MUX_REG)
#define DUT_12V_I_MON       (ADCF_MUX_REG)

//ADC limits
#define ADC_RESOLUTION  2441L // in uVolts
// Nominal = ( ((pullDownR * VoltageInUVolts)/(pullDownR+pullUpR)) / (ADC_RESOLUTION)
// Max = (Nominal) * (1.05) // +5%
// Min = (Nominal) * (0.95) // -5%

//ATOD_3V3_STBY
#define ATOD_3V3_STBY_NOMINAL   (((22 * 3300000L)/(22 + 10)) / (ADC_RESOLUTION))
#define ATOD_3V3_STBY_MAX       ((ATOD_3V3_STBY_NOMINAL * 105L) / 100)
#define ATOD_3V3_STBY_MIN       ((ATOD_3V3_STBY_NOMINAL * 95L) / 100)

//DUT_3V3_I_MON 
#define DUT_3V3_I_MON_NOMINAL  ((2400000L) / (ADC_RESOLUTION))
#define DUT_3V3_I_MON_MAX      ((DUT_3V3_I_MON_NOMINAL * 105L) / 100)
#define DUT_3V3_I_MON_MIN      0 //((DUT_3V3_I_MON_NOMINAL * 95L) / 100)

//V_MEAS_12V
#define V_MEAS_12V_NOMINAL          (((10 * 12000000L)/(10 + 43)) / (ADC_RESOLUTION))
#define V_MEAS_12V_MAX              ((V_MEAS_12V_NOMINAL * 110L) / 100)
#define V_MEAS_12V_MIN              ((V_MEAS_12V_NOMINAL * 90L) / 100)

//PCI_VCC_MON
#define PCI_VCC_MON_NOMINAL          ((1000000L) / (ADC_RESOLUTION))
#define PCI_VCC_MON_MAX              ((PCI_VCC_MON_NOMINAL * 105L) / 100)
#define PCI_VCC_MON_MIN              ((PCI_VCC_MON_NOMINAL * 95L) / 100)

//PCI_PLL_MON
#define PCI_PLL_MON_NOMINAL          ((1200000L) / (ADC_RESOLUTION))
#define PCI_PLL_MON_MAX              ((PCI_PLL_MON_NOMINAL * 105L) / 100)
#define PCI_PLL_MON_MIN              ((PCI_PLL_MON_NOMINAL * 95L) / 100)

//PCI_TX_MON
#define PCI_TX_MON_NOMINAL          ((1200000L) / (ADC_RESOLUTION))
#define PCI_TX_MON_MAX              ((PCI_TX_MON_NOMINAL * 105L) / 100)
#define PCI_TX_MON_MIN              ((PCI_TX_MON_NOMINAL * 95L) / 100)

//PCI_RX_MON
#define PCI_RX_MON_NOMINAL          ((1200000L) / (ADC_RESOLUTION))
#define PCI_RX_MON_MAX              ((PCI_RX_MON_NOMINAL * 105L) / 100)
#define PCI_RX_MON_MIN              ((PCI_RX_MON_NOMINAL * 95L) / 100)

//AUR_VCC_MON
#define AUR_VCC_MON_NOMINAL          ((1000000L) / (ADC_RESOLUTION))
#define AUR_VCC_MON_MAX              ((AUR_VCC_MON_NOMINAL * 105L) / 100)
#define AUR_VCC_MON_MIN              ((AUR_VCC_MON_NOMINAL * 95L) / 100)

//AUR_PLL_MON
#define AUR_PLL_MON_NOMINAL          ((1200000L) / (ADC_RESOLUTION))
#define AUR_PLL_MON_MAX              ((AUR_PLL_MON_NOMINAL * 105L) / 100)
#define AUR_PLL_MON_MIN              ((AUR_PLL_MON_NOMINAL * 95L) / 100)

//AUR_TX_MON
#define AUR_TX_MON_NOMINAL          ((1200000L) / (ADC_RESOLUTION))
#define AUR_TX_MON_MAX              ((AUR_TX_MON_NOMINAL * 105L) / 100)
#define AUR_TX_MON_MIN              ((AUR_TX_MON_NOMINAL * 95L) / 100)

//AUR_RX_MON
#define AUR_RX_MON_NOMINAL          ((1200000L) / (ADC_RESOLUTION))
#define AUR_RX_MON_MAX              ((AUR_RX_MON_NOMINAL * 105L) / 100)
#define AUR_RX_MON_MIN              ((AUR_RX_MON_NOMINAL * 95L) / 100)

//V_MEAS_NEG_5V
#define V_MEAS_NEG_5V_NOMINAL       ((((100 * 10000000L)/(100 + 30))-5000000) / (ADC_RESOLUTION))
#define V_MEAS_NEG_5V_MAX           ((V_MEAS_NEG_5V_NOMINAL * 110L) / 100)
#define V_MEAS_NEG_5V_MIN           ((V_MEAS_NEG_5V_NOMINAL * 90L) / 100)

//V_MEAS_5V
#define V_MEAS_5V_NOMINAL           (((10 * 5000000L)/(10 + 12)) / (ADC_RESOLUTION))
#define V_MEAS_5V_MAX               ((V_MEAS_5V_NOMINAL * 105L) / 100)
#define V_MEAS_5V_MIN               ((V_MEAS_5V_NOMINAL * 95L) / 100)

//V_MEAS_3V3
#define V_MEAS_3V3_NOMINAL          (((100 * 3300000L)/(100 + 47)) / (ADC_RESOLUTION))
#define V_MEAS_3V3_MAX              ((V_MEAS_3V3_NOMINAL * 105L) / 100)
#define V_MEAS_3V3_MIN              ((V_MEAS_3V3_NOMINAL * 95L) / 100)

//V_MEAS_2V5
#define V_MEAS_2V5_NOMINAL          (((100 * 2500000L)/(100 + 15)) / (ADC_RESOLUTION))
#define V_MEAS_2V5_MAX              ((V_MEAS_2V5_NOMINAL * 105L) / 100)
#define V_MEAS_2V5_MIN              ((V_MEAS_2V5_NOMINAL * 95L) / 100)

//V_MEAS_GROUND
#define V_MEAS_GROUND_NOMINAL       (((22 * 2500000L)/(22 + 10)) / (ADC_RESOLUTION))
#define V_MEAS_GROUND_MAX          100 //((V_MEAS_GROUND_NOMINAL * 105L) / 100)
#define V_MEAS_GROUND_MIN           0 //((V_MEAS_GROUND_NOMINAL * 95L) / 100)

//V_MEAS_1V
#define V_MEAS_1V_NOMINAL          ((1000000L) / (ADC_RESOLUTION))
#define V_MEAS_1V_MAX              ((V_MEAS_1V_NOMINAL * 105L) / 100)
#define V_MEAS_1V_MIN              ((V_MEAS_1V_NOMINAL * 95L) / 100)

//PSU_12V_I_MON 
#define PSU_12V_I_MON_NOMINAL       ((2400000L) / (ADC_RESOLUTION))
#define PSU_12V_I_MON_MAX           ((PSU_12V_I_MON_NOMINAL * 105L) / 100)
#define PSU_12V_I_MON_MIN           0 //((PSU_12V_I_MON_NOMINAL * 95L) / 100)

//DUT_12V_I_MON 
#define DUT_12V_I_MON_NOMINAL       ((2400000L) / (ADC_RESOLUTION))
#define DUT_12V_I_MON_MAX           ((DUT_12V_I_MON_NOMINAL * 105L) / 100)
#define DUT_12V_I_MON_MIN           0 //((DUT_12V_I_MON_NOMINAL * 95L) / 100)

// Timer 1
//#define COUNT_100MS_TICK  31250  // 100ms =  (1/PCLK)*TimerPrescaler*count
#define COUNT_50MS_TICK  15625      // 50ms =  (1/PCLK)*TimerPrescaler*count
//#define ONE_SECOND_100MSEC 10    
#define HALF_SECOND_50MSEC 10

#define NUMBER_OF_I2C_PORT_EXPANDERS 1

void HWAPI_InitialiseHardware(void);
BOOL HWAPI_IsHalfSecondUp(void);
uint32_t HWAPI_GetMilliSecCount(void);
uint16_t HWAPI_getNodeId(void);
void HWAPI_InitialiseInterfaces();
uint16_t HWAPI_getSlotId(void);
void HWAPI_CheckIfServiceMode(void);

#endif //HARDWARE_SETUP_H_

