#include "MemorySnap.h"
#include "MathLib.h"
#include<iostream>

int main()
{
	InitMemSnap();

	MemRecordStart();
	{
		Matrix m1 = CreateMatrix(3, 4);
		Matrix m2 = CreateMatrix(4, 4);
		VectorN v1 = GetRandomVector(4);
		
		float arr1[] = { 2, 5, 3, 1 };
		float arr2[] = { 3, 9, 6, 2 };
		float arr3[] = { 4, 2, 1, 4 };

		SetRow(0, m1, arr1);
		SetRow(1, m1, arr2);
		SetRow(2, m1, arr3);

		float arr11[] = { 2, 5, 3, 1};
		float arr12[] = { 3, 9, 6, 2};
		float arr13[] = { 4, 2, 1, 3};
		float arr14[] = { 2, 1, 9, 4};

		SetColumn(0, m2, arr11);
		SetColumn(1, m2, arr12);
		SetColumn(2, m2, arr13);
		SetColumn(3, m2, arr14);

		print(m1);
		//printf("\n");
		//print(v1);
		//printf("\n");
		//VectorN v2 = m1 * v1;
		//print(v2);

		DeleteVector(v1);
		//DeleteVector(v2);
		DeleteMatrix(m1);
		DeleteMatrix(m2);
			/*VectorN v1 = GetRandomVector(4);
			//print(v1);
			DeleteVector(v1);
			Matrix m1 = CreateMatrix(3, 4);
			//print(m1);
			DeleteMatrix(m1);*/
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