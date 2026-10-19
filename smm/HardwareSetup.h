#ifndef HARDWARE_SETUP_H
#define HARDWARE_SETUP_H

#include "global.h"

//PORT A
#define mRead_NOT_USED_0()              (PORTA & (uint32_t)(_PORTA_RA0_MASK))
#define mSet_NOT_USED_0()               (LATASET = (uint32_t)(_PORTA_RA0_MASK))
#define mClear_NOT_USED_0()             (LATACLR = (uint32_t)(_PORTA_RA0_MASK))
#define mToggle_NOT_USED_0()            (LATAINV = (uint32_t)(_PORTA_RA0_MASK))

#define mRead_TP302()                   (PORTA & (uint32_t)(_PORTA_RA1_MASK))
#define mSet_TP302()                    (LATASET = (uint32_t)(_PORTA_RA1_MASK))
#define mClear_TP302()                  (LATACLR = (uint32_t)(_PORTA_RA1_MASK))
#define mToggle_TP302()                 (LATAINV = (uint32_t)(_PORTA_RA1_MASK))

#define mRead_I2C_2_CLK()               (PORTA & (uint32_t)(_PORTA_RA2_MASK))
#define mSet_I2C_2_CLK()                (LATASET = (uint32_t)(_PORTA_RA2_MASK))
#define mClear_I2C_2_CLK()              (LATACLR = (uint32_t)(_PORTA_RA2_MASK))
#define mToggle_I2C_2_CLK()             (LATAINV = (uint32_t)(_PORTA_RA2_MASK))

#define mRead_I2C_2_DATA()              (PORTA & (uint32_t)(_PORTA_RA3_MASK))
#define mSet_I2C_2_DATA()               (LATASET = (uint32_t)(_PORTA_RA3_MASK))
#define mClear_I2C_2_DATA()             (LATACLR = (uint32_t)(_PORTA_RA3_MASK))
#define mToggle_I2C_2_DATA()            (LATAINV = (uint32_t)(_PORTA_RA3_MASK))

#define mRead_TP303()                   (PORTA & (uint32_t)(_PORTA_RA4_MASK))
#define mSet_TP303()                    (LATASET = (uint32_t)(_PORTA_RA4_MASK))
#define mClear_TP303()                  (LATACLR = (uint32_t)(_PORTA_RA4_MASK))
#define mToggle_TP303()                 (LATAINV = (uint32_t)(_PORTA_RA4_MASK))

#define mRead_TP304()                   (PORTA & (uint32_t)(_PORTA_RA5_MASK))
#define mSet_TP304()                    (LATASET = (uint32_t)(_PORTA_RA5_MASK))
#define mClear_TP304()                  (LATACLR = (uint32_t)(_PORTA_RA5_MASK))
#define mToggle_TP304()                 (LATAINV = (uint32_t)(_PORTA_RA5_MASK))

#define mRead_TP305()                   (PORTA & (uint32_t)(_PORTA_RA6_MASK))
#define mSet_TP305()                    (LATASET = (uint32_t)(_PORTA_RA6_MASK))
#define mClear_TP305()                  (LATACLR = (uint32_t)(_PORTA_RA6_MASK))
#define mToggle_TP305()                 (LATAINV = (uint32_t)(_PORTA_RA6_MASK))

#define mRead_TP306()                   (PORTA & (uint32_t)(_PORTA_RA7_MASK))
#define mSet_TP306()                    (LATASET = (uint32_t)(_PORTA_RA7_MASK))
#define mClear_TP306()                  (LATACLR = (uint32_t)(_PORTA_RA7_MASK))
#define mToggle_TP306()                 (LATAINV = (uint32_t)(_PORTA_RA7_MASK))

#define mRead_I2C_1_CLK()               (PORTA & (uint32_t)(_PORTA_RA14_MASK))
#define mSet_I2C_1_CLK()                (LATASET = (uint32_t)(_PORTA_RA14_MASK))
#define mClear_I2C_1_CLK()              (LATACLR = (uint32_t)(_PORTA_RA14_MASK))
#define mToggle_I2C_1_CLK()             (LATAINV = (uint32_t)(_PORTA_RA14_MASK))

#define mRead_I2C_1_DATA()              (PORTA & (uint32_t)(_PORTA_RA15_MASK))
#define mSet_I2C_1_DATA()               (LATASET = (uint32_t)(_PORTA_RA15_MASK))
#define mClear_I2C_1_DATA()             (LATACLR = (uint32_t)(_PORTA_RA15_MASK))
#define mToggle_I2C_1_DATA()            (LATAINV = (uint32_t)(_PORTA_RA15_MASK))

// PORTB
#define mRead_PROGRAM_DATA()            (PORTB & (uint32_t)(_PORTB_RB0_MASK))
#define mSet_PROGRAM_DATA()             (LATBSET = (uint32_t)(_PORTB_RB0_MASK))
#define mClear_PROGRAM_DATA()           (LATBCLR = (uint32_t)(_PORTB_RB0_MASK))
#define mToggle_PROGRAM_DATA()          (LABINV = (uint32_t)(_PORTB_RB0_MASK))

