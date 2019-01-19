/*
 * Author:           
 * Student Number:   
 * Lab Section:      
 * Date:             11/19/2018 8:16:53 PM
 *           
 * Purpose:  
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <DAQlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define SWITCH0 0
#define SWITCH1 1
#define LED0 0
#define LED1 1
#define LED2 2
#define ON 1
#define OFF 0
#define TRUE 1
#define FALSE 0

void controlLEDs(void);
void setLEDs(int led0, int led1, int led2);

int main(void)
{
	int setupNum = 1;
	/* insert your code here */
	
	if (setupDAQ(setupNum) == TRUE) {
		controlLEDs();
	}
	else
	{
		printf("Error: Cannot initialize DAQ...\n");
	}
	system("PAUSE");
	return 0;
}

void controlLEDs(void) {
	int switch0;
	int switch1;
	
	//remember to put all codes in continueSuperLoop() function; otherwise it won't run
	while (continueSuperLoop()== TRUE)
	{
		switch0 = digitalRead(SWITCH0);
		switch1 = digitalRead(SWITCH1);

		if (switch0 == ON && switch1 == ON)
		{
			setLEDs(OFF, OFF, ON);
		}
		else if (switch0 == ON && switch1 == OFF)
		{
			setLEDs(ON, OFF, OFF);
		}
		else if (switch0 == OFF && switch1 == ON)
		{
			setLEDs(OFF, ON, OFF);
		}
		else
		{
			setLEDs(OFF, OFF, OFF);
		}

	}
}

void setLEDs(int led0, int led1, int led2) {
	digitalWrite(LED0, led0);
	digitalWrite(LED1, led1);
	digitalWrite(LED2, led2);
}