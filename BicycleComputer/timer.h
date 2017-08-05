#pragma once

#include "base_timer.h"
#include "button.h"

class Timer : public BaseTimer, public Button
{
public:
	Timer(LCD &lcd);

private:
	LCD &_lcd;

	uint8_t _s;
	uint8_t _m;

	void ButtonHandler();
	void TimerHandler();
};