#define mRead_PROGRAM_CLK()             (PORTB & (uint32_t)(_PORTB_RB1_MASK))
#define mSet_PROGRAM_CLK()              (LATBSET = (uint32_t)(_PORTB_RB1_MASK))
#define mClear_PROGRAM_CLK()            (LATBCLR = (uint32_t)(_PORTB_RB1_MASK))
#define mToggle_PROGRAM_CLK()           (LABINV = (uint32_t)(_PORTB_RB1_MASK))

#define mRead_NOT_USED_1()              (PORTB & (uint32_t)(_PORTB_RB7_MASK))
#define mSet_NOT_USED_1()               (LATBSET = (uint32_t)(_PORTB_RB7_MASK))
#define mClear_NOT_USED_1()             (LATBCLR = (uint32_t)(_PORTB_RB7_MASK))
#define mToggle_NOT_USED_1()            (LATBINV = (uint32_t)(_PORTB_RB7_MASK))

#define mRead_NOT_USED_2()              (PORTB & (uint32_t)(_PORTB_RB8_MASK))
#define mSet_NOT_USED_2()               (LATBSET = (uint32_t)(_PORTB_RB8_MASK))
#define mClear_NOT_USED_2()             (LATBCLR = (uint32_t)(_PORTB_RB8_MASK))
#define mToggle_NOT_USED_2()            (LATBINV = (uint32_t)(_PORTB_RB8_MASK))

#define mRead_NOT_USED_3()              (PORTB & (uint32_t)(_PORTB_RB9_MASK))
#define mSet_NOT_USED_3()               (LATBSET = (uint32_t)(_PORTB_RB9_MASK))
#define mClear_NOT_USED_3()             (LATBCLR = (uint32_t)(_PORTB_RB9_MASK))
#define mToggle_NOT_USED_3()            (LATBINV = (uint32_t)(_PORTB_RB9_MASK))

#define mRead_NOT_USED_4()              (PORTB & (uint32_t)(_PORTB_RB10_MASK))
#define mSet_NOT_USED_4()               (LATBSET = (uint32_t)(_PORTB_RB10_MASK))
#define mClear_NOT_USED_4()             (LATBCLR = (uint32_t)(_PORTB_RB10_MASK))
#define mToggle_NOT_USED_4()            (LATBINV = (uint32_t)(_PORTB_RB10_MASK))

#define mRead_NOT_USED_5()              (PORTB & (uint32_t)(_PORTB_RB11_MASK))
#define mSet_NOT_USED_5()               (LATBSET = (uint32_t)(_PORTB_RB11_MASK))
#define mClear_NOT_USED_5()             (LATBCLR = (uint32_t)(_PORTB_RB11_MASK))
#define mToggle_NOT_USED_5()            (LATBINV = (uint32_t)(_PORTB_RB11_MASK))

#define mRead_NOT_USED_6()              (PORTB & (uint32_t)(_PORTB_RB12_MASK))
#define mSet_NOT_USED_6()               (LATBSET = (uint32_t)(_PORTB_RB12_MASK))
#define mClear_NOT_USED_6()             (LATBCLR = (uint32_t)(_PORTB_RB12_MASK))
#define mToggle_NOT_USED_6()            (LATBINV = (uint32_t)(_PORTB_RB12_MASK))

#define mRead_NOT_USED_7()              (PORTB & (uint32_t)(_PORTB_RB13_MASK))
#define mSet_NOT_USED_7()               (LATBSET = (uint32_t)(_PORTB_RB13_MASK))
#define mClear_NOT_USED_7()             (LATBCLR = (uint32_t)(_PORTB_RB13_MASK))
#define mToggle_NOT_USED_7()            (LATBINV = (uint32_t)(_PORTB_RB13_MASK))

#define mRead_NOT_USED_8()              (PORTB & (uint32_t)(_PORTB_RB14_MASK))
#define mSet_NOT_USED_8()               (LATBSET = (uint32_t)(_PORTB_RB14_MASK))
#define mClear_NOT_USED_8()             (LATBCLR = (uint32_t)(_PORTB_RB14_MASK))
#define mToggle_NOT_USED_8()            (LATBINV = (uint32_t)(_PORTB_RB14_MASK))

#define mRead_NOT_USED_9()              (PORTB & (uint32_t)(_PORTB_RB15_MASK))
#define mSet_NOT_USED_9()               (LATBSET = (uint32_t)(_PORTB_RB15_MASK))
#define mClear_NOT_USED_9()             (LATBCLR = (uint32_t)(_PORTB_RB15_MASK))
#define mToggle_NOT_USED_9()            (LATBINV = (uint32_t)(_PORTB_RB15_MASK))

