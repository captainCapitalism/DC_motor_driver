/*
 * pidDriver.h
 *
 * Created: 8/24/2017 1:24:12 PM
 * Author: mb
 */ 

#ifndef _PIDDRIVER_h
#define _PIDDRIVER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class pidDriverClass
{
	public:
		int encoderPosition;
		int progress = INIT_VALUE; //used to track progression of rotation
		int errorRange = 1;
		int initEncoderPosition;
		int desiredPosition;

		int status = MOVE_SOFT_STOP;
		int destination = ONE_DEGREE_IN_ENCODER_TICKS;	// value to which moves motor


		void checkForStatus(void);
		void resolveStatus(void);
};

extern pidDriverClass pidDriver;

#endif

