#include "Graphics/x_libs.h"

extern x_frameBuffer* activeFrameBuffer;
x_ortho* currentOrtho;
x_Geometry currentGeometry;
void Draw(x_Geometry geometry)
{
	currentGeometry = geometry;
	WorldToWindowTransform();

	/*.........................DRAW FRAME BUFFER DATA......................*/
	for (int i = 0; i < activeFrameBuffer->height; i++)
	{
		for (int j = 0; j < activeFrameBuffer->width; j++)
		{
			if (activeFrameBuffer->pixelPtr[i][j].pixelFlag == true)
				x_putpixel(j, i, WHITE);
		}
	}
}

void SetOrtho(int left, int right, int bottom, int top)
{
	currentOrtho = (x_ortho*)malloc(sizeof(x_ortho));
	currentOrtho->left = left;
	currentOrtho->right = right;
	currentOrtho->bottom = bottom;
	currentOrtho->top = top;

	//Left vertical line
	x_line(left, bottom, left, top);
	//right vertical line
	x_line(right, bottom, right, top);
	//bottom horizontal line
	x_line(left, bottom, right, bottom);
	//top horizontal line
	x_line(left, top, right, top);
}
