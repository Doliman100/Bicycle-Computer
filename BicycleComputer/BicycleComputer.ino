#include <Wire.h>

#include "core.h"

Core core;

void setup()
{
	core.Init();
}

void loop()
{
	core.Update();
}