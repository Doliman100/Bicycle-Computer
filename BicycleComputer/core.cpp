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
// PD3	Button
// PD2	Sensor

Core::Core()
	: Input(1)
{}

void Core::Init()
{
	DDRD = 0b00000000; // настройка пинов
	DDRB = 0b00111111;
	DDRC = 0b00000000;
	PORTD = 0b11111100; // включаем везде подтягивающие резисторы
	PORTB = 0b00000000;
	PORTC = 0b00111111;
	
	LCD.Init();

	_clock.Init();

	Input::Init();
	BaseTimer::Init();
}

void Core::Update()
{
	_speedometer.Update();
}

void Core::InputHandler()
{
	_speedometer.Reset();
	_timer.Reset();
}

