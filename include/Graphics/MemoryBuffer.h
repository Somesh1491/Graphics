#pragma once

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#include <string.h>
#include <stdlib.h>
#include <iostream>

struct x_point2;
struct x_vertex2;
struct x_vertexBuffer;
struct x_transformedVertexBuffer;
struct x_frameBuffer;
struct x_BitmapPixel;

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

struct x_transformedVertexBuffer
{
	x_point2* transformedVertexBufferPtr;
	int vertexCount;
};

struct x_BitmapPixel
{
	bool pixelFlag;
};

struct x_frameBuffer
{
	x_BitmapPixel** pixelPtr;
	int width;
	int height;
};

x_vertexBuffer* GenVertexBuffer();
void ActiveVertexBuffer(x_vertexBuffer* x_vertexBuffer);
void VertexBufferData(x_vertexBuffer* vertexBuffer, const int vertexCount, const x_vertex2* vertexData);
x_transformedVertexBuffer* GenTransformedVertexBuffer();
x_frameBuffer* GenFrameBuffer();
void DeleteVertexBuffer(x_vertexBuffer* vertexBuffer);
void DeleteFrameBuffer(x_frameBuffer* frameBuffer);
void DisplayBitMapFrameBuffer();