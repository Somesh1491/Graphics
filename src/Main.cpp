#include <iostream>
#include "MathLib.h"

int main()
{
	Matrix m1 = GetRandomMatrix(100, 100);
	Matrix m2 = GetRandomMatrix(100, 100);
	
	//print(m1);
	//printf("\n");

	//print(m2);
	

	Matrix m3 = m1 * m2;

	system("pause");
	return -1;
}