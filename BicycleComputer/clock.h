#pragma once

#include <Wire.h>

#include "base_timer.h"

class Clock : public BaseTimer
{
public:
	Clock(LCD &lcd);

	void Init();
	void Update();

private:
	LCD &_lcd;

	const uint8_t _address = 0x68;

	uint8_t _s;
	uint8_t _m;
	uint8_t _h;

	uint32_t _time; // последняя синхронизация

	uint8_t BCD2Dec(uint8_t number);

	void Sync();

	void TimerHandler();
};