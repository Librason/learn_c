#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <DAQlib.h>
#include <stdlib.h>
#include <Windows.h>

#define NUM_DISPLAYS 8

#define ON 1
#define OFF 0

#define RUN_SWITCH 0
#define RESET_SWTICH 1

#define TRUE 1
#define FALSE 0

#define ONE_SECOND 1000

void runCounter(void);
void writeNumber(int number);
void writeDigit(int digit, int position);

int main(void) {
	int setupNum = 4;

	if (setupDAQ(setupNum) == TRUE)
	{
		runCounter();
	}
	else
	{
		printf("Error: Cannot initialize DAQ...\n");
	}
	system("PAUSE");
	return 0;
}

void runCounter(void) {
	int startTime, stopTime;
	int runSwitch, resetSwitch;
	int count;

	printf("Please enter a startTime: ");
	scanf("%d", &startTime);
	printf("Please enter a stopTime: ");
	scanf("%d", &stopTime);

	while (startTime < 0 || stopTime < 0 || startTime < stopTime)
	{
		printf("Error\n");
		printf("Please enter a startTime: ");
		scanf("%d", &startTime);
		printf("Please enter a stopTime: ");
		scanf("%d", &stopTime);
	}

	printf("\nProgram initializing...\n");
	printf("Please set both switches to OFF\n");

	do
	{
		runSwitch = digitalRead(RUN_SWITCH);
		resetSwitch = digitalRead(RESET_SWTICH);
	} while (runSwitch != OFF || resetSwitch != OFF);

	printf("\nBoth switches are OFF\n");
	printf("Proceeding...\n");

	count = startTime;
	writeNumber(startTime);

	while (continueSuperLoop() == TRUE)
	{
		runSwitch = digitalRead(RUN_SWITCH);
		resetSwitch = digitalRead(RESET_SWTICH);

		if (resetSwitch == ON)
		{
			count = startTime;
			writeNumber(startTime);
		}
		else
		{
			if (runSwitch == OFF)
			{
				writeNumber(count);
			}
				
			if (runSwitch == ON && count >= stopTime)
			{
				writeNumber(count);
				Sleep(ONE_SECOND);
				count--;
			}
		}
	}
}

void writeNumber(int number) {
	int digit;
	int position = 0;

	do
	{
		digit = number % 10;
		number = number / 10;

		writeDigit(digit, position);
		position++;

	} while (position < NUM_DISPLAYS && number != 0);

	while (position < NUM_DISPLAYS)
	{
		displayWrite(OFF, position);
		position++;
	}
}

void writeDigit(int digit, int position) {
	static int digitsTable[10] = {
		252, 96, 218, 242, 102, 182, 190, 224, 254, 246 };

	displayWrite(digitsTable[digit], position);
}