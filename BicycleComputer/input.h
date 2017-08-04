#pragma once

#include "lcd.h"

class Input
{
public:
	static Input *_this[2];
	
	static void Init();

	Input(uint8_t interrupt);

	void Interrupt();

protected:
	uint32_t _time;
	uint32_t _time_delta;

private:
	const uint8_t _bit;

	virtual void InputHandler() = 0;
};

