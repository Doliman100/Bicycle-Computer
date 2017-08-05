#include "button.h"

Button::Button(uint8_t pin)
	: _bit(1 << pin)
{}

void Button::Update()
{
	uint32_t time = micros();
	if (time - _time > 1999)
	{
		bool state = PIND & _bit;
		if (_state != state)
		{
			_time = time;
			if (_state = state)
				ButtonHandler();
		}
	}
}