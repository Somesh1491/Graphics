#pragma once

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#include <stdlib.h>

struct Point2
{
	int x, y;
};

struct FrameBuffer
{
	Point2** pixelBufferPtr;
	int size;
};

void GenFrameBuffer(FrameBuffer* frameBuffer);
void DeleteFrameBuffer(FrameBuffer& frameBuffer);