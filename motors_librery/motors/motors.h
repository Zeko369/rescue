#ifndef motors_h
#define motors_h

#include "Arduino.h"

class motors
{
	private:
		int8_t m12;
		int8_t m11;
		int8_t m22;
		int8_t m21;

		int8_t mEnable1;
		int8_t mEnable2;

	public:
		motors(int8_t motor11, int8_t motor12, int8_t motor21, int8_t motor22, int8_t motor1E, int8_t motor2E, int8_t speed, bool encoder, float turnSpeed);

		void go(int16_t m1, int16_t m2 = 1023);
		void stop();
};

#endif
