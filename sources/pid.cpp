/*
 * pid.cpp
 *
 * Created: 2/08/2017 2:17:31 PM
 * Author: mb
 */ 

#include "../headers/pid.h"

void PidClass::UpdatePID(double error, double position)
{
	double pTerm, dTerm, iTerm;
	pTerm = propGain * error;				// calculate the proportional term
											// calculate the integral state with appropriate limiting
	integratState += error;
											// Limit the integrator state if necessary

	if (integratState >integratMax)
	{
		integratState =integratMax;
	}
	else if (integratState < integratMin)
	{
		integratState = integratMin;
	}
											// calculate the integral term	iTerm =integratGain * integratState;
											// calculate the derivative
	dTerm = derGain * (derState - position);
	derState = position;
	updatedSpeed =  pTerm + dTerm + iTerm;

	if(updatedSpeed > SPEED_MAX)					//speed cannot surpass 255, otherwise motor gets overflowed value
	{
		updatedSpeed = SPEED_MAX;
	} else if (updatedSpeed < -SPEED_MAX)
	{
		updatedSpeed = -SPEED_MAX;
	}
}

PidClass pid;