#include "CANAppLayer.h"
#include "ObjectDictionary.h"

typedef struct {
    uint16_t address;
    uint32_t node_id;
} uartReadRequest_t;

static BOOL enableCanToUart = FALSE;
static BOOL enableDisplayReadCommand = FALSE;
static uartReadRequest_t uartReadRequest;

static void 
_nibblesToHexAscii(uint8_t number, uchar_t*buffer, uint8_t numberOfNibbles)
{
    switch (*buffer)
    {
        case 10:
            *buffer = 'A';
            break;  
        case 11:
            *buffer = 'B';
            break;
        case 12:
            *buffer = 'C';
            break;
        case 13:
            *buffer = 'D';
            break;
        case 14:
            *buffer = 'E';
            break;
        case 15:
            *buffer = 'F';
            break;
        default:
            *buffer = *buffer + 0x30;   // it is a number 
    };
   
}

static void 
canRxMessageToString(CANRxMessageBuffer *message, uchar_t **stringBuffer)
{
    uchar_t* pStringBuffer;

    pStringBuffer = *stringBuffer;
    _nibblesToHexAscii(message->msgSID.SID & 0x7FF, pStringBuffer, 3);
    pStringBuffer++;
    pStringBuffer++;
    pStringBuffer++;

    *pStringBuffer++ =' ';
    _nibblesToHexAscii(message->msgEID.RTR, pStringBuffer, 1);
    pStringBuffer++;

    *pStringBuffer++ =' ';
    _nibblesToHexAscii(message->msgEID.DLC, pStringBuffer, 1);
    pStringBuffer++;

    *pStringBuffer++ =' ';
    for (uchar_t i=0; i<8; i++)
    {
        _nibblesToHexAscii(message->data[i], pStringBuffer,2);
        pStringBuffer++;
        pStringBuffer++;
        *pStringBuffer++ =' ';   
    }
    *pStringBuffer++ ='\r';
    *pStringBuffer ='\n';
}

BOOL 
CANAPP_RequestToReadObject (objectLocation_e objectType, 
    uint16_t objectIndex, uint8_t objectsubIndex, uint32_t nodeId)
{
	CANTxMessageBuffer message;
	BOOL success;

	message.messageWord = {0, 0, 0, 0}; // clear previous message

	switch (objectType) {
        case LOCAL_OBJECT:
            message.msgSID.SID 	= SDO_CLIENT_COBID;
            message.msgEID.EID  = nodeId;
            success = TRUE;
            break;
        case FPGA_OBJECT:
            message.msgSID.SID 	= SDO_FPGA_CLIENT_COBID;
            message.msgEID.EID  = nodeId;
            success = TRUE;
            break;
        default:
            success = FALSE;
    }   
    
    if (success == TRUE)
    {		
    	message.msgEID.IDE 	= 1;			
    	message.msgEID.DLC 	= 0x8; 			
    	message.data[0]       = CMD_SDO_READ;
    	message.data[1]       = objectIndex & 0x00FF;
    	message.data[2]       = (objectIndex & 0xFF00) >>8;
    	message.data[3]       = objectsubIndex;
    	message.data[4]       = 0x0;
    	message.data[5]       = 0x0;
    	message.data[6]       = 0x0;
    	message.data[7]       = 0x0;		
    	success = CAN1_TxMessage(&message); 
	}

	return success;	
}

BOOL 
CANAPP_RequestToWriteObject (objectLocation_e objectType,
    uint16_t objectIndex, uint8_t objectsubIndex, uint32_t nodeId, uint32_t data)
{
	CANTxMessageBuffer message;
	BOOL success;
	
	message.messageWord = {0, 0, 0, 0}; // clear previous message
    
	switch (objectType) {
        case LOCAL_OBJECT:
            message.msgSID.SID 	= SDO_CLIENT_COBID;
            message.msgEID.EID  = nodeId;
            success = TRUE;
            break;
        case FPGA_OBJECT:
            message.msgSID.SID 	= SDO_FPGA_CLIENT_COBID;
            message.msgEID.EID  = nodeId;
            success = TRUE;
            break;
        default:
            success = FALSE;
    }   
    
    if (success == TRUE)
    {  		
    	message.msgEID.IDE 	= 1;			
    	message.msgEID.DLC 	= 0x8;			
    	message.data[0]       = CMD_SDO_WRITE;
    	message.data[1]       = objectIndex & 0x00FF;
    	message.data[2]       = (objectIndex & 0xFF00) >> 8;
    	message.data[3]       = objectsubIndex;
    	message.data[4]       = (uint8_t)(data & 0x000000FF);
    	message.data[5]       = (uint8_t)((data & 0x0000FF00) >> 8);
    	message.data[6]       = (uint8_t)((data & 0x00FF0000) >> 16);
    	message.data[7]       = (uint8_t)((data & 0xFF000000) >> 24);

    	success = CAN1_TxMessage(&message); 
    }	
	return success;	
}

BOOL 
CANAPP_RequestToSendHeartBeat (void)
{
	CANTxMessageBuffer message;
	BOOL success;
    objectDictionary_t *pObjectDictionary;

	message.messageWord = {0, 0, 0, 0}; // clear previous message

	message.msgSID.SID 	= HEARTBEAT_COBID;
    message.msgEID.EID  = CAN1_getNodeId();		
	message.msgEID.IDE 	= 1;			
	message.msgEID.DLC 	= 0x8;				
    pObjectDictionary = OBJECTDICT_getObject(ERROR_REG);
    message.messageWord[3] = pObjectDictionary->value;	
	success = CAN1_TxMessage(&message); 	
	return success;	
}

void 
CANAPP_enableCANMonitor(BOOL enable)
{
    enableCanToUart = enable;
}

void 
CANAPP_enableDisplayReadCommand(uint16_t address, uint32_t node_id)
{
    uartReadRequest.address = address; 
    uartReadRequest.node_id = node_id;
    enableDisplayReadCommand = TRUE;
}

BOOL 
CANAPP_ProcessRxMessage(errorList_e *error)
{ 
    CANRxMessageBuffer *message;
    BOOL success;   
    uchar_t txBuffer[34];
    uchar_t* pTxBuffer;

    success = TRUE;
    *error = NO_ERROR;

    if (CAN1_ProcessRxMessages(&message) ) 
    {
        pTxBuffer = txBuffer;
        if (enableCanToUart)    
        { 
            canRxMessageToString(message, &pTxBuffer);
            UARTAPI_txString(txBuffer, 34);
        } 
        if (enableDisplayReadCommand)
        {
            // look for correct COBID, read response command and address
            if  ( 
                ( message->msgSID.SID == SDO_SERVER_COBID || message->msgSID.SID == SDO_FPGA_SERVER_COBID) &&
                    message->msgEID.EID == uartReadRequest.node_id &&
                    message->data[0] == CMD_SDO_READ_RESPONSE &&
                    message->data[1] == (uartReadRequest.address & 0x00FF)  &&
                    message->data[2] == uartReadRequest.address>>8
                )
            {
                _nibblesToHexAscii(message->messageWord[3], txBuffer, 8); 
                txBuffer[8] ='\r';
                txBuffer[9] ='\n';
                UARTAPI_txString(txBuffer, 10);
                enableDisplayReadCommand = FALSE;
            }           

        }  
        PORTAINV = 0x01;
        PORTFINV = 0x10; 
    }
    return (success);
}
