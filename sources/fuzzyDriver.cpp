/*
 * fuzzyDriver.cpp
 *
 * Created: 8/21/2017 1:11:31 PM
 * Author: mb
 */ 


#include "../headers/fuzzyDriver.h"
#include "../headers/encoder.h"
#include "../headers/driver.h"

void FuzzyDriverClass::fuzzyCheckForStatus()
{
	if((digitalRead(BUTTON_PIN_1) == HIGH ))
	{
		desiredPosition = Encoder.encoderPos + destination * DEGREE_MULTIPLIER;
	}
	else if(digitalRead(BUTTON_PIN_2) == HIGH)
	{
		desiredPosition = Encoder.encoderPos - destination * DEGREE_MULTIPLIER;
	}
	else if(digitalRead(BUTTON_PIN_3) == HIGH)
	{
		desiredPosition = Encoder.encoderPos;
		status = SPEED_STOP;
		Encoder.encoderPos = INIT_VALUE;
	}

}

void FuzzyDriverClass::fuzzyDetermineSpeed()
{
	fuzzyDifference = desiredPosition - encoderPosition;

	if(fuzzyDifference >= FUZZY_HIGH_DIFFERENCE)
	{
		speed = SPEED_MAX;
		status = MOVE_FORWARD;
	}
	else if(fuzzyDifference <= -FUZZY_HIGH_DIFFERENCE)
	{
		speed = SPEED_MAX;
		status = MOVE_BACKWARD;
	}
	else if(FUZZY_HIGH_DIFFERENCE > fuzzyDifference && fuzzyDifference > FUZZY_MEDIUM_DIFFERENCE)
	{
		speed = SPEED_FUZZY_HIGH;
		status = MOVE_FORWARD;
	}
	else if(-FUZZY_HIGH_DIFFERENCE < fuzzyDifference && fuzzyDifference < -FUZZY_MEDIUM_DIFFERENCE)
	{
		speed = SPEED_FUZZY_HIGH;
		status = MOVE_BACKWARD;
	}
	else if(-FUZZY_MEDIUM_DIFFERENCE < fuzzyDifference && fuzzyDifference < -FUZZY_LOW_DIFFERENCE)
	{
		speed = SPEED_FUZZY_LOW;
		status = MOVE_BACKWARD;
	}
	else if(FUZZY_MEDIUM_DIFFERENCE > fuzzyDifference && fuzzyDifference > FUZZY_LOW_DIFFERENCE)
	{
		speed = SPEED_FUZZY_LOW;
		status = MOVE_FORWARD;
	}
	else if(-FUZZY_LOW_DIFFERENCE <= fuzzyDifference && fuzzyDifference >= FUZZY_LOW_DIFFERENCE)
	{
		speed = SPEED_MAX;
		status = MOVE_STOP;
	}

}

void FuzzyDriverClass::fuzzyResolveStatus()
{
	encoderPosition = Encoder.encoderPos;
	fuzzyDriver.fuzzyDetermineSpeed();
	switch(status)
	{
		case MOVE_FORWARD:
			Driver.moveForward(speed);
			break;
		case MOVE_BACKWARD:
			Driver.moveBackward(speed);
			break;
		case MOVE_STOP:
			Driver.moveStop(speed);
			break;
		default:
			break;
	}
}

FuzzyDriverClass fuzzyDriver;