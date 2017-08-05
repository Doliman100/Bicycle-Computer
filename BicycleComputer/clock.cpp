#include "clock.h"

Clock::Clock(LCD &lcd)
	: BaseTimer(0)
	, _lcd(lcd)
{}

void Clock::Init()
{
	Wire.begin();

	Sync();
}

void Clock::Update()
{
	if (_time - millis() < 4287767296) // каждые 2 часа // 4294967296 - 7200000
	{
		Sync();
		Reset();
	}
}

uint8_t Clock::BCD2Dec(uint8_t number)
{
	return number - (number >> 4) * 6; // взято из RTClib от Adafruit
}

void Clock::Sync()
{
	_time = millis() % 86400000;

	Wire.requestFrom(_address, 3, 0, 1, true);
	
	_s = BCD2Dec(Wire.read() & 0b01111111);

	_lcd.DrawText(_m = BCD2Dec(Wire.read()), 8, 0, 2);
	_lcd.DrawText(_h = BCD2Dec(Wire.read()), 5, 0, 2);
}

void Clock::TimerHandler()
{
	if (_s != 59)
		_s++;
	else if (_m != 59)
	{
		_s = 0;

		_lcd.DrawText(++_m, 8, 0, 2);
	}
	else if (_h != 23)
	{
		_s = 0;
		_m = 0;

		_lcd.DrawText(++_h, 5, 0, 2);
		_lcd.DrawText("00", 8, 0);
	}
	else
	{
		_s = 0;
		_m = 0;
		_h = 0;

		_lcd.DrawText("00", 5, 0);
		_lcd.DrawText("00", 8, 0);
	}
}