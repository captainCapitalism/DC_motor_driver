/*
 * pid.h
 *
 * Created: 2/08/2017 2:17:31 PM
 * Author: mb
 */ 

 #include "../config/config.h"

#ifndef _PID_h
#define _PID_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class PidClass
{
	public:
		double	derState;							// Last position input
		double	integratState;						// Integrator state
		double	integratMax,						// Maximum and minimum
				integratMin;						// allowable integrator state
		double	integratGain=GAIN_INTEGRAT,	
				propGain=GAIN_PROPORTIONAL,			
				derGain=GAIN_DERIVERATIVE;			
		double	updatedSpeed = SPEED_MAX;

		void UpdatePID(double error, double position);
};

extern PidClass pid;

#endif