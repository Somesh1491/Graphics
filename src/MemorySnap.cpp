#include "MemorySnap.h"

bool isRecordingStarted = false;
_CrtMemState mem_old;
_CrtMemState mem_new;
_CrtMemState mem_diff;

#ifdef _DEBUG

void InitMemSnap()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}

void MemRecordStart()
{
	assert(!isRecordingStarted);

	_CrtMemCheckpoint(&mem_old);
}

void MemRecordStop()
{
	_CrtMemCheckpoint(&mem_new);
}

void DisplayMemStatus()
{
	if (_CrtMemDifference(&mem_diff, &mem_old, &mem_new))
	{
		std::cout << "Memory Leaked: " << mem_diff.lTotalCount << " Bytes" << std::endl;
	}
}

#endif // !_DEBUG
