#pragma once

#include "lcd.h"

class BaseTimer
{
public:
	static BaseTimer *_this[2];
	
	static void Init();

	BaseTimer(uint8_t timer);

	void Reset();
	void Interrupt();

private:
	volatile uint16_t *_ocr;

	bool _skip;

	virtual void ResetHandler() = 0;
	virtual void TimerHandler() = 0;
};