// PORTC
#define mRead_DIGI_RESET()              (PORTC & (uint32_t)(_PORTC_RC1_MASK))
#define mSet_DIGI_RESET()               (LATCSET = (uint32_t)(_PORTC_RC1_MASK))
#define mClear_DIGI_RESET()             (LATCCLR = (uint32_t)(_PORTC_RC1_MASK))
#define mToggle_DIGI_RESET()            (LACINV = (uint32_t)(_PORTC_RC1_MASK))

#define mRead_DIGI_INIT_B()             (PORTC & (uint32_t)(_PORTC_RC2_MASK))
#define mSet_DIGI_INIT_B()              (LATCSET = (uint32_t)(_PORTC_RC2_MASK))
#define mClear_DIGI_INIT_B()            (LATCCLR = (uint32_t)(_PORTC_RC2_MASK))
#define mToggle_DIGI_INIT_B()           (LACINV = (uint32_t)(_PORTC_RC2_MASK))

#define mRead_NOT_USED_10()             (PORTC & (uint32_t)(_PORTC_RC3_MASK))
#define mSet_NOT_USED_10()              (LATCSET = (uint32_t)(_PORTC_RC3_MASK))
#define mClear_NOT_USED_10()            (LATCCLR = (uint32_t)(_PORTC_RC3_MASK))
#define mToggle_NOT_USED_10()           (LACINV = (uint32_t)(_PORTC_RC3_MASK))

#define mRead_PROM_DATA_OUT()           (PORTC & (uint32_t)(_PORTC_RC4_MASK))
#define mSet_PROM_DATA_OUT()            (LATCSET = (uint32_t)(_PORTC_RC4_MASK))
#define mClear_PROM_DATA_OUT()          (LATCCLR = (uint32_t)(_PORTC_RC4_MASK))
#define mToggle_PROM_DATA_OUT()         (LACINV = (uint32_t)(_PORTC_RC4_MASK))

#define mRead_NOT_USED_11()             (PORTC & (uint32_t)(_PORTC_RC13_MASK))
#define mSet_NOT_USED_11()              (LATCSET = (uint32_t)(_PORTC_RC13_MASK))
#define mClear_NOT_USED_11()            (LATCCLR = (uint32_t)(_PORTC_RC13_MASK))
#define mToggle_NOT_USED_11()           (LACINV = (uint32_t)(_PORTC_RC13_MASK))

#define mRead_NOT_USED_12()             (PORTC & (uint32_t)(_PORTC_RC14_MASK))
#define mSet_NOT_USED_12()              (LATCSET = (uint32_t)(_PORTC_RC14_MASK))
#define mClear_NOT_USED_12()            (LATCCLR = (uint32_t)(_PORTC_RC14_MASK))
#define mToggle_NOT_USED_12()           (LACINV = (uint32_t)(_PORTC_RC14_MASK))

#define mRead_NOT_USED_13()             (PORTC & (uint32_t)(_PORTC_RC15_MASK))
#define mSet_NOT_USED_13()              (LATCSET = (uint32_t)(_PORTC_RC15_MASK))
#define mClear_NOT_USED_13()            (LATCCLR = (uint32_t)(_PORTC_RC15_MASK))
#define mToggle_NOT_USED_13()           (LACINV = (uint32_t)(_PORTC_RC15_MASK))

//PORTD
#define mRead_PROM_DATA_IN()            (PORTD & (uint32_t)(_PORTD_RD0_MASK))
#define mSet_PROM_DATA_IN()             (LATDSET = (uint32_t)(_PORTD_RD0_MASK))
#define mClear_PROM_DATA_IN()           (LATDCLR = (uint32_t)(_PORTD_RD0_MASK))
#define mToggle_PROM_DATA_IN()          (LATDINV = (uint32_t)(_PORTD_RD0_MASK))

#define mRead_NOT_USED_14()             (PORTD & (uint32_t)(_PORTD_RD1_MASK))
#define mSet_NOT_USED_14()              (LATDSET = (uint32_t)(_PORTD_RD1_MASK))
#define mClear_NOT_USED_14()            (LATDCLR = (uint32_t)(_PORTD_RD1_MASK))
#define mToggle_NOT_USED_14()           (LATDINV = (uint32_t)(_PORTD_RD1_MASK))

#define mRead_PROM_MUX_ENABLE()         (PORTD & (uint32_t)(_PORTD_RD2_MASK))
#define mSet_PROM_MUX_ENABLE()          (LATDSET = (uint32_t)(_PORTD_RD2_MASK))
#define mClear_PROM_MUX_ENABLE()        (LATDCLR = (uint32_t)(_PORTD_RD2_MASK))
#define mToggle_PROM_MUX_ENABLE()       (LATDINV = (uint32_t)(_PORTD_RD2_MASK))

#define mRead_PIC_LED()                 (PORTD & (uint32_t)(_PORTD_RD3_MASK))
#define mSet_PIC_LED()                  (LATDSET = (uint32_t)(_PORTD_RD3_MASK))
#define mClear_PIC_LED()                (LATDCLR = (uint32_t)(_PORTD_RD3_MASK))
#define mToggle_PIC_LED()               (LATDINV = (uint32_t)(_PORTD_RD3_MASK))

