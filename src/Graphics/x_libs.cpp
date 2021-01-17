#include "Graphics/x_libs.h"

extern x_frameBuffer* activeFrameBuffer;
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
				putpixel(j, i, WHITE);
		}
	}
}