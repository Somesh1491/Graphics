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

#ifdef _DEBUG

void InitMemSnap();
void MemRecordStart();
void MemRecordStop();
void DisplayMemStatus();

#endif // !_DEBUG


