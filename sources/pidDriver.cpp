/*
 * pidDriver.cpp
 *
 * Created: 8/24/2017 1:24:12 PM
 * Author: mb
 */ 

#include "../headers/driver.h" 
#include "../headers/pidDriver.h"
#include "../headers/encoder.h"
#include "../headers/pid.h"

//#define DEBUG_DRIVER //debug state machine
//#define DEBUG_SPEED //debug state machine

void pidDriverClass::checkForStatus()
{
/* 
This function based on which button is pressed determinates 
which state should trigger
*/
	if((digitalRead(BUTTON_PIN_1) == HIGH ))
	{
		status = MOVE_FORWARD;
		progress = INIT_VALUE;
		initEncoderPosition = Encoder.encoderPos;

	}
	else if(digitalRead(BUTTON_PIN_2) == HIGH)
	{
		status = MOVE_BACKWARD; 
		progress = INIT_VALUE;
		initEncoderPosition = Encoder.encoderPos;
	}
	else if(digitalRead(BUTTON_PIN_3) == HIGH)
	{
		status = MOVE_STOP;					 
		progress=INIT_VALUE;																//resets values
		pid.updatedSpeed = SPEED_MAX;
		Encoder.encoderPos = INIT_VALUE;
	}
}

void pidDriverClass::resolveStatus()										//This function controls motor based on STATUS variable
{
	encoderPosition = Encoder.encoderPos;

	switch (status)
	{
		case MOVE_FORWARD:															//move forward for value of destination
			desiredPosition = initEncoderPosition + progress*destination;
			if (progress < DEGREE_MULTIPLIER)
			{
				if(encoderPosition >= desiredPosition-errorRange && encoderPosition <= desiredPosition+errorRange)
				{
					progress++;
				}
				else
				{
					pid.UpdatePID(desiredPosition - encoderPosition, encoderPosition);
					if(pid.updatedSpeed >= 0)
					{
						Driver.moveForward(pid.updatedSpeed);
					} 
					else if(pid.updatedSpeed < 0)
					{
						Driver.moveBackward(-pid.updatedSpeed);
					}

					#ifdef DEBUG_SPEED
					Serial.print("   ");
					Serial.print(pid.updatedSpeed);
					#endif

				}
			} 
			else 
			{
				status = MOVE_STOP;
			}
			break;
		
		case MOVE_BACKWARD:														// move to -destination
			desiredPosition = initEncoderPosition + progress*destination;
			if (progress > -DEGREE_MULTIPLIER)
			{
				if(encoderPosition >= desiredPosition-errorRange && encoderPosition <=desiredPosition+errorRange)
				{
					progress--;
				}
				else
				{
					pid.UpdatePID(desiredPosition- encoderPosition, encoderPosition);
					if(pid.updatedSpeed >= 0)
					{
						Driver.moveForward(pid.updatedSpeed);
					}
					else if(pid.updatedSpeed < 0)
					{
						Driver.moveBackward(-pid.updatedSpeed);
					}

					#ifdef DEBUG_SPEED
						Serial.print("   ");
						Serial.print(pid.updatedSpeed);
					#endif

				}
			}
			else
			{
				status = MOVE_STOP;
			}
			break;

		case MOVE_STOP:														// Stop
			Driver.moveStop(SPEED_MAX);

			#ifdef DEBUG_DRIVER
			Serial.println("HALT");
			#endif
			break;

		case MOVE_SOFT_STOP:						// Soft Stop
			Driver.moveSoftStop();
			#ifdef DEBUG_DRIVER
			Serial.println("SLOW");
			#endif
						break;

		default:												 // Soft Stop
			Driver.moveSoftStop();
			break;
	};

}

pidDriverClass pidDriver;