#define mRead_POWER_LED()               (PORTD & (uint32_t)(_PORTD_RD4_MASK))
#define mSet_POWER_LED()                (LATDSET = (uint32_t)(_PORTD_RD4_MASK))
#define mClear_POWER_LED()              (LATDCLR = (uint32_t)(_PORTD_RD4_MASK))
#define mToggle_POWER_LED()             (LATDINV = (uint32_t)(_PORTD_RD4_MASK))

#define mRead_SLFAN_ALT2()              (PORTD & (uint32_t)(_PORTD_RD5_MASK))
#define mSet_SLFAN_ALT2()               (LATDSET = (uint32_t)(_PORTD_RD5_MASK))
#define mClear_SLFAN_ALT2()             (LATDCLR = (uint32_t)(_PORTD_RD5_MASK))
#define mToggle_SLFAN_ALT2()            (LATDINV = (uint32_t)(_PORTD_RD5_MASK))

#define mRead_SLFAN_ALT3()              (PORTD & (uint32_t)(_PORTD_RD6_MASK))
#define mSet_SLFAN_ALT3()               (LATDSET = (uint32_t)(_PORTD_RD6_MASK))
#define mClear_SLFAN_ALT3()             (LATDCLR = (uint32_t)(_PORTD_RD6_MASK))
#define mToggle_SLFAN_ALT3()            (LATDINV = (uint32_t)(_PORTD_RD6_MASK))

#define mRead_SLFAN_ALT4()              (PORTD & (uint32_t)(_PORTD_RD7_MASK))
#define mSet_SLFAN_ALT4()               (LATDSET = (uint32_t)(_PORTD_RD7_MASK))
#define mClear_SLFAN_ALT4()             (LATDCLR = (uint32_t)(_PORTD_RD7_MASK))
#define mToggle_SLFAN_ALT4()            (LATDINV = (uint32_t)(_PORTD_RD7_MASK))

#define mRead_PROM_SEL_B()              (PORTD & (uint32_t)(_PORTD_RD8_MASK))
#define mSet_PROM_SEL_B()               (LATDSET = (uint32_t)(_PORTD_RD8_MASK))
#define mClear_PROM_SEL_B()             (LATDCLR = (uint32_t)(_PORTD_RD8_MASK))
#define mToggle_PROM_SEL_B()            (LATDINV = (uint32_t)(_PORTD_RD8_MASK))

#define mRead_PROM_CSB()                (PORTD & (uint32_t)(_PORTD_RD9_MASK))
#define mSet_PROM_CSB()                 (LATDSET = (uint32_t)(_PORTD_RD9_MASK))
#define mClear_PROM_CSB()               (LATDCLR = (uint32_t)(_PORTD_RD9_MASK))
#define mToggle_PROM_CSB()              (LATDINV = (uint32_t)(_PORTD_RD9_MASK))

#define mRead_PROM_CLK()                (PORTD & (uint32_t)(_PORTD_RD10_MASK))
#define mSet_PROM_CLK()                 (LATDSET = (uint32_t)(_PORTD_RD10_MASK))
#define mClear_PROM_CLK()               (LATDCLR = (uint32_t)(_PORTD_RD10_MASK))
#define mToggle_PROM_CLK()              (LATDINV = (uint32_t)(_PORTD_RD10_MASK))

#define mRead_PROM_SEL_A()              (PORTD & (uint32_t)(_PORTD_RD11_MASK))
#define mSet_PROM_SEL_A()               (LATDSET = (uint32_t)(_PORTD_RD11_MASK))
#define mClear_PROM_SEL_A()             (LATDCLR = (uint32_t)(_PORTD_RD11_MASK))
#define mToggle_PROM_SEL_A()            (LATDINV = (uint32_t)(_PORTD_RD11_MASK))

#define mRead_1_WIRE()                  (PORTD & (uint32_t)(_PORTD_RD12_MASK))
#define mSet_1_WIRE()                   (LATDSET = (uint32_t)(_PORTD_RD12_MASK))
#define mClear_1_WIRE()                 (LATDCLR = (uint32_t)(_PORTD_RD12_MASK))
#define mToggle_1_WIRE()                (LATDINV = (uint32_t)(_PORTD_RD12_MASK))

#define mRead_SLFAN_ALT1()              (PORTD & (uint32_t)(_PORTD_RD13_MASK))
#define mSet_SLFAN_ALT1()               (LATDSET = (uint32_t)(_PORTD_RD13_MASK))
#define mClear_SLFAN_ALT1()             (LATDCLR = (uint32_t)(_PORTD_RD13_MASK))
#define mToggle_SLFAN_ALT1()            (LATDINV = (uint32_t)(_PORTD_RD13_MASK))

#define mRead_HWDET_ALT()               (PORTD & (uint32_t)(_PORTD_RD14_MASK))
#define mSet_HWDET_ALT()                (LATDSET = (uint32_t)(_PORTD_RD14_MASK))
#define mClear_HWDET_ALT()              (LATDCLR = (uint32_t)(_PORTD_RD14_MASK))
#define mToggle_HWDET_ALT()             (LATDINV = (uint32_t)(_PORTD_RD14_MASK))

