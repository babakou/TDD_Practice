#ifndef _CIRCULARBUFFER_
#define _CIRCULARBUFFER_

typedef struct CircularBufferStruct * CircularBuffer;

void CircularBuffer_Init( CircularBuffer CBHead, int BufferSize );
void CircularBuffer_Clear( CircularBuffer CBHead );

#endif
