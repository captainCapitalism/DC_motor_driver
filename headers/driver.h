/*
 * driver.h
 *
 * Created: 7/27/2017 4:32:31 PM
 * Author: mb
 */ 

#include "../config/config.h"

#ifndef _DRIVER_h
#define _DRIVER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class DriverClass
{
	public:		
		void moveForward(int speed);
		void moveBackward(int speed);
		void moveStop(int speed);
		void moveSoftStop(void);
		void init();
};

extern DriverClass Driver;

#endif