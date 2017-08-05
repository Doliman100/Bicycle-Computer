#include "speedometer.h"

Speedometer::Speedometer(LCD &lcd)
	: Input(0)
	, Button(4)
	, _lcd(lcd)
{}

void Speedometer::Update()
{
	Button::Update();

	if (_moving && (Input::_time - micros() < _time_delta_max_minus)) // _time может измениться в любой момент
	{
		_speed_00X = 0;
		_speed_0X0 = 0;
		_speed_X00 = 0;

		_lcd.DrawTextLarge(0, 0);
		_lcd.DrawTextLarge(0, 1);
		_lcd.DrawText('0', 4, 1);

		_moving = false;
	}
}

void Speedometer::ButtonHandler()
{
	_distance_mm = 0;

	_lcd.DrawText("00000", 11, 1);
}

void Speedometer::InputHandler()
{
	// odometer
	if (_distance_m != 99999)
	{
		_distance_mm += _distance_delta;

		uint32_t distance_m = _distance_mm / 1000;
		if (distance_m != _distance_m)
			_lcd.DrawText(_distance_m = distance_m, 11, 1, 5);
	}

	// speedometer
	uint16_t speed = _time_delta_max / _time_delta; // 0.1km/h

	uint8_t digit = speed % 10;
	if (digit != _speed_00X)
		_lcd.DrawText((_speed_00X = digit) + '0', 4, 1);

	digit = (speed /= 10) % 10;
	if (digit != _speed_0X0)
		_lcd.DrawTextLarge(_speed_0X0 = digit, 1);

	digit = (speed /= 10) % 10;
	if (digit != _speed_X00)
		_lcd.DrawTextLarge(_speed_X00 = digit, 0);

	_moving = true;
}