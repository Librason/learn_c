/*
 * Author:           
 * Student Number:   
 * Lab Section:      
 * Date:             11/19/2018 8:47:13 PM
 *           
 * Purpose:  
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <DAQlib.h>
#include <Windows.h>
#define _CRT_SECURE_NO_WARNINGS
#define EW_G 0
#define EW_Y 1
#define EW_R 2
#define NS_G 3
#define NS_Y 4
#define NS_R 5

#define TRUE 1
#define FALSE 0

#define ON 1
#define OFF 0
#define SECOND 1000

void trafficLightsController(void);
void setLEDs_EW(int green, int yellow, int red);
void setLEDs_NS(int green, int yellow, int red);

int main(void)
{
	int setupNum = 2;
	/* insert your code here */
	if (setupDAQ(setupNum) == TRUE)
	{
		trafficLightsController();
	}
	else
	{
		printf("Error: Fail to initalize DAQ...\n");
	}
	system("PAUSE");
	return 0;
}

void trafficLightsController(void) {

	while (continueSuperLoop() == TRUE)
	{
		setLEDs_EW(ON, OFF, OFF);
		setLEDs_NS(OFF, OFF, ON);
		if (continueSuperLoop() == FALSE)
		{
			break;
		}
		else
		{
			Sleep(5*SECOND);
		}

		setLEDs_EW(OFF, ON, OFF);
		setLEDs_NS(OFF, OFF, ON);
		if (continueSuperLoop() == FALSE)
		{
			break;
		}
		else
		{
			Sleep(2*SECOND);
		}

		setLEDs_EW(OFF, OFF, ON);
		setLEDs_NS(ON, OFF, OFF);
		if (continueSuperLoop() == FALSE)
		{
			break;
		}
		else
		{
			Sleep(4*SECOND);
		}

		setLEDs_EW(OFF, OFF, ON);
		setLEDs_NS(OFF, ON, OFF);
		if (continueSuperLoop() == FALSE)
		{
			break;
		}
		else
		{
			Sleep(2 * SECOND);
		}
	}
	
}

void setLEDs_EW(int green, int yellow, int red) {
	digitalWrite(EW_G, green);
	digitalWrite(EW_Y, yellow);
	digitalWrite(EW_R, red);
}
void setLEDs_NS(int green, int yellow, int red) {
	digitalWrite(NS_G, green);
	digitalWrite(NS_Y, yellow);
	digitalWrite(NS_R, red);
}
