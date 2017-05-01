int8_t m11 = 12;
int8_t m12 = 11;
int8_t m21 = 10;
int8_t m22 = 9;

char red = "";

void go(int8_t m1, int16_t m2 = 1023)
{
	if(m2 == 1023)
	{
		if(m1 > 0)
		{
			analogWrite(m11, m1+510);	
			analogWrite(m21, m1+510);	
		}	
		else
		{
			analogWrite(m12, m1);	
			analogWrite(m22, m1);	
		}
	}
	else
	{
		if(m1 < 0) analogWrite(m11, m1);
		else analogWrite(m12, m1 + 510);

		if(m2 > 0) {analogWrite(m21, m2);}
		else {analogWrite(m22, m2 + 510);}
	}
}

void mStop()
{
	digitalWrite(m11, 0);
	digitalWrite(m12, 0);
	digitalWrite(m21, 0);
	digitalWrite(m22, 0);
}

void setup()
{
	Serial1.begin(112500);

	pinMode(m11, OUTPUT);
	pinMode(m12, OUTPUT);
	pinMode(m21, OUTPUT);
	pinMode(m22, OUTPUT);

	pinMode(16, OUTPUT);
	pinMode(17, OUTPUT);
	digitalWrite(16, 1);
	digitalWrite(17, 0);
}

void loop()
{
	if(Serial1.available())
	{
		red = Serial1.read();

		switch (red) 
		{
			case 'f': go(255); break;
			case 'b': go(-255);break;
			case 'r': go(-255, 255);break;
			case 'l': go(255, -255);break;
			case 'n': mStop();break;
		}
	}

	delay(10);
}
