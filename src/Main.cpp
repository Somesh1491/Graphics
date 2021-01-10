#include "MemorySnap.h"
#include "MathLib.h"
#include<iostream>

int main()
{
	InitMemSnap();

	MemRecordStart();
	{		
		float arr1[] = {5, 3};
		float arr2[] = { 2, 7 };

		x_matrix m1;
		GetRandomMatrix(4, 4, m1);
	
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