#define mRead_DUTFAN_ALT()              (PORTD & (uint32_t)(_PORTD_RD15_MASK))
#define mSet_DUTFAN_ALT()               (LATDSET = (uint32_t)(_PORTD_RD15_MASK))
#define mClear_DUTFAN_ALT()             (LATDCLR = (uint32_t)(_PORTD_RD15_MASK))
#define mToggle_DUTFAN_ALT()            (LATDINV = (uint32_t)(_PORTD_RD15_MASK))

// PORTE
#define mRead_PIC_SMMIO_0()             (PORTE & (uint32_t)(_PORTE_RE0_MASK))
#define mSet_PIC_SMMIO_0()              (LATESET = (uint32_t)(_PORTE_RE0_MASK))
#define mClear_PIC_SMMIO_0()            (LATECLR = (uint32_t)(_PORTE_RE0_MASK))
#define mToggle_PIC_SMMIO_0()           (LATEINV = (uint32_t)(_PORTE_RE0_MASK))

#define mRead_PIC_SMMIO_1()             (PORTE & (uint32_t)(_PORTE_RE1_MASK))
#define mSet_PIC_SMMIO_1()              (LATESET = (uint32_t)(_PORTE_RE1_MASK))
#define mClear_SLOT_ID_1()              (LATECLR = (uint32_t)(_PORTE_RE1_MASK))
#define mToggle_SLOT_ID_1()             (LATEINV = (uint32_t)(_PORTE_RE1_MASK))

#define mRead_NOT_USED_15()             (PORTE & (uint32_t)(_PORTE_RE2_MASK))
#define mSet_NOT_USED_15()              (LATESET = (uint32_t)(_PORTE_RE2_MASK))
#define mClear_NOT_USED_15()            (LATECLR = (uint32_t)(_PORTE_RE2_MASK))
#define mToggle_NOT_USED_15()           (LATEINV = (uint32_t)(_PORTE_RE2_MASK))

#define mRead_NOT_USED_16()             (PORTE & (uint32_t)(_PORTE_RE3_MASK))
#define mSet_NOT_USED_16()              (LATESET = (uint32_t)(_PORTE_RE3_MASK))
#define mClear_NOT_USED_16()            (LATECLR = (uint32_t)(_PORTE_RE3_MASK))
#define mToggle_NOT_USED_16()           (LATEINV = (uint32_t)(_PORTE_RE3_MASK))

#define mRead_NOT_USED_17()             (PORTE & (uint32_t)(_PORTE_RE4_MASK))
#define mSet_NOT_USED_17()              (LATESET = (uint32_t)(_PORTE_RE4_MASK))
#define mClear_NOT_USED_17()            (LATECLR = (uint32_t)(_PORTE_RE4_MASK))
#define mToggle_NOT_USED_17()           (LATEINV = (uint32_t)(_PORTE_RE4_MASK))

#define mRead_NOT_USED_18()             (PORTE & (uint32_t)(_PORTE_RE5_MASK))
#define mSet_NOT_USED_18()              (LATESET = (uint32_t)(_PORTE_RE5_MASK))
#define mClear_NOT_USED_18()            (LATECLR = (uint32_t)(_PORTE_RE5_MASK))
#define mToggle_NOT_USED_18()           (LATEINV = (uint32_t)(_PORTE_RE5_MASK))

#define mRead_NOT_USED_19()             (PORTE & (uint32_t)(_PORTE_RE6_MASK))
#define mSet_NOT_USED_19()              (LATESET = (uint32_t)(_PORTE_RE6_MASK))
#define mClear_NOT_USED_19()            (LATECLR = (uint32_t)(_PORTE_RE6_MASK))
#define mToggle_NOT_USED_19()           (LATEINV = (uint32_t)(_PORTE_RE6_MASK))

#define mRead_NOT_USED_20()             (PORTE & (uint32_t)(_PORTE_RE7_MASK))
#define mSet_NOT_USED_20()              (LATESET = (uint32_t)(_PORTE_RE7_MASK))
#define mClear_NOT_USED_20()            (LATECLR = (uint32_t)(_PORTE_RE7_MASK))
#define mToggle_NOT_USED_20()           (LATEINV = (uint32_t)(_PORTE_RE7_MASK))

#define mRead_NOT_USED_21()             (PORTE & (uint32_t)(_PORTE_RE8_MASK))
#define mSet_NOT_USED_21()              (LATESET = (uint32_t)(_PORTE_RE8_MASK))
#define mClear_NOT_USED_21()            (LATECLR = (uint32_t)(_PORTE_RE8_MASK))
#define mToggle_NOT_USED_21()           (LATEINV = (uint32_t)(_PORTE_RE8_MASK))

