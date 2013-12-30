extern "C" {
#include "LEDDriver.h"
}
	
#include <gtest/gtest.h>

static uint16_t virtualLEDs;

class LEDDriver : public ::testing::Test {
protected:
	virtual void SetUp() {
		LEDDriver_Create( &virtualLEDs );
	}

	virtual void TearDown() {
		
	}
};


TEST_F( LEDDriver, LEDsOffAfterCreate ) {
	uint16_t virtualLEDs = 0xffff;
	LEDDriver_Create( &virtualLEDs );
	EXPECT_EQ( 0, virtualLEDs );
}

TEST_F( LEDDriver, TurnOnLED1 ) {
	//uint16_t virtualLEDs;
	//LEDDriver_Create( &virtualLEDs );
	LEDDriver_TurnOn( 1 );
	EXPECT_EQ( 1, virtualLEDs );
}

TEST_F( LEDDriver, TurnOffLED1 ) {
	//uint16_t virtualLEDs;
	//LEDDriver_Create( &virtualLEDs );
	LEDDriver_TurnOn( 1 );
	LEDDriver_TurnOff( 1 );
	EXPECT_EQ( 0, virtualLEDs );
}

TEST_F( LEDDriver, TurnOnMultipleLEDs ) {
	LEDDriver_TurnOn( 8 );
	LEDDriver_TurnOn( 9 );
	EXPECT_EQ( 0x0180, virtualLEDs );
}

TEST_F( LEDDriver, TurnOffAnyLED ) {
	LEDDriver_TurnOn( 8 );
	LEDDriver_TurnOn( 9 );
	LEDDriver_TurnOff( 8 );
	EXPECT_EQ( 0x0100, virtualLEDs );
}

TEST_F( LEDDriver, LEDsIsNotReadble ) {
	virtualLEDs = 0xffff;
	LEDDriver_TurnOn( 8 );
	EXPECT_EQ( 0x0080, virtualLEDs );
}

TEST_F( LEDDriver, UpperAndLowerBounds ) {
	LEDDriver_TurnOn( 1 );
	LEDDriver_TurnOn( 16 );
	EXPECT_EQ( 0x8001, virtualLEDs );
}

TEST_F( LEDDriver, AllLEDsOn ) {
	LEDDriver_TurnAllOn();
	EXPECT_EQ( 0xffff, virtualLEDs );
}

TEST_F( LEDDriver, AllLEDsOff ) {
	LEDDriver_TurnAllOn();
	LEDDriver_TurnAllOff();
	EXPECT_EQ( 0x0000, virtualLEDs );
}

TEST_F( LEDDriver, OutOfBoundsTurningOnChangesNothing ) {
	LEDDriver_TurnOn( 0 );
	LEDDriver_TurnOn( 17 );
	LEDDriver_TurnOn( -1 );
	LEDDriver_TurnOn( 100 );
	EXPECT_EQ( 0x0000, virtualLEDs );
}

TEST_F( LEDDriver, OutOfBoundsTurningOffChangesNothing ) {
	LEDDriver_TurnAllOn();
	LEDDriver_TurnOff( 0 );
	LEDDriver_TurnOff( 17 );
	LEDDriver_TurnOff( -1 );
	LEDDriver_TurnOff( 100 );
	EXPECT_EQ( 0xffff, virtualLEDs );
}

int main( int argc, char *argv[] ) {
	::testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}
