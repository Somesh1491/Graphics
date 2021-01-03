#pragma once

#include <time.h>

struct Timer
{
	void Start();
	void Stop();
	void Reset();

	int valueInMilliSeconds;
};
