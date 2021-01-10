#include "MemorySnap.h"
#include "MathLib.h"
#include<iostream>

int main()
{
	InitMemSnap();

	MemRecordStart();
	{
		x_matrix m1;
		GetRandomMatrix(3, 3, m1);
		print(m1);
		printf("\n");
		x_matrix m2;
		
		GetUpperTriangularMatrix(m1, m2);
		print(m2);
		printf("\n");

		printf("%f", GetDeterminant(m1));

		DeleteMatrix(m1);
		DeleteMatrix(m2);
	}
	MemRecordStop();
	DisplayMemStatus();

	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}