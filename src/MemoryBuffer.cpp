#include "MemoryBuffer.h"

x_vertexBuffer* activeVertexBuffer;
x_frameBuffer* activeFrameBuffer;

x_vertexBuffer* GenVertexBuffer()
{
	x_vertexBuffer* vertexBuffer = (x_vertexBuffer*)malloc(sizeof(x_vertexBuffer));
	activeVertexBuffer = vertexBuffer;
	return vertexBuffer;
}

void ActiveVertexBuffer(x_vertexBuffer* x_vertexBuffer)
{
	activeVertexBuffer = x_vertexBuffer;
}

void VertexBufferData(x_vertexBuffer* vertexBuffer, const int vertexCount, const x_vertex2* vertexData)
{
	vertexBuffer->vertexCount = vertexCount;
	vertexBuffer->vertexBufferPtr = (x_vertex2*)malloc(sizeof(x_vertex2) * vertexCount);

	//Copy Data from data to vertexBuffer
	memcpy(vertexBuffer->vertexBufferPtr, vertexData, sizeof(x_vertex2) * vertexCount);
}

x_frameBuffer* GenFrameBuffer()
{
	x_frameBuffer* frameBuffer = (x_frameBuffer*)malloc(sizeof(x_frameBuffer));
	frameBuffer->pixelBufferPtr = (x_point2**)malloc(sizeof(x_point2*) * SCREEN_WIDTH);

	for (int i = 0; i < SCREEN_WIDTH; i++)
		frameBuffer->pixelBufferPtr[i] = (x_point2*)malloc(sizeof(x_point2) * SCREEN_HEIGHT);

	activeFrameBuffer = frameBuffer;

	return frameBuffer;
}

void DeleteVertexBuffer(x_vertexBuffer* vertexBuffer)
{
	free(vertexBuffer->vertexBufferPtr);
	free(vertexBuffer);
}

void DeleteFrameBuffer(x_frameBuffer* frameBuffer)
{
	for (int i = 0; i < SCREEN_WIDTH; i++)
		free(frameBuffer->pixelBufferPtr[i]);
	
	free(frameBuffer->pixelBufferPtr);
	free(frameBuffer);
}

void Draw(x_Geometry geometry)
{
	switch (geometry)
	{

	case LINE:
		break;
	default:
		break;
	}
}


