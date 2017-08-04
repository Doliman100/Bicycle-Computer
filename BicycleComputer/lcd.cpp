#include "lcd.h"

class LCD LCD;

void LCD::Init()
{
	delay(40);

	SendDataH(0b0011);
	delayMicroseconds(4100);

	SendDataH(0b0011);
	delayMicroseconds(100);

	SendDataH(0b0011);
	SendDataH(0b0010);
	
	SendData(0b00101000); // 4bit, 2 line, 5x8
	SendData(0b00001100); // Display, NoCursor, NoBlink
	SendData(0b00000110); // AC++, NoShift

	SendData(0b00000010); // Home
	delayMicroseconds(1520);

	// display
	DrawTextLarge(0, 0);
	DrawTextLarge(0, 1);

	DrawText("\010\011\014\015 00:00 00:00", 0, 0);
	DrawText("\012\013\016\0170 km/h 00000", 0, 1);
}

void LCD::SendDataH(uint8_t data)
{
	PORTB |= 0b00010000 | data;
	_delay_loop_1(1);
	PORTB &= 0b11100000;

	_delay_loop_2(144); // 4 * us
}

void LCD::SendData(uint8_t data)
{
	SendDataH(data >> 4);		// H
	SendDataH(data & 0b1111);	// L
}

// command
void LCD::Command(uint8_t data)
{
	PORTB &= 0b11000000;

	SendData(data);
}

// write
void LCD::Write(char code)
{
	PORTB |= 0b00100000;

	SendData(code);
}

void LCD::Write(const char *buffer, uint8_t size)
{
	PORTB |= 0b00100000;

	for (uint8_t i = 0; i < size; i++)
		SendData(buffer[i]);
}

void LCD::Write(uint16_t number, uint8_t size)
{
	char buffer[5];

	for (uint8_t i = size - 1; i > 0; i--)
	{
		buffer[i] = number % 10 + '0';
		number /= 10;
	}

	buffer[0] = number + '0';

	Write(buffer, size);
}

// draw
void LCD::SetCursorPos(uint8_t x, uint8_t y)
{
	Command(0b10000000 | x | y << 6);
}

void LCD::DrawText(char code, uint8_t x, uint8_t y)
{
	noInterrupts();

	SetCursorPos(x, y);
	Write(code);

	interrupts();
}

void LCD::DrawText(const char *text, uint8_t x, uint8_t y)
{
	noInterrupts();

	SetCursorPos(x, y);
	Write(text, strlen(text));

	interrupts();
}

void LCD::DrawText(uint16_t number, uint8_t x, uint8_t y, uint8_t size)
{
	noInterrupts();

	SetCursorPos(x, y);
	Write(number, size);

	interrupts();
}

void LCD::DrawTextLarge(uint8_t number, uint8_t code)
{
	noInterrupts();

	for (uint8_t i = 0; i < 4; i++)
	{
		Command(0b01000000 | (i | code << 2) << 3);
		Write(_large_font[number][i], 8);
	}

	interrupts();
}