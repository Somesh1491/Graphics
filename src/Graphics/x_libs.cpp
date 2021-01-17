#include "Graphics/x_libs.h"

x_Geometry currentGeometry;
void Draw(x_Geometry geometry)
{
	currentGeometry = geometry;
	WorldToWindowTransform();
}