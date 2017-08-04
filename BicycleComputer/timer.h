#pragma once

#include "base_timer.h"

class Timer : public BaseTimer
{
public:
	Timer();

private:
	uint8_t _s;
	uint8_t _m;

	void ResetHandler();
	void TimerHandler();
};

