# pic32-dev

## can_monitor

This is a firmware framework designed for PIC32 that implements a CANopen Application Layer and a real-time CAN monitoring interface.

- Supports reading and writing objects across local registers and FPGA targets using Service Data Object (SDO) requests.
- Captures incoming CAN messages, converts them to ASCII string representations, and streams them over UART for monitoring and debugging.  
- Features a structured object dictionary to manage device configurations, ADC channels, and error status registers.
- Periodically transmits device **heartbeats** incorporating system error register data.

**`CANAppLayer.c`**: Implements the CANopen application layer logic, including sending SDO read/write requests, transmitting heartbeats, filtering messages, and bridging CAN data to UART

**`ObjectDictionary.c`**: Manages the local device's object dictionary, containing standard registers, ADC channels, error flags, and helper functions to get or set register values.

**`CANfunctions.h`**: Defines low-level CAN message buffer structures (standard and extended IDs), FIFO queues, operation modes, and core function prototypes for the CAN interface

**`Uart.h` / `UartCommands.h`**: Referenced by `main.c` for handling UART communication and executing incoming commands (implied by includes)

...

## PIC32MX795

- 80 MHz/105 DMIPS performance
- Program Memory 512 KB Flash and 128 KB RAM
- Integrated 10/100 Mbps Ethernet MAC
- RMII/MII interface to PHY
- Full speed USB, CAN 2.0B
- Dedicated DMA interface for direct access to the entire system RAM

Boards:

- [NU32](https://hades.mech.northwestern.edu/index.php/NU32)
- [dm320004-2](https://www.microchip.com/en-us/development-tool/dm320004-2) 

## PIC32MZ2048EFG144 

- 252 MHz/415 DMIPS performance
- Program Memory 2048 KB Flash and 512 KB RAM
- I2C:5 and UART:6
- Full speed USB (Harmony)

## External


External libraries used in and with the project.

- ZLIB came from the github and was cloned using:

```
    $ git clone https://github.com/madler/zlib.git
    $ ./configure; make test
```

- Unity for command format (http://www.throwtheswitch.org)