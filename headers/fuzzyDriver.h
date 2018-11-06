/*
 * fuzzyDriver.h
 *
 * Created: 8/21/2017 1:11:31 PM
 * Author: mb
 */ 

#include "../config/config.h"

#ifndef _FUZZYDRIVER_h
#define _FUZZYDRIVER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class FuzzyDriverClass
{
	public:
		int desiredPosition;
		int encoderPosition;
		int fuzzyDifference;

		int status = MOVE_STOP;
		int speed = SPEED_STOP;
		int destination = ONE_DEGREE_IN_ENCODER_TICKS;

		void fuzzyResolveStatus();
		void fuzzyCheckForStatus();
		void fuzzyDetermineSpeed();
};

extern FuzzyDriverClass fuzzyDriver;

#endif

