#include "Graphics/PrimitiveAssembly.h"

extern x_transformedVertexBuffer* transformedVertexBuffer;
extern x_Geometry currentGeometry;

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
}
