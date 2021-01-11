#include "MemorySnap.h"
#include "MathLib.h"
#include<iostream>

int main()
{
	InitMemSnap();

	MemRecordStart();
	{		
		float arr1[] = {1, 0, 1 };
		float arr2[] = { 0, 1, 0 };
		float arr3[] = { 0, 0, 1 };

		x_matrix m1;
		CreateMatrix(3, 3, m1);

		SetRow(0, m1, arr1);
		SetRow(1, m1, arr2);
		SetRow(2, m1, arr3);
	

		x_matrix m2;
		GetInverseMatrix(m1, m2);

		print(m1);
		printf("\n");
		print(m2);
		printf("\n");

		DeleteMatrix(m1);
		DeleteMatrix(m2);
	}
	MemRecordStop();
	DisplayMemStatus();

	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}