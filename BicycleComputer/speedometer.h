#pragma once

#include "input.h"
#include "button.h"

class Speedometer : public Input, public Button
{
public:
	Speedometer(LCD &lcd);

	void Update();

private:
	LCD &_lcd;

	// 2.1m длинна колеса
	// 32 прерывания за оборот
	const uint8_t _distance_delta = 65; // 2100mm / 32;
	const uint32_t _time_delta_max = _distance_delta * 36000;
	const uint32_t _time_delta_max_minus = 1 - _time_delta_max;

	uint32_t _distance_mm;
	uint16_t _distance_m;

	uint8_t _speed_00X;
	uint8_t _speed_0X0;
	uint8_t _speed_X00;

	bool _moving;

	void ButtonHandler();
	void InputHandler();
};