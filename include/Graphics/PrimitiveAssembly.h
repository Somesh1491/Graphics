#pragma once

#include "MemoryBuffer.h"
#include "x_enums.h"
#include <iostream>

struct Primitive_Line
{
	int dy, dx;
	int d; //decision parameter
};

void PrimitiveAssemblyBlock();
