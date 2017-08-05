#pragma once

#include "lcd.h"

class Button
{
public:
	Button(uint8_t pin);

	void Update();

private:
	const uint8_t _bit;

	uint32_t _time;

	bool _state = true;

	virtual void ButtonHandler() = 0;
};