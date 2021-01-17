#include "Graphics/VertexShader.h"

extern x_transformedVertexBuffer* transformedVertexBuffer;
void WorldToWindowTransform()
{
	transformedVertexBuffer = GenTransformedVertexBuffer();

	PrimitiveAssemblyBlock();
}
