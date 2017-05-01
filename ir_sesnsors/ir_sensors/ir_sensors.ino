#include "MaxMatrix.h"

uint8_t arrey[8] = {A8, A9, A10, A11, A12, A13, A14, A15};

int8_t m12 = 11;
int8_t m11 = 12;
int8_t m22 = 9;
int8_t m21 = 10;

int8_t mEnable1 = 13;
int8_t mEnable2 = 8;

int8_t button = 31;

double now, beg;

int8_t data = 33;
int8_t ss = 37;
int8_t load = 35;
int8_t maxInUse = 1;

MaxMatrix m(data, load, ss, maxInUse);

bool left90[8][8] = {{ 0, 0, 0, 0, 0, 0, 0, 0 },
		       { 0, 0, 0, 0, 0, 0, 0, 0 },
		       { 0, 1, 1, 1, 1, 0, 0, 0 },
		       { 0, 1, 1, 1, 1, 0, 0, 0 },
		       { 0, 0, 0, 1, 1, 0, 0, 0 },
		       { 0, 0, 0, 1, 1, 0, 0, 0 },
		       { 0, 0, 0, 1, 1, 0, 0, 0 },
		       { 0, 0, 0, 0, 0, 0, 0, 0 }};

bool right90[8][8] = {{ 0, 0, 0, 0, 0, 0, 0, 0 },
		        { 0, 0, 0, 0, 0, 0, 0, 0 },
		        { 0, 0, 0, 1, 1, 1, 1, 0 },
		        { 0, 0, 0, 1, 1, 1, 1, 0 },
		        { 0, 0, 0, 1, 1, 0, 0, 0 },
		        { 0, 0, 0, 1, 1, 0, 0, 0 },
		        { 0, 0, 0, 1, 1, 0, 0, 0 },
		        { 0, 0, 0, 0, 0, 0, 0, 0 }};

bool left11[8][8] = {{ 0, 0, 0, 0, 0, 0, 0, 0 },
		       { 0, 0, 0, 1, 1, 0, 0, 0 },
		       { 0, 0, 1, 1, 1, 0, 0, 0 },
		       { 0, 1, 1, 1, 1, 0, 0, 0 },
		       { 1, 1, 0, 1, 1, 0, 0, 0 },
		       { 0, 0, 0, 1, 1, 0, 0, 0 },
		       { 0, 0, 0, 1, 1, 0, 0, 0 },
		       { 0, 0, 0, 0, 0, 0, 0, 0 }};

bool right11[8][8] = {{ 0, 0, 0, 0, 0, 0, 0, 0 },
		        { 0, 0, 0, 1, 1, 0, 0, 0 },
		        { 0, 0, 0, 1, 1, 1, 0, 0 },
		        { 0, 0, 0, 1, 1, 1, 1, 0 },
		        { 0, 0, 0, 1, 1, 0, 1, 1 },
		        { 0, 0, 0, 1, 1, 0, 0, 0 },
		        { 0, 0, 0, 1, 1, 0, 0, 0 },
		        { 0, 0, 0, 0, 0, 0, 0, 0 }};

bool both9090[8][8] = {{ 0, 0, 0, 0, 0, 0, 0, 0 },
		         { 0, 1, 1, 1, 1, 1, 1, 0 },
		         { 0, 1, 1, 1, 1, 1, 1, 0 },
		         { 0, 0, 0, 1, 1, 0, 0, 0 },
		         { 0, 0, 0, 1, 1, 0, 0, 0 },
		         { 0, 0, 0, 1, 1, 0, 0, 0 },
		         { 0, 0, 0, 1, 1, 0, 0, 0 },
		         { 0, 0, 0, 0, 0, 0, 0, 0 }};

bool leftUP[8][8] = {{ 0, 0, 0, 1, 1, 0, 0, 0 },
		       { 0, 0, 0, 1, 1, 0, 0, 0 },
		       { 0, 1, 1, 1, 1, 0, 0, 0 },
		       { 0, 1, 1, 1, 1, 0, 0, 0 },
		       { 0, 0, 0, 1, 1, 0, 0, 0 },
		       { 0, 0, 0, 1, 1, 0, 0, 0 },
		       { 0, 0, 0, 1, 1, 0, 0, 0 },
		       { 0, 0, 0, 0, 0, 0, 0, 0 }};

uint8_t readSensor(int8_t i){ return analogRead(arrey[i]); }

void drawSimb(int8_t n)
{
	switch(n)
	{
		case 0:
		{
			for(int i = 0; i<8; i++)
			{
				for(int j = 0; j<8; j++)
				{
					m.setDot(i, j, left90[i][j]);
				}
			}

			break;
		}
		case 1:
		{
			for(int i = 0; i<8; i++)
			{
				for(int j = 0; j<8; j++)
				{
					m.setDot(i, j, right90[i][j]);
				}
			}

			break;
		}
		case 2:
		{
			for(int i = 0; i<8; i++)
			{
				for(int j = 0; j<8; j++)
				{
					m.setDot(i, j, left11[i][j]);
				}
			}

			break;
		}
		case 3:
		{
			for(int i = 0; i<8; i++)
			{
				for(int j = 0; j<8; j++)
				{
					m.setDot(i, j, right11[i][j]);
				}
			}

			break;
		}
		case 4:
		{
			for(int i = 0; i<8; i++)
			{
				for(int j = 0; j<8; j++)
				{
					m.setDot(i, j, both9090[i][j]);
				}
			}

			break;
		}
		case 5:
		{
			for(int i = 0; i<8; i++)
			{
				for(int j = 0; j<8; j++)
				{
					m.setDot(i, j, leftUP[i][j]);
				}
			}

			break;
		}
	}
}

