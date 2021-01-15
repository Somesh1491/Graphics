#include "Graphics/Line.h"

void PlotPoint(int x, int y);

void PlotPoint(int x, int y)
{
	putpixel(x, y, WHITE);
}

void Line(int x1, int y1, int x2, int y2)
{
}

void MidPoint_Algorithm(int x1, int y1, int x2, int y2)
{
	int x = x1;
	int y = y1;
	
	int dy = y2 - y1;
	int dx = x2 - x1;	

	int d = 2 * dy - dx;
	int delta_E = 2 * dy;
	int delta_NE = 2 * (dy - dx);
}