#pragma once

#include "speedometer.h"
#include "clock.h"
#include "timer.h"

class Core : public Input
{
public:
	Core();

	void Init();
	void Update();

private:
	Speedometer _speedometer;
	Clock _clock;
	Timer _timer;

	void InputHandler();
};