
#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_STRING 30
#define MAX_LINE 2,000,000
#define MAX_HUMAN 200,000

char sLongInputLine[MAX_LINE+1] = ""; // Initialize a character array to store a long input line
int anComingSec[MAX_HUMAN]; // Initialize an array to store the arrival time of humans

int main() {

	char sInput[MAX_STRING+1] = ""; // Initialize a character array to store a single input line
	char* psWord = NULL; // Pointer to store a token from the input line
	char* psInput = NULL; // Pointer to store the first token from the input line

	int nHumanNumber = 0; // Initialize a counter for the number of humans
	int nNextHumanIndex = 0; // Initialize a counter for the index of the next human
	int nWaterLength = 0; // Initialize the length of the water wave
	int nWaterLife = 0; // Initialize the life of the water wave
	int nStart = 0; // Initialize the start time of the water wave
	int nStop = 0; // Initialize the stop time of the water wave

	int nIndex = 0; // Initialize a counter for iterating through the array
	int i = 0; // Initialize a counter for iterating through the humans
	int j = 0; // Initialize a counter for iterating through the humans

	# <START-OF-CODE>
	# Read the first line of input
	sInput = input().strip()
	psInput = sInput.split()
	nHumanNumber = int(psInput[0])
	nWaterLength = int(psInput[1])

	# Read the second line of input
	sLongInputLine = input().strip()
	anComingSec = [int(x) for x in sLongInputLine.split()]

	# Initialize the start time of the water wave to the arrival time of the first human
	nStart = anComingSec[0]

	# Calculate the life of the water wave by iterating through the humans and finding the overlapping periods
	while nNextHumanIndex < nHumanNumber:
		if nNextHumanIndex == nHumanNumber:
			break
		else:
			# Calculate the stop time of the water wave based on the start time and the length of the water wave
			nStop = nStart + nWaterLength

			# Check if the next human arrives before the stop time of the water wave
			if anComingSec[nNextHumanIndex] < nStop:
				# If the next human arrives before the stop time, we need to find the maximum stop time that includes both the current and next human
				while nNextHumanIndex < nHumanNumber and anComingSec[nNextHumanIndex] < nStop:
					if nStop <= anComingSec[nNextHumanIndex] + nWaterLength:
						nStop = anComingSec[nNextHumanIndex] + nWaterLength
						nNextHumanIndex += 1

				# If we have reached the end of the array, we have found the maximum stop time that includes all the humans
				if nNextHumanIndex == nHumanNumber:
					nWaterLife += (nStop - nStart)
					break
			# If the next human arrives after the stop time of the water wave, we can update the start time to the arrival time of the next human and continue the loop
			nStart = nStop
			if nStart < anComingSec[nNextHumanIndex]:
				nStart = anComingSec[nNextHumanIndex]
	# 