void go(int16_t m1, int16_t m2 = 1023)
{
	if(m2 == 1023)
	{
		if(m1 > 0)
		{
			digitalWrite(m11, 1);
			digitalWrite(m12, 0);
			digitalWrite(m21, 1);
			digitalWrite(m22, 0);

			analogWrite(mEnable1, m1);
			analogWrite(mEnable2, m1);
		}	
		else
		{
			digitalWrite(m11, 0);
			digitalWrite(m12, 1);
			digitalWrite(m21, 0);
			digitalWrite(m22, 1);

			analogWrite(mEnable1, m1*-1);
			analogWrite(mEnable2, m1*-1);
		}
	}
	else
	{
		if(m1 > 0)
		{ 
			digitalWrite(m11, 1);
			digitalWrite(m12, 0);

			analogWrite(mEnable1, m1);
		}		
		else 
		{ 
			digitalWrite(m11, 0);
			digitalWrite(m12, 1);
			
			analogWrite(mEnable1, m1*-1);
		}

		if(m2 > 0)
		{ 
			digitalWrite(m21, 1);
			digitalWrite(m22, 0);

			analogWrite(mEnable2, m2);
		}		
		else 
		{ 
			digitalWrite(m21, 0);
			digitalWrite(m22, 1);
			
			analogWrite(mEnable2, m2*-1);
		}
	}
}

void stop()
{
	digitalWrite(m11, LOW);
	digitalWrite(m12, LOW);
	digitalWrite(m21, LOW);
	digitalWrite(m22, LOW);

	digitalWrite(mEnable1, 0);
	digitalWrite(mEnable2, 0);
}

void waitButton() { while(digitalRead(button) == 1) {}; }

void setup()
{
	for(int i = 0; i<8; i++) pinMode(arrey[i], INPUT);

	Serial.begin(9600);

	m.init();
	m.setIntensity(8);
	m.clear();

	beg = millis();

	pinMode(m11, OUTPUT);
	pinMode(m12, OUTPUT);
	pinMode(m21, OUTPUT);
	pinMode(m22, OUTPUT);
	pinMode(mEnable1, OUTPUT);
	pinMode(mEnable2, OUTPUT);

	pinMode(button,INPUT_PULLUP);

	while(digitalRead(button) == 1) {};

	stop();

	delay(500);
}


void loop()
{
	Serial.print(readSensor(3));
	Serial.print(" ");
	Serial.print(readSensor(4));
	Serial.print(" ");

	int a = readSensor(3);
	int b = readSensor(4);

	if(a < 150)
	{
		if(b < 150)
		{
			go(175, 175);	
			Serial.println(0);
		}	
		else
		{
			go(175, -175);	
			Serial.println(1);
		}
	}
	else
	{
		if(b < 150)
		{
			go(-175, 175);	
			Serial.println(2);
		}	
		else
		{
			go(175, 175);	
			Serial.println(3);
		}
	}

	int c = readSensor(0);
	int d = readSensor(7);
	int e = readSensor(1);
	int f = readSensor(6);

	//one sec
	if(c < 150)
	{
		beg = millis();
		now = millis();
		while(now - 100 <= beg)
		{
			go(255, 255);
			int c = readSensor(0);
			int d = readSensor(7);
			int e = readSensor(1);
			int f = readSensor(6);
			////////////////////////////////////////////detect green


			if(d < 150) //intersection
			{
				stop();
				delay(100);
				Serial.println("Both");
				drawSimb(4);
				waitButton();
				m.clear();
				////////////////////////////////////////////detect green
			}
			else if(e < 150)
			{
				bool pero = false;

				for(int i = 0; i<100; i++)
				{
					int c = readSensor(0);
					int d = readSensor(7);
					int e = readSensor(1);
					int f = readSensor(6);

					if(d < 150)
					{
						stop();
						delay(100);
						Serial.println("Both");
						drawSimb(4);
						waitButton();
						m.clear();
						////////////////////////////////////////////detect green
						pero = 1;
						break;
					}
					else if(c > 150 && (readSensor(3) < 150 || readSensor(4) < 150))
					{
						stop();
						delay(100);
						Serial.println("Both");
						drawSimb(5);
						waitButton();
						m.clear();
						////////////////////////////////////////////detect green
						pero = 1;
						break;
					}
				}
				if(pero == 0)
				{
					stop();
					delay(100);
					Serial.println("90 left");
					drawSimb(0);
					waitButton();
					m.clear();
				}
			}
			else
			{
				stop();
				delay(100);
				Serial.println("90 1");
				drawSimb(2);
				waitButton();
				m.clear();
			}

			now = millis();
		}
	}
}
