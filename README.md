# pic32-dev

APP layer (CANopen)

- CANAPP_Request to read or write Object.
- CANAPP_ProcessRxMessage

Object Dictionary

 - OBJECTDICT_API_set or get Object.

 CAN functions

 - CAN1ProcessRxMessages
 - CAN1TxMessage

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