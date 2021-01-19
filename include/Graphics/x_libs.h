#pragma once

#include "VertexShader.h"
#include "BGIWrapper.h"
#include "x_enums.h"

struct x_ortho
{
	int left;
	int right;
	int bottom;
	int top;
};

void Draw(x_Geometry geometry);
void SetOrtho(int left, int right, int bottom, int top);