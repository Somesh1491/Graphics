#include "MemorySnap.h"
#include "MathLib.h"
#include<iostream>

int main()
{
	InitMemSnap();

	MemRecordStart();
	{
		Matrix m1 = GetRandomMatrix(3, 4);
		Matrix m2 = GetRandomMatrix(4, 3);
		VectorN v1 = GetRandomVector(3);
		VectorN v2 = GetRandomVector(4);

		Matrix m3 = m1 * m2;
		VectorN v3 = m2 * v1;

		print(m2);
		printf("\n");
		print(v1);
		printf("\n");
		print(v3);
		printf("\n");

		DeleteVector(v1);
		DeleteVector(v2);
		DeleteVector(v3);
		DeleteMatrix(m3);
		DeleteMatrix(m1);
		DeleteMatrix(m2);
	}
	MemRecordStop();
	DisplayMemStatus();

	MemRecordStart();
	{
		
	}
	MemRecordStop();
	DisplayMemStatus();

	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}