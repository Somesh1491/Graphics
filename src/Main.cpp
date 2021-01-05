#include "MemorySnap.h"
#include "MathLib.h"
#include<iostream>

struct Test
{
	int** testPtr;
};

int main()
{
	InitMemSnap();

	MemRecordStart();
	{
		Test t;
		t.testPtr = (int**)malloc(sizeof(int*) * 20);

		for (int i = 0; i < 20; i++)
		{
			t.testPtr[i] = (int*)malloc(sizeof(int) * 30);
		}

		for (int i = 0; i < 20; i++)
		{
			free(t.testPtr[i]);
		}

		free(t.testPtr);
	}
	MemRecordStop();
	DisplayMemStatus();
	return 0;
}