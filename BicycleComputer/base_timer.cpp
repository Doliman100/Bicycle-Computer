#include "base_timer.h"

BaseTimer *BaseTimer::_this[2];

ISR(TIMER1_COMPA_vect)
{
	BaseTimer::_this[0]->Interrupt();
}

ISR(TIMER1_COMPB_vect)
{
	BaseTimer::_this[1]->Interrupt();
}

void BaseTimer::Init()
{
	TCCR1A = 0b00000010; // 2 независимых таймера с частотой 1Гц
	TCCR1B = 0b00011101; // Быстрый ШИМ, верхняя граница ICR1, предделитель 1024
	ICR1 = 15624; // F_CPU / (1Hz * 1024) - 1
	TCNT1 = 0;
	TIFR1 = 0b00000110;
	TIMSK1 = 0b00000110;
}

BaseTimer::BaseTimer(uint8_t timer)
	: _ocr((volatile uint16_t *)(0x88 | timer << 1))
{
	_this[timer] = this;
}

void BaseTimer::Reset()
{
	ResetHandler();

	if (*_ocr > TCNT1) // пропуск запомненного прерывания
		_skip = true;
	*_ocr = TCNT1; // независимый сброс таймера
}

void BaseTimer::Interrupt()
{
	if (_skip)
		_skip = false;
	else
		TimerHandler();
}