#include "LEDDriver.h"

static uint16_t currentLEDs;
static uint16_t *LEDAddress;

enum {
	FIRST_LED = 1,
	LAST_LED = 16
};

static uint16_t ledNumberToBit( int LEDNumber ) {
	return (1 << (LEDNumber - 1));
}

static void updateHardware( void ) {
	*LEDAddress = currentLEDs;
}

void LEDDriver_Create( uint16_t *address ) {
	LEDAddress = address;
	currentLEDs = 0;
	updateHardware();
}

void LEDDriver_TurnOn( int LEDNumber ) {
	if( LEDNumber < FIRST_LED || LAST_LED < LEDNumber ) {
		return;
	}
	
	currentLEDs |= ledNumberToBit( LEDNumber );
	updateHardware();
}

void LEDDriver_TurnAllOn( void ) {
	currentLEDs = 0xffff;
	updateHardware();
}

void LEDDriver_TurnAllOff( void ) {
	currentLEDs = 0x0000;
	updateHardware();
}

void LEDDriver_TurnOff( int LEDNumber ) {
	if( LEDNumber < FIRST_LED || LAST_LED < LEDNumber ) {
		return;
	}
	
	currentLEDs &= ~(ledNumberToBit( LEDNumber ));
	updateHardware();
}
