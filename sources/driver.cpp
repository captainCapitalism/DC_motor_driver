/*
 * driver.cpp
 *
 * Created: 7/27/2017 4:32:31 PM
 * Author: mb
 */ 

#include "../headers/driver.h"

void DriverClass::init()
{	
	pinMode(DC_DRIVER_SLEEP_PIN, INPUT);
	pinMode(DC_DRIVER_PWM_PIN, INPUT);
	pinMode(DC_DRIVER_DIRECTION_PIN, INPUT);
}

void DriverClass::moveForward(int speed)
{
	analogWrite(DC_DRIVER_PWM_PIN, speed);
	digitalWrite(DC_DRIVER_SLEEP_PIN, LOW);
	digitalWrite(DC_DRIVER_DIRECTION_PIN, HIGH);
}

void DriverClass::moveBackward(int speed)
{
	analogWrite(DC_DRIVER_PWM_PIN, speed);
	digitalWrite(DC_DRIVER_SLEEP_PIN, HIGH);
	digitalWrite(DC_DRIVER_DIRECTION_PIN, LOW);
}

void DriverClass::moveStop(int speed)
{
	analogWrite(DC_DRIVER_PWM_PIN, speed);
	digitalWrite(DC_DRIVER_SLEEP_PIN, HIGH);
	digitalWrite(DC_DRIVER_DIRECTION_PIN, HIGH);
}

void DriverClass::moveSoftStop(void)
{
	analogWrite(DC_DRIVER_PWM_PIN, SPEED_STOP);
	digitalWrite(DC_DRIVER_SLEEP_PIN, LOW);
	digitalWrite(DC_DRIVER_DIRECTION_PIN, LOW);
}

DriverClass Driver;