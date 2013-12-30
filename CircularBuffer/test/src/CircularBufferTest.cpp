extern "C" {
#include "CircularBuffer.h"
}

#include <gtest/gtest.h>

TEST( CircularBufferTest, InitializeWithSizeZero ) {
	CircularBuffer pCircularBuffer;
	
	CircularBuffer_Init( pCircularBuffer, 0 );
	EXPECT_EQ( NULL, pCircularBuffer );
}

TEST( CircularBufferTest, InitializeAndClear ) {
	CircularBuffer pCircularBuffer;

	CircularBuffer_Init( pCircularBuffer, 10 );
	EXPECT_NE( NULL, pCircularBuffer );
	//EXPECT_NE( pCircularBuffer->data, NULL );

	CircularBuffer_Clear( pCircularBuffer );
	EXPECT_EQ( pCircularBuffer, NULL );
	//EXPECT_EQ( NULL, pCircularBuffer->data );
}

int main( int argc, char *argv[] ) {
	::testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}
