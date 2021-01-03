#pragma once

#include <time.h>
#include <assert.h>
#include "Timer.h"

bool isTimerStart;
clock_t start;
clock_t end;
clock_t difference;

void Timer::Start()
{
	isTimerStart = true;
	start = clock();	
}

void Timer::Stop()
{
	/*.................Timer must be started before stop.......................*/
	assert(isTimerStart);

	isTimerStart = false;
	end = clock();

	valueInMilliSeconds = (end - start) * 1000 / CLOCKS_PER_SEC;
}

void Timer::Reset()
{
	isTimerStart = false;
	valueInMilliSeconds = 0;
}
