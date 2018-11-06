/*
 * encoder.h
 *
 * Created: 7/27/2017 4:32:31 PM
 * Author: mb
 */ 

 #include "../config/config.h"

#ifndef _ENCODER_h
#define _ENCODER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class EncoderClass
{
	public:
		volatile int encoderPos = INIT_VALUE;
		void init();
		static void doEncode();
};

extern EncoderClass Encoder;

#endif