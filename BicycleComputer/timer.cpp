#include "timer.h"

Timer::Timer(LCD &lcd)
	: BaseTimer(1)
	, Button(5)
	, _lcd(lcd)
{}

void Timer::ButtonHandler()
{
	_m = 0;
	_s = 0;

	_lcd.DrawText("00", 11, 0);
	_lcd.DrawText("00", 14, 0);

	Reset();
}

void Timer::TimerHandler()
{
	if (_s != 59)
		_lcd.DrawText(++_s, 14, 0, 2);
	else if (_m != 99)
	{
		_s = 0;
		
		_lcd.DrawText(++_m, 11, 0, 2);
		_lcd.DrawText("00", 14, 0);
	}
}