#define mRead_NOT_USED_22()             (PORTE & (uint32_t)(_PORTE_RE9_MASK))
#define mSet_NOT_USED_22()              (LATESET = (uint32_t)(_PORTE_RE9_MASK))
#define mClear_NOT_USED_22()            (LATECLR = (uint32_t)(_PORTE_RE9_MASK))
#define mToggle_NOT_USED_22()           (LATEINV = (uint32_t)(_PORTE_RE9_MASK))

//PORT F
#define mRead_CAN1_RX()                 (PORTF & (uint32_t)(_PORTF_RF0_MASK))
#define mSet_CAN1_RX()                  (LATFSET = (uint32_t)(_PORTF_RF0_MASK))
#define mClear_CAN1_RX()                (LATFCLR = (uint32_t)(_PORTF_RF0_MASK))
#define mToggle_CAN1_RX()               (LATFINV = (uint32_t)(_PORTF_RF0_MASK))

#define mRead_CAN1_TX()                 (PORTF & (uint32_t)(_PORTF_RF1_MASK))
#define mSet_CAN1_TX()                  (LATFSET = (uint32_t)(_PORTF_RF1_MASK))
#define mClear_CAN1_TX()                (LATFCLR = (uint32_t)(_PORTF_RF1_MASK))
#define mToggle_CAN1_TX()               (LATFINV = (uint32_t)(_PORTF_RF1_MASK))

#define mRead_NOT_USED_23()             (PORTF & (uint32_t)(_PORTF_RF2_MASK))
#define mSet_NOT_USED_23()              (LATFSET = (uint32_t)(_PORTF_RF2_MASK))
#define mClear_NOT_USED_23()            (LATFCLR = (uint32_t)(_PORTF_RF2_MASK))
#define mToggle_NOT_USED_23()           (LATFINV = (uint32_t)(_PORTF_RF2_MASK))

#define mRead_PROM_WP()                 (PORTF & (uint32_t)(_PORTF_RF3_MASK))
#define mSet_PROM_WP()                  (LATFSET = (uint32_t)(_PORTF_RF3_MASK))
#define mClear_PROM_WP()                (LATFCLR = (uint32_t)(_PORTF_RF3_MASK))
#define mToggle_PROM_WP()               (LATFINV = (uint32_t)(_PORTF_RF3_MASK))

#define mRead_DIGI_SPI_OUT()            (PORTF & (uint32_t)(_PORTF_RF4_MASK))
#define mSet_DIGI_SPI_OUT()             (LATFSET = (uint32_t)(_PORTF_RF4_MASK))
#define mClear_DIGI_SPI_OUT()           (LATFCLR = (uint32_t)(_PORTF_RF4_MASK))
#define mToggle_DIGI_SPI_OUT()          (LATFINV = (uint32_t)(_PORTF_RF4_MASK))

#define mRead_DIGI_SPI_IN()             (PORTF & (uint32_t)(_PORTF_RF5_MASK))
#define mSet_DIGI_SPI_IN()              (LATFSET = (uint32_t)(_PORTF_RF5_MASK))
#define mClear_DIGI_SPI_IN()            (LATFCLR = (uint32_t)(_PORTF_RF5_MASK))
#define mToggle_DIGI_SPI_IN()           (LATFINV = (uint32_t)(_PORTF_RF5_MASK))

#define mRead_NOT_USED_24()             (PORTF & (uint32_t)(_PORTF_RF8_MASK))
#define mSet_NOT_USED_24()              (LATFSET = (uint32_t)(_PORTF_RF8_MASK))
#define mClear_NOT_USED_24()            (LATFCLR = (uint32_t)(_PORTF_RF8_MASK))
#define mToggle_NOT_USED_24()           (LATFINV = (uint32_t)(_PORTF_RF8_MASK))

#define mRead_DIGI_SPI_EN()             (PORTF & (uint32_t)(_PORTF_RF12_MASK))
#define mSet_DIGI_SPI_EN()              (LATFSET = (uint32_t)(_PORTF_RF12_MASK))
#define mClear_DIGI_SPI_EN()            (LATFCLR = (uint32_t)(_PORTF_RF12_MASK))
#define mToggle_DIGI_SPI_EN()           (LATFINV = (uint32_t)(_PORTF_RF12_MASK))

#define mRead_DIGI_SPI_CLK()            (PORTF & (uint32_t)(_PORTF_RF13_MASK))
#define mSet_DIGI_SPI_CLK()             (LATFSET = (uint32_t)(_PORTF_RF13_MASK))
#define mClear_DIGI_SPI_CLK()           (LATFCLR = (uint32_t)(_PORTF_RF13_MASK))
#define mToggle_DIGI_SPI_CLK()          (LATFINV = (uint32_t)(_PORTF_RF13_MASK))

// PORTG
#define mRead_CAN_2_RX()                (PORTG & (uint32_t)(_PORTG_RG0_MASK))
#define mSet_CAN_2_RX()                 (LATGSET = (uint32_t)(_PORTG_RG0_MASK))
#define mClear_CAN_2_RX()               (LATGCLR = (uint32_t)(_PORTG_RG0_MASK))
#define mToggle_CAN_2_RX()              (LATGINV = (uint32_t)(_PORTG_RG0_MASK))

