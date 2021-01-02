#include "Line.h"
//#include "Math.h"

void PlotPoint(int x, int y);

void PlotPoint(int x, int y)
{
	putpixel(x, y, WHITE);
	std::cout << x << " " << y << std::endl;
}

/*Matrix MatrixFor1stOctant()
{
	return CreateMatrixIdentity(2);
}*/

/*Matrix MatrixFor2ndOctant()
{
	Matrix matrix = CreateMatrixIdentity(2);
	matrix[0][0] = 0;
	matrix[0][1] = 1;
	matrix[1][0] = 1;
	matrix[1][1] = 0;
	
	return matrix;
}*/