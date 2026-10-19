#include "XilinxFlash.h"
#include "HardwareSetup.h"
#include "SpiOne.h"

#define RX_BUFFER_SIZE 260 // max command length is 4 + page size which is 256 Bytes

// FLASH Instruction Set
static const uint8_t WREN = 0x06;       // write enable
static const uint8_t WRDI = 0x04;       // write diasable
static const uint8_t RDSR = 0x05;       // read status register
static const uint8_t WRSR = 0x01;       // write status register
static const uint8_t READ = 0x03;       // read date bytes
static const uint8_t PP = 0x02;         // page program
static const uint8_t SE = 0xD8;         // sector erase
static const uint8_t BE = 0xC7;

union {
	struct {
        unsigned WRITE_IN_PROGRESS_BIT:1;
        unsigned WRITE_ENABLE_LATCH:1;
        unsigned BLOCK_PROTECT_BITS:3;
        unsigned :2;
        unsigned STATUS_REGISTER_WRITE_PROTECT:1;
    };
    uint8_t byte;
} flashStatusRegister;

/* Private */

static uint8_t rxBuffer[RX_BUFFER_SIZE];
static uint8_t txBuffer[RX_BUFFER_SIZE];

static void cmdWriteEnable(void)
{
    txBuffer[0] = WREN;
    SPIOne_TxRxBuffer(txBuffer, rxBuffer, 1);
}

static BOOL 
cmdProgramPage(uint32_t flashAddress, uint32_t numberOfBytes)
{
    BOOL success;
    if (numberOfBytes <= RX_BUFFER_SIZE)
    {
        flashAddress &= 0x00FFFFFF;
        txBuffer[0] = PP;
        txBuffer[1] = (uint8_t) ((flashAddress & 0x00FF0000) >> 16);
        txBuffer[2] = (uint8_t) ((flashAddress & 0x0000FF00) >> 8);
        txBuffer[3] = (uint8_t) (flashAddress & 0xFF);
        SPIOne_TxRxBuffer(txBuffer, rxBuffer, numberOfBytes+OFFSET_BEGIN_DATA);
        success = TRUE;
    }
    else
    {
        success = FALSE;
    }
    return success;
}

static void cmdReadStatusRegister(void)
{
    txBuffer[0] = RDSR;
    SPIOne_TxRxBuffer(txBuffer, rxBuffer, 2);
    while (!(SPIOne_IsTxComplete()))
    {
        ;
    }
    flashStatusRegister.byte = rxBuffer[1];
}

static void cmdWriteStatusRegister(void)
{
    cmdWriteEnable();
    txBuffer[0] = WRSR;
    txBuffer[1] = flashStatusRegister.byte;
    SPIOne_TxRxBuffer(txBuffer, rxBuffer, 2);
}

static void cmdBulkErase(void)
{
    cmdWriteEnable();
    txBuffer[0] = BE;
    SPIOne_TxRxBuffer(txBuffer, rxBuffer, 1);
}

/* Public */

BOOL 
XILFLASH_EraseFlash(void)
{
    BOOL success;

    success = FALSE;
    cmdReadStatusRegister();
    if (flashStatusRegister.WRITE_IN_PROGRESS_BIT == 0)
    {    
        cmdBulkErase();
        success = TRUE; 
    }   

    return success;
}

BOOL 
XILFLASH_ReadDataBytes(uint32_t flashAddress, uint32_t numberOfBytes)
{
    BOOL success;
    
    if (numberOfBytes <= RX_BUFFER_SIZE)
    {
        cmdReadStatusRegister();
        if (flashStatusRegister.WRITE_IN_PROGRESS_BIT == 0)
        {
            flashAddress &= 0x00FFFFFF;
            txBuffer[0] = READ;
            txBuffer[1] = (uint8_t) ((flashAddress & 0x00FF0000) >> 16);
            txBuffer[2] = (uint8_t) ((flashAddress & 0x0000FF00) >> 8);
            txBuffer[3] = (uint8_t) (flashAddress & 0xFF);
            while (!(SPIOne_IsTxComplete()))
            {
                ;
            }
            SPIOne_TxRxBuffer(txBuffer, rxBuffer, numberOfBytes+OFFSET_BEGIN_DATA);
            success = TRUE;
        }
        else
        {
            success = FALSE;
        }
    }
    else
    {
        success = FALSE;
    }
    return success;
}

BOOL 
XILFLASH_WriteDataBytes(uint32_t flashAddress,uint8_t* bufferToTx, uint32_t numberOfBytes)
{
    uint32_t loopIndex;
    BOOL success;

    success = FALSE;
    cmdReadStatusRegister();
    if (flashStatusRegister.WRITE_IN_PROGRESS_BIT == 0)
    {
        // copy data to local buffer
        for (loopIndex = 0; loopIndex < numberOfBytes; loopIndex++)
        {
            txBuffer[loopIndex+OFFSET_BEGIN_DATA] = *bufferToTx;
            bufferToTx++;
        }
        cmdWriteEnable();
        if (cmdProgramPage(flashAddress, numberOfBytes))
        {
            success = TRUE;
        }
    }
    return success;
}

uint8_t* 
XILFLASH_GetRxBuffer(void)
{
    return (rxBuffer+RX_BUFFER_DATA_OFFSET);
}

BOOL 
XILFLASH_ReadWriteComplete(void)
{
    return (SPIOne_IsTxComplete());
}

BOOL  
XILFLASH_UnProtectAllSectors(void)
{
    BOOL success;

    success = FALSE;
    mSet_PROM_WP();     // disable h/w protection
    cmdReadStatusRegister();
    if (flashStatusRegister.WRITE_IN_PROGRESS_BIT == 0)
    {
        flashStatusRegister.BLOCK_PROTECT_BITS = 0;
        cmdWriteStatusRegister();   
        success = TRUE;
    }
    return success;
}

BOOL  
XILFLASH_ProtectAllSectors(void)
{
    BOOL success;

    success = FALSE;
    cmdReadStatusRegister();
    if (flashStatusRegister.WRITE_IN_PROGRESS_BIT == 0)
    {
        flashStatusRegister.BLOCK_PROTECT_BITS = 7;
        cmdWriteStatusRegister();
        mSet_PROM_WP();     // enable h/w protection
        success = TRUE;
    }
    return success;
}

BOOL 
XILFLASH_Select_Flash(uint32_t flashId)
{
    BOOL success;
    
    success = TRUE;
    switch (flashId)
    {
        case 0:
            mClear_PROM_SEL_A();
            mClear_PROM_SEL_B();
            break;
        case 1:
            mSet_PROM_SEL_A();
            mClear_PROM_SEL_B();
            break;
        case 2:
            mClear_PROM_SEL_A();
            mSet_PROM_SEL_B();
            break;
        case 3:
            mSet_PROM_SEL_A();
            mSet_PROM_SEL_B();
            break;
        default:
            success = FALSE;
            break;
    }
    return success;
}
