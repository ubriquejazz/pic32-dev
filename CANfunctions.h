#ifndef CAN_FUNCTIONS_H
#define CAN_FUNCTIONS_H

#include "global.h"

// CAN modes of operation
#define NORMAL_OPERATION_MODE   0x0
#define LISTEN_ONLY_MODE        0x3
#define CONFIGURATION_MODE      0x4

// Used CAN FIFOs
#define FIFO_0 0   // FIFO 0 for SDO Tx to Server
#define FIFO_1 1   // FIFO 1 for SDO Tx to Client
#define FIFO_2 2   // FIFO 2 for SDO Rx from Server
#define FIFO_3 3   // FIFO 3 for SDO Rx from Client

#define SDO_RX_FROM_CLIENT_MSG_BUFFERS 7
#define SDO_TX_TO_SERVER_MSG_BUFFERS 7

// CAN FIFO size (actual size is number + 1)
#define CAN1_TOTAL_SDO_MESSAGE_BUFFERS      2 + SDO_RX_FROM_CLIENT_MSG_BUFFERS + SDO_TX_TO_SERVER_MSG_BUFFERS
#define CAN1_TOTAL_MSG_BUFFERS              CAN1_TOTAL_SDO_MESSAGE_BUFFERS
#define CAN1_SIZE_OF_FIFO_MESSAGE_BUFFER    16
#define CAN1_FIFO_SIZE 16 * CAN1_SIZE_OF_FIFO_MESSAGE_BUFFER / 4 // using 32-bit word

// CAN FILTERS
#define SDO_CLIENT_FILTER SDO_CLIENT_COBID
#define SDO_SERVER_FILTER SDO_SERVER_COBID
#define SDO_MASK 0xFFFFFF80 // mask to accept from SDO_CLIENT_COBID to SDO_CLIENT_COBID + 0x7F, where 7F max number of nodes

// CAN Interrupts
#define CAN1_INTERRUPT_PRIORITY 5 // should match the priority specified in the CAN1 interrupt handler
#define CAN1_INTERRUPT_SUB_PRIORITY 1

typedef struct
{
    uint16_t nodeId;
    uint16_t bridgeCanOneAndTwo;
    uint16_t bridgeCan;
} CANInit_t;

typedef	struct 
{
	unsigned SID:11;
	unsigned :21;
} CAN_TX_MSG_SID;        // CAN TX Message Standard ID. This value should be between 0x0 - 0x7FF

typedef struct 
{
    // Data Length Control. Specifies the size of the
    // data payload section of the CAN packet. Valid 
    // values are 0x0 - 0x8.
	unsigned DLC:4;

    // Reserved bit. Should be always 0.
	unsigned RB0:1;
	unsigned :3;

    // Reserved bit. Should be always 0.
	unsigned RB1:1;

    // Remote Transmit Request bit. Should be set for
    // RTR messages, clear otherwise.
	unsigned RTR:1;

    // CAN TX and RX Extended ID field. Valid values
    // are in range 0x0 - 0x3FFFF. 
	unsigned EID:18;

    // Identifier bit. If 0 means that message is SID.
    // If 1 means that message is EID type.
	unsigned IDE:1;

    // Susbtitute Remote request bit. This bit should
    // always be clear for an EID message. It is ignored
    // for an SID message.
	unsigned SRR:1;
	unsigned :2;

} CAN_MSG_EID;

typedef union {

	struct
	{
        // This is SID portion of the CAN TX message.
		CAN_TX_MSG_SID msgSID;

        // This is EID portion of the CAN TX message.
		CAN_MSG_EID msgEID;

        // This is the data portion of the CAN TX message.
		uchar_t data[8];
	};

    // This is CAN TX message organized as a set of 32 bit words.
	uint32_t messageWord[4];

} CANTxMessageBuffer;

typedef	struct 
{
    // SID of the Received CAN Message. 
	unsigned SID:11;

    // Filter which accepted this message.
	unsigned FILHIT:5;

    // Time stamp of the received message. This is
    // valid only if the Timestamping is enabled.
	unsigned CMSGTS:16;

} CAN_RX_MSG_SID;

typedef union {

	struct
	{
        // This is SID portion of the CAN RX message.
		CAN_RX_MSG_SID msgSID;

        // This is EID portion of the CAN RX message
		CAN_MSG_EID msgEID;

        // This is the data payload section of the 
        // received message.
		uchar_t data[8];
	};

    // This can be used if the message buffer is to 
    // be read from a Data-Only type of CAN RX Channel.
    uchar_t dataOnlyMsgData[8];

    // This is CAN RX message organized as a set of 32 bit  words.
	uint32_t messageWord[4];

} CANRxMessageBuffer;

void CAN1_Initialise(CANInit_t *);
void CAN2_Initialise(CANInit_t *);

BOOL CAN1_TxMessage(CANTxMessageBuffer *);

BOOL CAN1_ProcessRxMessages(CANRxMessageBuffer **);

uint16_t CAN1_getNodeId(void);

#endif

