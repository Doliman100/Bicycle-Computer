#include "clock.h"

Clock::Clock()
	: BaseTimer(0)
{}

void Clock::Init()
{
	Wire.begin();

	ResetHandler();
}

uint8_t Clock::BCD2Dec(uint8_t number)
{
	return number - (number >> 4) * 6; // взято из RTClib от Adafruit
}

void Clock::ResetHandler()
{
	_time = millis() % 86400000;

	Wire.requestFrom(_address, 3, 0, 1, true);
	
	_s = BCD2Dec(Wire.read() & 0b01111111);

	LCD.DrawText(_m = BCD2Dec(Wire.read()), 8, 0, 2);
	LCD.DrawText(_h = BCD2Dec(Wire.read()), 5, 0, 2);
}

void Clock::TimerHandler()
{
	if (millis() - _time > 7199999)
		Reset();
	else if (_s != 59)
		_s++;
	else if (_m != 59)
	{
		_s = 0;

		LCD.DrawText(++_m, 8, 0, 2);
	}
	else if (_h != 23)
	{
		_s = 0;
		_m = 0;

		LCD.DrawText(++_h, 5, 0, 2);
		LCD.DrawText("00", 8, 0);
	}
	else
	{
		_s = 0;
		_m = 0;
		_h = 0;

		LCD.DrawText("00", 5, 0);
		LCD.DrawText("00", 8, 0);
	}
}

