
#pragma warning(disable:4996)
import sys
import string
import math

# Initialize a character array to store a long input line
sLongInputLine = ""

# Initialize an array to store the arrival time of humans
anComingSec = []

# Initialize a counter for the number of humans
nHumanNumber = 0

# Initialize a counter for the index of the next human
nNextHumanIndex = 0

# Initialize the length of the water wave
nWaterLength = 0

# Initialize the life of the water wave
nWaterLife = 0

# Initialize the start time of the water wave
nStart = 0

# Initialize the stop time of the water wave
nStop = 0

# Initialize a counter for iterating through the array
nIndex = 0

# Initialize a counter for iterating through the humans
i = 0

# Initialize a counter for iterating through the humans
j = 0

# Read the first line of input
sInput = sys.stdin.readline()

# Check if the line ends with a newline character
if sInput.endswith('\n'):
	sInput = sInput[:-1]

# Tokenize the string using whitespace as the delimiter
psInput = string.split(sInput)

# Convert the first token to an integer representing the number of humans
nHumanNumber = int(psInput[0])

# Convert the second token to an integer representing the length of the water wave
nWaterLength = int(psInput[1])

# Read the second line of input
sLongInputLine = sys.stdin.readline()

# Check if the line ends with a newline character
if sLongInputLine.endswith('\n'):
	sLongInputLine = sLongInputLine[:-1]

# Parse the second line of input and store the arrival times of the humans in the anComingSec array
for i in range(0, nHumanNumber):
	psWord = string.split(sLongInputLine)
	anComingSec.append(int(psWord[i]))

# Initialize the start time of the water wave to the arrival time of the first human
nStart = anComingSec[0]

# Calculate the life of the water wave by iterating through the humans and finding the overlapping periods
while nNextHumanIndex < nHumanNumber:
	if nNextHumanIndex == nHumanNumber:
		break # If we have reached the last human, we are done
	else:
		# Calculate the stop time of the water wave based on the start time and the length of the water wave
		nStop = nStart + nWaterLength

		# Check if the next human arrives before the stop time of the water wave
		if anComingSec[nNextHumanIndex] < nStop:
			# If the next human arrives before the stop time, we need to find the maximum stop time that includes both the current and next human
			while nNextHumanIndex < nHumanNumber and anComingSec[nNextHumanIndex] < nStop:
				if nStop <= anComingSec[nNextHumanIndex] + nWaterLength:
					nStop = anComingSec[nNextHumanIndex] + nWaterLength # Update the stop time to include the next human
					nNextHumanIndex += 1 # Move to the next human

			# If we have reached the end of the array, we have found the maximum stop time that includes all the humans
			if nNextHumanIndex == nHumanNumber:
				nWaterLife += (nStop - nStart) # Calculate the life of the water wave based on the start and stop times
				break # Exit the loop
		# If the next human arrives after the stop time of the water wave, we can update the start time to the arrival time of the next human and continue the loop
		nStart = nStop
		if nStart < anComingSec[nNextHumanIndex]:
			nStart = anComingSec[nNextHumanIndex] # Update the start time to the arrival time of the next human

# Print the life of the water wave to the standard output stream
print(nWaterLife)

