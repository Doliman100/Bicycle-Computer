#include <Wire.h>

void setup()
{
  Wire.begin();

  uint8_t s = (__TIME__[6] - 48) * 10 + __TIME__[7] - 48;
  uint8_t m = (__TIME__[3] - 48) * 10 + __TIME__[4] - 48;
  uint8_t h = (__TIME__[0] - 48) * 10 + __TIME__[1] - 48;
  
  Wire.beginTransmission(0x68);
  Wire.write((uint8_t)0);
  Wire.write(s + (s / 10) * 6);
  Wire.write(m + (m / 10) * 6);
  Wire.write(h + (h / 10) * 6);
  Wire.endTransmission();
}

void loop()
{}
