#include "MemoryBuffer.h"

void GenFrameBuffer(FrameBuffer* frameBuffer)
{
	frameBuffer->pixelBufferPtr = (Point2**)malloc(sizeof(Point2*) * SCREEN_WIDTH);

	for (int i = 0; i < SCREEN_WIDTH; i++)
	{
		frameBuffer->pixelBufferPtr[i] = (Point2*)malloc(sizeof(Point2) * SCREEN_HEIGHT);
	}
}

void DeleteFrameBuffer(FrameBuffer & frameBuffer)
{
	for (int i = 0; i < SCREEN_WIDTH; i++)
		free(frameBuffer.pixelBufferPtr[i]);
	
	free(frameBuffer.pixelBufferPtr);
}


