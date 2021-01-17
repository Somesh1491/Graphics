#include "Graphics/PrimitiveAssembly.h"

extern x_transformedVertexBuffer* transformedVertexBuffer;
extern x_Geometry currentGeometry;

Primitive_Line* primitiveLine;

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
}

void LinePrimitiveBlock()
{
	int lineCount = transformedVertexBuffer->vertexCount / 2;

	primitiveLine = (Primitive_Line*)malloc(sizeof(Primitive_Line) * lineCount);
	
	for (int i = 0; i < lineCount; i++)
	{
		x_point2 p1 = transformedVertexBuffer->transformedVertexBufferPtr[i*2];
		x_point2 p2 = transformedVertexBuffer->transformedVertexBufferPtr[i*2 + 1];

		primitiveLine->dy = p2.y - p1.y;
		primitiveLine->dx = p2.x - p1.x;
		primitiveLine->d = 2 * primitiveLine->dy - primitiveLine->dx;
	}
}
