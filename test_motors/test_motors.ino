int8_t m11 = 12;
int8_t m12 = 11;
int8_t m21 = 10;
int8_t m22 = 9;

int8_t mEnable1 = 13;
int8_t mEnable2 = 8;

int8_t button = 31;

void waitButton()
{
	while(digitalRead(button) == 1) {};
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

void setup()
{
	pinMode(m11, OUTPUT);
	pinMode(m12, OUTPUT);
	pinMode(m21, OUTPUT);
	pinMode(m22, OUTPUT);
	pinMode(mEnable1, OUTPUT);
	pinMode(mEnable2, OUTPUT);

	pinMode(button, INPUT_PULLUP);

	waitButton();
}

void loop()
{
	go(255, 255);
	delay(500);
	stop();
	delay(20);
	go(255, -255);
	delay(250);
	stop();
	delay(20);
	go(255, -255);
	go(-255, 255);
	delay(250);
	stop();
	delay(20);
	go(255, -255);
	go(-255, 255);
	delay(250);
	go(255, -255);
	delay(250);
	stop();
	delay(20);
	go(255, -255);
	go(-255, -255);
	delay(500);

	stop();
	delay(1000);
}
