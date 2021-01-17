#include "Graphics\Rasterizer.h"

extern PrimitiveLineBuffer* primitiveLineBuffer;
extern x_transformedVertexBuffer* transformedVertexBuffer;
extern x_frameBuffer* activeFrameBuffer;
extern x_Geometry currentGeometry;

void LineDraw(int x1, int x2, int y1, int y2, int dy, int dx, int d);

void RasterizationBlock()
{
	switch (currentGeometry)
	{
	case x_Geometry::X_LINE:
		
		for (int i = 0; i < primitiveLineBuffer->lineCount; i++)
		{
			int d = primitiveLineBuffer->primitiveLineBufferPtr[i].d;
			int dx = primitiveLineBuffer->primitiveLineBufferPtr[i].dx;
			int dy = primitiveLineBuffer->primitiveLineBufferPtr[i].dy;

			//Extract vertices
			int x1 = transformedVertexBuffer->transformedVertexBufferPtr[i * 2].x;
			int y1 = transformedVertexBuffer->transformedVertexBufferPtr[i * 2].y;

			int x2 = transformedVertexBuffer->transformedVertexBufferPtr[i * 2 + 1].x;
			int y2 = transformedVertexBuffer->transformedVertexBufferPtr[i * 2 + 1].y;

			LineDraw(x1, x2, y1, y2, dy, dx, d);
		}

		break;
	default:
		break;
	}
}

void LineDraw(int x1, int x2, int y1, int y2, int dy, int dx, int d)
{
	int x = x1; int y = y1;
	activeFrameBuffer->pixelPtr[y][x].pixelFlag = true;

	int delta_E = 2 * dy;
	int delta_NE = 2 * (dy - dx);

	while (x < x2)
	{
		if (d <= 0) // Choose East Pixel
			d += delta_E;

		else        // Choose North East Pixel
		{
			d += delta_NE;
			y++;
		}

		x++;
		activeFrameBuffer->pixelPtr[y][x].pixelFlag = true;
	}
}