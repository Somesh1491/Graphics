#pragma once

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#include <assert.h>
#include <iostream>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif


bool isRecordingStarted = false;
_CrtMemState mem_old;
_CrtMemState mem_new;
_CrtMemState mem_diff;


inline void InitMemSnap()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}

inline void MemRecordStart()
{
	assert(!isRecordingStarted);

	_CrtMemCheckpoint(&mem_old);
}

inline void MemRecordStop()
{
	_CrtMemCheckpoint(&mem_new);
}

inline void DisplayMemStatus()
{
	if (_CrtMemDifference(&mem_diff, &mem_old, &mem_new))
	{
		std::cout << "Memory Leaked: " << mem_diff.lTotalCount << " Bytes" << std::endl;
	}
}