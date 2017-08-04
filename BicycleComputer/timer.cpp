#include "timer.h"

Timer::Timer()
	: BaseTimer(1)
{}

void Timer::ResetHandler()
{
	_m = 0;
	_s = 0;

	LCD.DrawText("00", 11, 0);
	LCD.DrawText("00", 14, 0);
}

void Timer::TimerHandler()
{
	if (_s != 59)
		LCD.DrawText(++_s, 14, 0, 2);
	else if (_m != 99)
	{
		_s = 0;
		
		LCD.DrawText(++_m, 11, 0, 2);
		LCD.DrawText("00", 14, 0);
	}
}

