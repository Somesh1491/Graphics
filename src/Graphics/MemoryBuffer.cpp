#include "Graphics/MemoryBuffer.h"

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
	frameBuffer->pixelPtr = (x_BitmapPixel**)malloc(sizeof(x_BitmapPixel*) * SCREEN_HEIGHT);

	for (int i = 0; i < SCREEN_HEIGHT; i++)
		frameBuffer->pixelPtr[i] = (x_BitmapPixel*)malloc(sizeof(x_BitmapPixel) * SCREEN_WIDTH);

	frameBuffer->width = SCREEN_WIDTH;
	frameBuffer->height = SCREEN_HEIGHT;

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
	for (int i = 0; i < SCREEN_HEIGHT; i++)
		free(frameBuffer->pixelPtr[i]);
	
	free(frameBuffer->pixelPtr);
	free(frameBuffer);
}

void DisplayBitMapFrameBuffer()
{
	for (int i = 0; i < activeFrameBuffer->height; i++)
	{
		for (int j = 0; j < activeFrameBuffer->width; j++)
		{
			if (activeFrameBuffer->pixelPtr[i][j].pixelFlag == true)
				std::cout << j << " " << i << std::endl;
		}
	}
}


