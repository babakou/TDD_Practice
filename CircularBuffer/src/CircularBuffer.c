#include "CircularBuffer.h"
#include <stdlib.h>

struct CircularBufferStruct {
	int size;
	int *data;
};

void CircularBuffer_Init( CircularBuffer pCB, int bufSize ) {
	pCB = (CircularBuffer)malloc( sizeof(struct CircularBufferStruct) );
	pCB->data = (int *)calloc( bufSize, bufSize * sizeof(int) );

	pCB->size = bufSize;

	return;
}

void CircularBuffer_Clear( CircularBuffer pCB ) {
	free( pCB->data ); pCB->data = NULL;
	free( pCB ); pCB = NULL;
}
