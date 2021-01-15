#pragma once

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#include <string.h>
#include <stdlib.h>

struct x_point2;
struct x_vertex2;
struct x_vertexBuffer;
struct x_frameBuffer;

struct x_point2
{
	int x, y;
};

struct x_vertex2 
{
	float x, y;
};

struct x_vertexBuffer
{
	x_vertex2* vertexBufferPtr;
	int vertexCount;
};

struct x_frameBuffer
{
	x_point2** pixelBufferPtr;
	int size;
};

void GenVertexBuffer(x_vertexBuffer* vertexBuffer, int vertexCount, x_vertex2* data);
void GenFrameBuffer(x_frameBuffer* frameBuffer);
void DeleteVertexBuffer(x_vertexBuffer& vertexBuffer);
void DeleteFrameBuffer(x_frameBuffer& frameBuffer);