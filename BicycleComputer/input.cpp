#include "input.h"

Input *Input::_this[2];

ISR(INT0_vect)
{
	Input::_this[0]->Interrupt();
}

ISR(INT1_vect)
{
	Input::_this[1]->Interrupt();
}

void Input::Init()
{
	EICRA = 0b00001111;
	EIFR = 0b00000011;
	EIMSK = 0b00000011;
}

Input::Input(uint8_t interrupt)
	: _bit(4 << interrupt)
{
	_this[interrupt] = this;
}

void Input::Interrupt()
{
	uint32_t time = micros();
	_time_delta = time - _time;
	if (_time_delta > 2000)
	{
		_time = time;
		_delay_loop_2(8000);

		if (PIND & _bit)
			InputHandler();
	}
}

