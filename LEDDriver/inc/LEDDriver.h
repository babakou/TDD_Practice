#ifndef _LEDDRIVER_H_
#define _LEDDRIVER_H_

#include <stdint.h>

void LEDDriver_Create( uint16_t * );
void LEDDriver_TurnOn( int );
void LEDDriver_TurnOff( int );
void LEDDriver_TurnAllOn( void );
void LEDDriver_TurnAllOff( void );

#endif
