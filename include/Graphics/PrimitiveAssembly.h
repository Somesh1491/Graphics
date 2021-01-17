#pragma once

#include "MemoryBuffer.h"
#include "Rasterizer.h"
#include "x_enums.h"
#include <iostream>

struct PrimitiveLine;
struct PrimitiveLineBuffer;

struct PrimitiveLineBuffer
{
	PrimitiveLine* primitiveLineBufferPtr;
	int lineCount;
};

struct PrimitiveLine
{
	int dy, dx;
	int d; //decision parameter
};

void PrimitiveAssemblyBlock();
