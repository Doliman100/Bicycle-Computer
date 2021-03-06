#pragma once

#include <Arduino.h>

class LCD
{
public:
	void Init();

	void DrawText(char code, uint8_t x, uint8_t y);
	void DrawText(const char *text, uint8_t x, uint8_t y);
	void DrawText(uint16_t number, uint8_t x, uint8_t y, uint8_t size);
	void DrawTextLarge(uint8_t number, uint8_t code);

private:
	const char _large_font[10][4][8]
	{
		{ // 0
			{ 0x00, 0x07, 0x07, 0x18, 0x18, 0x18, 0x18, 0x19 },
			{ 0x00, 0x1C, 0x1C, 0x03, 0x03, 0x0F, 0x0F, 0x13 },
			{ 0x19, 0x1E, 0x1E, 0x18, 0x18, 0x07, 0x07, 0x00 },
			{ 0x13, 0x03, 0x03, 0x03, 0x03, 0x1C, 0x1C, 0x00 }
		},
		{ // 2
			{ 0x00, 0x01, 0x01, 0x07, 0x07, 0x01, 0x01, 0x01 },
			{ 0x00, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10 },
			{ 0x01, 0x01, 0x01, 0x01, 0x01, 0x07, 0x07, 0x00 },
			{ 0x10, 0x10, 0x10, 0x10, 0x10, 0x1C, 0x1C, 0x00 }
		},
		{ // 2
			{ 0x00, 0x07, 0x07, 0x18, 0x18, 0x00, 0x00, 0x00 },
			{ 0x00, 0x1C, 0x1C, 0x03, 0x03, 0x03, 0x03, 0x0C },
			{ 0x00, 0x01, 0x01, 0x06, 0x06, 0x1F, 0x1F, 0x00 },
			{ 0x0C, 0x10, 0x10, 0x00, 0x00, 0x1F, 0x1F, 0x00 }
		},
		{ // 3
			{ 0x00, 0x1F, 0x1F, 0x00, 0x00, 0x01, 0x01, 0x00 },
			{ 0x00, 0x1F, 0x1F, 0x0C, 0x0C, 0x10, 0x10, 0x0C },
			{ 0x00, 0x00, 0x00, 0x18, 0x18, 0x07, 0x07, 0x00 },
			{ 0x0C, 0x03, 0x03, 0x03, 0x03, 0x1C, 0x1C, 0x00 }
		},
		{ // 4
			{ 0x00, 0x00, 0x00, 0x01, 0x01, 0x06, 0x06, 0x18 },
			{ 0x00, 0x0C, 0x0C, 0x1C, 0x1C, 0x0C, 0x0C, 0x0C },
			{ 0x18, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00 },
			{ 0x0C, 0x1F, 0x1F, 0x0C, 0x0C, 0x0C, 0x0C, 0x00 }
		},
		{ // 5
			{ 0x00, 0x1F, 0x1F, 0x18, 0x18, 0x1F, 0x1F, 0x00 },
			{ 0x00, 0x1F, 0x1F, 0x00, 0x00, 0x1C, 0x1C, 0x03 },
			{ 0x00, 0x00, 0x00, 0x18, 0x18, 0x07, 0x07, 0x00 },
			{ 0x03, 0x03, 0x03, 0x03, 0x03, 0x1C, 0x1C, 0x00 }
		},
		{ // 6
			{ 0x00, 0x01, 0x01, 0x06, 0x06, 0x18, 0x18, 0x1F },
			{ 0x00, 0x1C, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x1C },
			{ 0x1F, 0x18, 0x18, 0x18, 0x18, 0x07, 0x07, 0x00 },
			{ 0x1C, 0x03, 0x03, 0x03, 0x03, 0x1C, 0x1C, 0x00 }
		},
		{ // 7
			{ 0x00, 0x1F, 0x1F, 0x18, 0x18, 0x00, 0x00, 0x00 },
			{ 0x00, 0x1F, 0x1F, 0x03, 0x03, 0x03, 0x03, 0x0C },
			{ 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00 },
			{ 0x0C, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00 }
		},
		{ // 8
			{ 0x00, 0x07, 0x07, 0x18, 0x18, 0x18, 0x18, 0x07 },
			{ 0x00, 0x1C, 0x1C, 0x03, 0x03, 0x03, 0x03, 0x0C },
			{ 0x07, 0x18, 0x18, 0x18, 0x18, 0x07, 0x07, 0x00 },
			{ 0x1C, 0x03, 0x03, 0x03, 0x03, 0x1C, 0x1C, 0x00 }
		},
		{ // 9
			{ 0x00, 0x07, 0x07, 0x18, 0x18, 0x18, 0x18, 0x07 },
			{ 0x00, 0x1C, 0x1C, 0x03, 0x03, 0x03, 0x03, 0x1F },
			{ 0x07, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x00 },
			{ 0x1F, 0x03, 0x03, 0x0C, 0x0C, 0x10, 0x10, 0x00 }
		}
	};
	
	void SendDataH(uint8_t data);
	void SendData(uint8_t data);

	void Command(uint8_t data);

	void Write(char code);
	void Write(const char *buffer, uint8_t size);
	void Write(uint16_t number, uint8_t size);

	void SetCursorPos(uint8_t x, uint8_t y);
};