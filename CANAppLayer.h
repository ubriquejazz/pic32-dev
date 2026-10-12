#ifndef CANAPP_LAYER_H
#define CANAPP_LAYER_H

#include "global.h"
#include "CANfunctions.h"
#include "ObjectDictionary.h"

#define COMMS_BOARD 1
#define DIGITAL_BOARD 2
#define POWER_BOARD 3

// COBID Should have a min difference of 0x80
// The order of COBID should not be changed 
typedef enum {
    INVALID_COBID = 0x0000,
    SDO_FPGA_SERVER_COBID = 0x480,
    SDO_FPGA_CLIENT_COBID = 0x500,
    SDO_SERVER_COBID = 0x580,
    SDO_CLIENT_COBID = 0x600,
    HEARTBEAT_COBID = 0x700
} cobId_e;

// SDO commands
#define CMD_SDO_READ            0x40
#define CMD_SDO_READ_RESPONSE   0x43
#define CMD_SDO_WRITE           0x23
#define CMD_SDO_WRITE_RESPONSE  0x20
#define TX_MESSAGE_QUEUE_SIZE 1

//typedef enum {
//    NO_ERROR, 
//    INVALID_COBID_ERROR, 
//    INVALID_CMD_ERROR, 
//    INVALID_OBJECT_INDEX_ERROR, 
//    TX_BUFFER_FULL_ERROR
//} canAppErrors_e;

BOOL CANAPP_RequestToReadObject (objectLocation_e, uint16_t, uint8_t, uint32_t);

BOOL CANAPP_RequestToWriteObject (objectLocation_e, uint16_t, uint8_t, uint32_t, uint32_t);

BOOL CANAPP_ProcessRxMessage(errorList_e *error);

void CANAPP_enableCANMonitor(BOOL enable);

void CANAPP_enableDisplayReadCommand(uint16_t address, uint32_t node_id);

#endif //CANAPPLAYER_H
