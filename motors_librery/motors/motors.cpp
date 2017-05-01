#include "Arduino.h"
#include "motors.h"

motors::motors(int8_t _motor11, int8_t _motor12, int8_t _motor21, int8_t _motor22, int8_t _motor1E, int8_t _motor2E, int8_t _speed, bool _encoder, float _turnSpeed)
{
	m11 = _motor11;
	m12 = _motor12;
	m21 = _motor21;
	m22 = _motor22;
	motor1E = _motor1E;
	motor2E = _motor2E;

	pinMode(m11, 1);
	pinMode(m12, 1);
	pinMode(m21, 1);
	pinMode(m22, 1);
	pinMode(motor1E, 1);
	pinMode(motor2E, 1);
}

void motors::stop()
{
	digitalWrite(m11, LOW);
	digitalWrite(m12, LOW);
	digitalWrite(m21, LOW);
	digitalWrite(m22, LOW);

	digitalWrite(mEnable1, 0);
	digitalWrite(mEnable2, 0);
}

void motors::go(int16_t m1, int16_t m2 = 1023)
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