#define mRead_CAN_2_TX()                (PORTG & (uint32_t)(_PORTG_RG1_MASK))
#define mSet_CAN_2_TX()                 (LATGSET = (uint32_t)(_PORTG_RG1_MASK))
#define mClear_CAN_2_TX()               (LATGCLR = (uint32_t)(_PORTG_RG1_MASK))
#define mToggle_CAN_2_TX()              (LATGINV = (uint32_t)(_PORTG_RG1_MASK))

#define mRead_NOT_USED_25()             (PORTG & (uint32_t)(_PORTG_RG2_MASK))
#define mSet_NOT_USED_25()              (LATGSET = (uint32_t)(_PORTG_RG2_MASK))
#define mClear_NOT_USED_25()            (LATGCLR = (uint32_t)(_PORTG_RG2_MASK))
#define mToggle_NOT_USED_25()           (LATGINV = (uint32_t)(_PORTG_RG2_MASK))

#define mRead_NOT_USED_26()             (PORTG & (uint32_t)(_PORTG_RG3_MASK))
#define mSet_NOT_USED_26()              (LATGSET = (uint32_t)(_PORTG_RG3_MASK))
#define mClear_NOT_USED_26()            (LATGCLR = (uint32_t)(_PORTG_RG3_MASK))
#define mToggle_NOT_USED_26()           (LATGINV = (uint32_t)(_PORTG_RG3_MASK))

#define mRead_SMM_PROM()                (PORTG & (uint32_t)(_PORTG_RG6_MASK))
#define mSet_SMM_PROM()                 (LATGSET = (uint32_t)(_PORTG_RG6_MASK))
#define mClear_SMM_PROM()               (LATGCLR = (uint32_t)(_PORTG_RG6_MASK))
#define mToggle_SMM_PROM()              (LATGINV = (uint32_t)(_PORTG_RG6_MASK))

#define mRead_MP_PROM()                 (PORTG & (uint32_t)(_PORTG_RG7_MASK))
#define mSet_MP_PROM()                  (LATGSET = (uint32_t)(_PORTG_RG7_MASK))
#define mClear_MP_PROM()                (LATGCLR = (uint32_t)(_PORTG_RG7_MASK))
#define mToggle_MP_PROM()               (LATGINV = (uint32_t)(_PORTG_RG7_MASK))

#define mRead_SYS_LED()                 (PORTG & (uint32_t)(_PORTG_RG8_MASK))
#define mSet_SYS_LED()                  (LATGSET = (uint32_t)(_PORTG_RG8_MASK))
#define mClear_SYS_LED()                (LATGCLR = (uint32_t)(_PORTG_RG8_MASK))
#define mToggle_SYS_LED()               (LATGINV = (uint32_t)(_PORTG_RG8_MASK))

#define mRead_NOT_USED_27()             (PORTG & (uint32_t)(_PORTG_RG9_MASK))
#define mSet_NOT_USED_27()              (LATGSET = (uint32_t)(_PORTG_RG9_MASK))
#define mClear_NOT_USED_27()            (LATGCLR = (uint32_t)(_PORTG_RG9_MASK))
#define mToggle_NOT_USED_27()           (LATGINV = (uint32_t)(_PORTG_RG9_MASK))

#define mRead_NOT_USED_28()             (PORTG & (uint32_t)(_PORTG_RG12_MASK))
#define mSet_NOT_USED_28()              (LATGSET = (uint32_t)(_PORTG_RG12_MASK))
#define mClear_NOT_USED_28()            (LATGCLR = (uint32_t)(_PORTG_RG12_MASK))
#define mToggle_NOT_USED_28()           (LATGINV = (uint32_t)(_PORTG_RG12_MASK))

#define mRead_NOT_USED_29()             (PORTG & (uint32_t)(_PORTG_RG13_MASK))
#define mSet_NOT_USED_29()              (LATGSET = (uint32_t)(_PORTG_RG13_MASK))
#define mClear_NOT_USED_29()            (LATGCLR = (uint32_t)(_PORTG_RG13_MASK))
#define mToggle_NOT_USED_29()           (LATGINV = (uint32_t)(_PORTG_RG13_MASK))

#define mRead_NOT_USED_30()             (PORTG & (uint32_t)(_PORTG_RG14_MASK))
#define mSet_NOT_USED_30()              (LATGSET = (uint32_t)(_PORTG_RG14_MASK))
#define mClear_NOT_USED_30()            (LATGCLR = (uint32_t)(_PORTG_RG14_MASK))
#define mToggle_NOT_USED_30()           (LATGINV = (uint32_t)(_PORTG_RG14_MASK))

#define mRead_NOT_USED_31()             (PORTG & (uint32_t)(_PORTG_RG15_MASK))
#define mSet_NOT_USED_31()              (LATGSET = (uint32_t)(_PORTG_RG15_MASK))
#define mClear_NOT_USED_31()            (LATGCLR = (uint32_t)(_PORTG_RG15_MASK))
#define mToggle_NOT_USED_31()           (LATGINV = (uint32_t)(_PORTG_RG15_MASK))

