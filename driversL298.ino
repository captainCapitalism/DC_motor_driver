/*
 * driversL298.ino
 *
 * Created: 7/27/2017 4:32:31 PM
 * Author: mb
 */ 

#include "config/config.h"
#include "headers/encoder.h"
#include "headers/driver.h"
#include "headers/fuzzyDriver.h"
#include "headers/pidDriver.h"
#include "headers/TimersMillis.h"


unsigned long previousMillis = millis();
unsigned long timerFrequencyFuzzy = TIMER_FREQUENCY_FUZZY;
unsigned long timerFrequencyPid = TIMER_FREQUENCY_PID;

int mode = MODE_PID;

Timer MainTimer;

void setup()
{
	pinMode(BUTTON_PIN_1, INPUT);
	pinMode(BUTTON_PIN_2, INPUT);
	pinMode(BUTTON_PIN_3, INPUT);
	
	Encoder.init();
	Driver.init();
	
	//initialize interruption
	attachInterrupt(digitalPinToInterrupt(ENCODER_CHANNELA_PIN), Encoder.doEncode , CHANGE);

	MainTimer.begin(MSECS(1));
	//Jakby nie chodzi³ to: begin(SECS(0.001))

	Serial.begin(SERIAL_BAUDRATE);
}

void loop()
{
	if (MainTimer.available()) {

		switch(mode){
			
			case MODE_FUZZY:
				fuzzyDriver.fuzzyCheckForStatus();
				fuzzyDriver.fuzzyResolveStatus();
			break;

			case MODE_PID:
				pidDriver.checkForStatus();
				pidDriver.resolveStatus();
			break;
		
			default:
			break;
		};
	}
}