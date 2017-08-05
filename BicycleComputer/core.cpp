#include "core.h"

// pinout
// PC5	SCL
// PC4	SDA
// PB5	Register Select
// PB4	Enable
// PB3	Data 7
// PB2	Data 6
// PB1	Data 5
// PB0	Data 4
// PD5	Reset Timer
// PD4	Reset Odometer
// PD2	Sensor

Core::Core()
	: _speedometer(_lcd)
	, _clock(_lcd)
	, _timer(_lcd)
{}

void Core::Init()
{
	DDRD = 0b00000000; // настройка пинов
	DDRB = 0b00111111;
	DDRC = 0b00000000;
	PORTD = 0b11111100; // включаем везде подтягивающие резисторы
	PORTB = 0b00000000;
	PORTC = 0b00111111;
	
	_lcd.Init();
	_clock.Init();

	Input::Init();
	BaseTimer::Init();
}

void Core::Update()
{
	_speedometer.Update();
	_clock.Update();
	_timer.Update();
}