// ADC Channels
#define V_FAN_MEAS          (ADC0_REG)
#define V_5V_STBY_MEAS      (ADC1_REG)
#define V_5V_MEAS           (ADC2_REG)
#define V_3V3_MEAS          (ADC3_REG)
#define V_12V_MEAS          (ADC4_REG)

//ADC limits
#define ADC_RESOLUTION  2441L // in uVolts
// Nominal = ( ((pullDownR * VoltageInUVolts)/(pullDownR+pullUpR)) / (ADC_RESOLUTION)
// Max = (Nominal) * (1.05) // +5%
// Min = (Nominal) * (0.95) // -5%

//V_FAN_MEAS
#define V_FAN_MEAS_NOMINAL              (((47 * 24000000L)/(47 + 470)) / (ADC_RESOLUTION))
#define V_FAN_MEAS_MAX                  ((V_FAN_MEAS_NOMINAL * 110L) / 100)
#define V_FAN_MEAS_MIN                  ((V_FAN_MEAS_NOMINAL * 90L) / 100)

//V_5V_STBY_MEAS
#define V_5V_STBY_MEAS_NOMINAL          (((22 * 5000000L)/(22 + 27)) / (ADC_RESOLUTION))
#define V_5V_STBY_MEAS_MAX               ((V_5V_STBY_MEAS_NOMINAL * 105L) / 100)
#define V_5V_STBY_MEAS_MIN               ((V_5V_STBY_MEAS_NOMINAL * 95L) / 100)

//V_5V_MEAS
#define V_5V_MEAS_NOMINAL               (((22 * 5000000L)/(22 + 27)) / (ADC_RESOLUTION))
#define V_5V_MEAS_MAX                   ((V_5V_MEAS_NOMINAL * 105L) / 100)
#define V_5V_MEAS_MIN                   ((V_5V_MEAS_NOMINAL * 95L) / 100)

//V_3V3_MEAS
#define V_3V3_MEAS_NOMINAL               (((22 * 3300000L)/(22 + 10)) / (ADC_RESOLUTION))
#define V_3V3_MEAS_MAX                   ((V_3V3_MEAS_NOMINAL * 105L) / 100)
#define V_3V3_MEAS_MIN                   ((V_3V3_MEAS_NOMINAL * 95L) / 100)

//V_12V_MEAS
#define V_12V_MEAS_NOMINAL              (((10 * 12000000L)/(47 + 10)) / (ADC_RESOLUTION))
#define V_12V_MEAS_MAX                  ((V_12V_MEAS_NOMINAL * 110L) / 100)
#define V_12V_MEAS_MIN                  ((V_12V_MEAS_NOMINAL * 90L) / 100)

// Timer 1
#define COUNT_50MS_TICK  15625      // 50ms =  (1/PCLK)*TimerPrescaler*count    
#define HALF_SECOND_50MSEC 10

// Object Dictionary register re-assignment
#define SYSTEM_STATUS_REG GP_REG_0  
#define SYSTEM_STATUS_REG_DUT_FITTED_MASK   0x0001
#define SYSTEM_STATUS_REG_SW_FITTED_MASK    0x0002
#define SYSTEM_STATUS_REG_FAN_FITTED_MASK   0x0004
#define SYSTEM_STATUS_REG_SW_PRESSED_MASK   0x0008

#define COM_HEARTBEAT_STATUS_REG            GP_REG_1 
#define POWER_HEARTBEAT_STATUS_REG          GP_REG_2 
#define DIGITAL_HEARTBEAT_STATUS_REG        GP_REG_3 
#define EXP_HEARTBEAT_STATUS_REG            GP_REG_4
#define POWER_TRAY_HEARTBEAT_STATUS_REG     GP_REG_5  
#define SELECT_EEPROM_REG                   GP_REG_6
#define POWER_UP_SLOT_REG                   GP_REG_7     
#define SETUP_SLOT_TACHO_MEASUREMENT_REG    GP_REG_8
#define TACHO_FAN_1_MEASUREMENT_REG         GP_REG_9
#define TACHO_FAN_2_MEASUREMENT_REG         GP_REG_A
#define TACHO_FAN_3_MEASUREMENT_REG         GP_REG_B
#define TACHO_FAN_4_MEASUREMENT_REG         GP_REG_C
#define TACHO_FAN_DUT_MEASUREMENT_REG       GP_REG_D
#define TACHO_ERROR_REG                     GP_REG_E
#define RESET_REG                           GP_REG_F

BOOL HWAPI_InitialiseHardware(void);
void HWAPI_InitialiseInterfaces(void);
uint16_t HWAPI_getNodeId(void);
uint16_t HWAPI_getSlotId(void);
BOOL HWAPI_IsHalfSecondUp(void);
void __attribute__((noreturn)) HWAPI_SoftReset(void);

#endif //HARDWARE_SETUP_H