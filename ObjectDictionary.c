#include "ObjectDictionary.h"

static BOOL accessFPGARegister(uint32_t, uint32_t, BOOL); // not implemented

static objectDictionary_t objectDictionary[]=
{
    { 0, VALUE, NULL},                  // MODULE_TYPE
    { 0, VALUE, NULL},                  // ERROR_REG
    { 0, VALUE, NULL},                  // SERIAL_NUMBER
    { 0, VALUE, NULL},                  // REVISION_NUMBER
    { 0, VALUE, NULL},                  // ADC0_REG
    { 0, VALUE, NULL},                  // ADC1_REG
    { 0, VALUE, NULL},                  // ADC2_REG
    { 0, VALUE, NULL},                  // ADC3_REG
    { 0, VALUE, NULL},                  // ADC4_REG
    { 0, VALUE, NULL},                  // ADC5_REG
    { 0, VALUE, NULL},                  // ADC6_REG
    { 0, VALUE, NULL},                  // ADC7_REG
    { 0, VALUE, NULL},                  // ADC8_REG
    { 0, VALUE, NULL},                  // ADC9_REG
    { 0, VALUE, NULL},                  // ADCA_REG
    { 0, VALUE, NULL},                  // ADCB_REG
    { 0, VALUE, NULL},                  // ADCC_REG
    { 0, VALUE, NULL},                  // ADCD_REG
    { 0, VALUE, NULL},                  // ADCE_REG
    { 0, VALUE, NULL}                   // ADCF_REG 
    { 0, VALUE, &accessFPGARegister}    // FPGA_REG   
};

BOOL 
OBJECTDICT_setObject(uint32_t objectIndex, uint32_t value)
{
    BOOL success;

    if ( (objectIndex <= END_OF_OBJECT_LIST) )        // local register
    {
        if ( objectDictionary[objectIndex].function != NULL)
        {            
            objectDictionary[objectIndex].function(objectIndex, value, FALSE); //write   
        }
        objectDictionary[objectIndex].value = value;
        success = TRUE;
    }
    else
    {
        success = FALSE;
    }
    return success;
}

objectDictionary_t* 
OBJECTDICT_getObject(uint32_t objectIndex)
{
    objectDictionary_t* pObjectDictionaryItem;
/*
    if ( (objectIndex >= START_FPGA_REGISTERS) && (objectIndex <= END_FPGA_REGISTERS) )// FPGA register
    {
        if ( objectDictionary[FPGA_REG].function != NULL)
        {
            objectDictionary[FPGA_REG].function(objectIndex - START_FPGA_REGISTERS, 0, TRUE); //read   
        }
        pObjectDictionaryItem = &objectDictionary[FPGA_REG];     
    }
else */ 
    if (objectIndex <= END_OF_OBJECT_LIST)     // local register
    {
        if ( objectDictionary[objectIndex].function != NULL)
        {
            objectDictionary[objectIndex].function(objectIndex, 0, TRUE);   
        }
        pObjectDictionaryItem = &objectDictionary[objectIndex];
    }
    else
    {
        pObjectDictionaryItem = NULL;
    }
    
    return pObjectDictionaryItem;
}

static BOOL 
accessFPGARegister(uint32_t address, uint32_t data, BOOL readAccess)
{
    BOOL success = FALSE;
    uint16_t readValue; 
    return success;
}
