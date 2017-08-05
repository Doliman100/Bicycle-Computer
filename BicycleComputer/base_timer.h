#pragma once

#include "lcd.h"

class BaseTimer
{
public:
	static BaseTimer *_this[2];
	
	static void Init();

	BaseTimer(uint8_t timer);

	void Interrupt();

protected:
	void Reset();

private:
	volatile uint16_t &_ocr;

	bool _skip;

	virtual void TimerHandler() = 0;
};