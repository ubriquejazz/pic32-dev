#ifndef CAN_OBJECT_DICTIONARY_H
#define CAN_OBJECT_DICTIONARY_H

#include "global.h"

typedef enum {
    VALUE = 0, 
    QUEUED_VALUE, 
    FUNCTION_CALL} 
objectType_e; 

typedef enum {LOCAL_OBJECT, FPGA_OBJECT} objectLocation_e;

typedef BOOL (*pObjectDictionaryFunction) (uint32_t, uint32_t, BOOL);

typedef struct {
    uint32_t value;
    objectType_e type; 
    pObjectDictionaryFunction function;
}objectDictionary_t;

// The enum should match the entries to objectDictionary[] defined
// in CANObjectDictionary.c
typedef enum {
    MODULE_TYPE_REG = 0,    // 0
    ERROR_REG,              // 1
    SERIAL_NUMBER_REG,      // 2
    SW_REV_REG,             // 3
    CAN_ERROR_REG,          // 4
    ADC0_REG,               // 5
    ADC1_REG,               // 6
    ADC2_REG,               // 7 
    ADC3_REG,               // 8
    ADC4_REG,               // 9
    ADC5_REG,               // A
    ADC6_REG,               // B
    ADC7_REG,               // C
    ADC8_REG,               // D
    ADC9_REG,               // E
    ADCA_REG,               // F
    ADCB_REG,               // 10
    ADCC_REG,               // 11
    ADCD_REG,               // 12
    ADCE_REG,               // 13
    ADCF_REG,               // 14
    TEMPERATURE_REG,        // 15
    EEPROM_REG,             // 16
    END_OF_OBJECT_LIST = EEPROM_REG
} objectDictionaryAddress_e;

// FPGA REGISTERS
#define BASE_ADDRESS_FPGA_REGISTERS 0x10000
//#define END_FPGA_REGISTERS 0x1FFF
//EEPROM REGISTERS 
#define START_EEPROM_REGISTERS 0xE00
#define END_EEPROM_REGISTERS 0xFFF
// ERROR REGISTER Bits
#define ERROR_REG_CAN_BIT 1
#define ERROR_REG_FPGA_BIT 2
#define ERROR_REG_EEPROM_BIT 4
#define ERROR_REG_TEMPERATURE_BIT 8

typedef enum {
    NO_ERROR = 0, 
    INVALID_COBID_ERROR, 
    INVALID_CMD_ERROR, 
    INVALID_OBJECT_INDEX_ERROR, 
    TX_BUFFER_FULL_ERROR,
    NOT_ENOUGH_SPACE_IN_EEPROM_SCRATCHPAD,
    FAILED_EEPROM_SCRATCHPAD_VERIFICATION,
    INVALID_EEPROM_ADDRESS
} errorList_e;

typedef enum {
    CAN_ERROR = 0,
    FPGA_ERROR,
    ONE_WIRE_EEPROM_ERROR,
    ONE_WIRE_TEMPERATURE_ERROR, 
    ONE_WIRE_BUS_ERROR   
} errorCaregory_e;

BOOL OBJECTDICT_API_setObject(uint32_t, uint32_t);

objectDictionary_t* OBJECTDICT_API_getObject(uint32_t);

#endif