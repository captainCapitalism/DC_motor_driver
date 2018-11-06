/*
 * config.h
 *
 * Created: 7/27/2017 4:32:31 PM
 * Author: mb
 */ 

#ifndef _CONFIG_h
#define _CONFIG_h

#define SERIAL_BAUDRATE								9600
																		//encoder data read pins
#define ENCODER_CHANNELA_PIN						2
#define ENCODER_CHANNELB_PIN						3
																		//analog button read pins
#define BUTTON_PIN_1								4
#define BUTTON_PIN_2								5
#define BUTTON_PIN_3								6
																		//motor control pins
#define DC_DRIVER_SLEEP_PIN							8
#define DC_DRIVER_DIRECTION_PIN						9
#define DC_DRIVER_PWM_PIN							10
																		//status controls
#define MOVE_FORWARD								1
#define MOVE_BACKWARD								2
#define MOVE_STOP									0
#define MOVE_SOFT_STOP								3
																		//motor speed values
#define SPEED_MAX									255
#define SPEED_FUZZY_HIGH							122
#define SPEED_FUZZY_LOW								30
#define SPEED_STOP									0
																		//PID controls
#define GAIN_PROPORTIONAL							52
#define GAIN_DERIVERATIVE							300
#define GAIN_INTEGRAT								6
																		//5.223 = 1 degree
#define ONE_DEGREE_IN_ENCODER_TICKS					1*5
#define DEGREE_MULTIPLIER							95					//to turn for desired angle
																		//fuzzy business
#define FUZZY_HIGH_DIFFERENCE						150
#define FUZZY_MEDIUM_DIFFERENCE						80
#define FUZZY_LOW_DIFFERENCE						5

#define INIT_VALUE									0
#define TIMER_FREQUENCY_FUZZY						10
#define TIMER_FREQUENCY_PID							1

#define MODE_PID									1
#define MODE_FUZZY									2

#endif