#include "BGIWrapper.h"

void x_putpixel(int x, int y, int color)
{
	int y_max = getmaxy();
	putpixel(x, y_max - y, color);
}

void x_line(int x1, int y1, int x2, int y2)
{
	int y_max = getmaxy();
	line(x1, y_max - y1, x2, y_max - y2);
}
