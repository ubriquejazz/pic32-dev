#include "HardwareSetup.h"

void HWAPI_InitialiseHardware(void)
{
    // Disable Parallel Master Port
    PMCON = 0;
    // GPIO Setup
    TRISDCLR = 0x30;    // Only needed for Explorer 16 board so to diable the LCD
    PORTDCLR = 0x10;    
    TRISACLR = 0x01;
    TRISFSET = 0x10;    // Set UART 3A Rx as input
    TRISESET = 0x03;    // set PE0, PE1 as inputs    
}
