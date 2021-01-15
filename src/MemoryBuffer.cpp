#include "MemoryBuffer.h"

void GenVertexBuffer(x_vertexBuffer* vertexBuffer, int vertexCount,  x_vertex2* data)
{
	vertexBuffer->vertexCount = vertexCount;
	vertexBuffer->vertexBufferPtr = (x_vertex2*)malloc(sizeof(x_vertex2) * vertexCount);

	//Copy Data from data to vertexBuffer
	memcpy(vertexBuffer->vertexBufferPtr, data, sizeof(x_vertex2) * vertexCount);
}

void GenFrameBuffer(x_frameBuffer* frameBuffer)
{
	frameBuffer->pixelBufferPtr = (x_point2**)malloc(sizeof(x_point2*) * SCREEN_WIDTH);

	for (int i = 0; i < SCREEN_WIDTH; i++)
	{
		frameBuffer->pixelBufferPtr[i] = (x_point2*)malloc(sizeof(x_point2) * SCREEN_HEIGHT);
	}
}

void DeleteVertexBuffer(x_vertexBuffer& vertexBuffer)
{
	free(vertexBuffer.vertexBufferPtr);
}

void DeleteFrameBuffer(x_frameBuffer & frameBuffer)
{
	for (int i = 0; i < SCREEN_WIDTH; i++)
		free(frameBuffer.pixelBufferPtr[i]);
	
	free(frameBuffer.pixelBufferPtr);
}


