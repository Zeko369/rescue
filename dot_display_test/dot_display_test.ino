#include "MaxMatrix.h"

int8_t data = 7;
int8_t ss = 5;
int8_t load = 6;
int8_t maxInUse = 1;

MaxMatrix m(data, load, ss, maxInUse);

void setup()
{
	m.init();
	m.setIntensity(8);

	m.setDot(0, 0, 1);
	m.setDot(1, 1, 1);
	delay(10000);
}

void loop()
{
	for(int i = 0; i<8; i++)
	{
		for(int j = 0; j<8; j++)
		{
			m.setDot(i, j, 0);	
			delay(25);
		}
	}
}
