#pragma once

#include "speedometer.h"
#include "clock.h"
#include "timer.h"

class Core
{
public:
	Core();

	void Init();
	void Update();

private:
	LCD _lcd;
	Speedometer _speedometer;
	Clock _clock;
	Timer _timer;
};