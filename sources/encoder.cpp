/*
 * encoder.cpp
 *
 * Created: 7/27/2017 4:32:31 PM
 * Author: mb
 */ 

#include "../headers/encoder.h"

void EncoderClass::init()
{
	pinMode(ENCODER_CHANNELA_PIN, INPUT);
	pinMode(ENCODER_CHANNELB_PIN, INPUT);
}

void EncoderClass::doEncode()										//This function checks if encoder is moving forward or backwards
{
	if (digitalRead(ENCODER_CHANNELA_PIN) == digitalRead(ENCODER_CHANNELB_PIN)) 	//when PINs are equal then MOTOR moves forward
	{
		Encoder.encoderPos++;
	}
	else
	{
		Encoder.encoderPos--;
	}
}

EncoderClass Encoder;