//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "ble_com.h"
#include "gate.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

UnbufferedSerial uartBle(PD_5, PD_6, 115000);
DigitalOut led_3(LED3);


//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

static char bleComCharRead();

//=====[Implementations of public functions]===================================

void bleComUpdate()
{
    char receivedChar = bleComCharRead();
    if( receivedChar != '\0' ) {
        switch (receivedChar) {
            case 'U': 
                led_3 = ON;
                delay(1000);
                led_3 = OFF;
                break;    //@Nico
            case '@': 
                led_3 = ON;
                delay(1000);
                led_3 = OFF;
                break;    //@Nico
            case 'O': gateOpen(); break;
            case 'C': gateClose(); break;
        }
    }
}

void bleComStringWrite( const char* str )
{
    uartBle.write( str, strlen(str) );
}

//=====[Implementations of private functions]==================================

static char bleComCharRead()
{
    char receivedChar = '\0';
    if( uartBle.readable() ) {
        uartBle.read(&receivedChar,1);
    }
    return receivedChar;
}