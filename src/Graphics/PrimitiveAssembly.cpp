#include "Graphics/PrimitiveAssembly.h"

extern x_transformedVertexBuffer* transformedVertexBuffer;
extern x_Geometry currentGeometry;

PrimitiveLineBuffer* primitiveLineBuffer;

void LinePrimitiveBlock();

void PrimitiveAssemblyBlock()
{
	switch (currentGeometry)
	{
	case x_Geometry::X_LINE:
		LinePrimitiveBlock();
		break;
	default:
		break;
	}

	RasterizationBlock();
}

void LinePrimitiveBlock()
{
	int lineCount = transformedVertexBuffer->vertexCount / 2;

	primitiveLineBuffer = (PrimitiveLineBuffer*)malloc(sizeof(PrimitiveLineBuffer));
	primitiveLineBuffer->lineCount = lineCount;
	
	primitiveLineBuffer->primitiveLineBufferPtr = (PrimitiveLine*)malloc(sizeof(PrimitiveLine) * lineCount);

	for (int i = 0; i < lineCount; i++)
	{
		x_point2 p1 = transformedVertexBuffer->transformedVertexBufferPtr[i*2];
		x_point2 p2 = transformedVertexBuffer->transformedVertexBufferPtr[i*2 + 1];

		int dy = primitiveLineBuffer->primitiveLineBufferPtr[i].dy = p2.y - p1.y;
		int dx = primitiveLineBuffer->primitiveLineBufferPtr[i].dx = p2.x - p1.x;
		
		
		primitiveLineBuffer->primitiveLineBufferPtr[i].d = 2 * dy - dx;
	}
}
