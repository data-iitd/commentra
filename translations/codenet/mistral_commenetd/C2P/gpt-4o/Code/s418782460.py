import sys

MAX_STRING = 30
MAX_LINE = 2000000
MAX_HUMAN = 200000

sLongInputLine = ""  # Initialize a string to store a long input line
anComingSec = []  # Initialize a list to store the arrival time of humans

def main():
    global anComingSec

    sInput = input().strip()  # Read the first line of input
    tokens = sInput.split()  # Tokenize the string using whitespace as the delimiter
    nHumanNumber = int(tokens[0])  # Convert the first token to an integer representing the number of humans
    nWaterLength = int(tokens[1])  # Convert the second token to an integer representing the length of the water wave

    sLongInputLine = input().strip()  # Read the second line of input
    anComingSec = list(map(int, sLongInputLine.split()))  # Parse the second line of input and store the arrival times of the humans

    # Initialize the start time of the water wave to the arrival time of the first human
    nStart = anComingSec[0]
    nWaterLife = 0  # Initialize the life of the water wave
    nNextHumanIndex = 0  # Initialize a counter for the index of the next human

    # Calculate the life of the water wave by iterating through the humans and finding the overlapping periods
    while nNextHumanIndex < nHumanNumber:
        nStop = nStart + nWaterLength  # Calculate the stop time of the water wave

        # Check if the next human arrives before the stop time of the water wave
        if anComingSec[nNextHumanIndex] < nStop:
            # If the next human arrives before the stop time, we need to find the maximum stop time that includes both the current and next human
            while nNextHumanIndex < nHumanNumber and anComingSec[nNextHumanIndex] < nStop:
                if nStop <= anComingSec[nNextHumanIndex] + nWaterLength:
                    nStop = anComingSec[nNextHumanIndex] + nWaterLength  # Update the stop time to include the next human
                nNextHumanIndex += 1  # Move to the next human

            # If we have reached the end of the array, we have found the maximum stop time that includes all the humans
            if nNextHumanIndex == nHumanNumber:
                nWaterLife += (nStop - nStart)  # Calculate the life of the water wave based on the start and stop times
                break  # Exit the loop
        else:
            # If the next human arrives after the stop time of the water wave, we can update the start time to the arrival time of the next human and continue the loop
            nStart = nStop
            if nStart < anComingSec[nNextHumanIndex]:
                nStart = anComingSec[nNextHumanIndex]  # Update the start time to the arrival time of the next human

    # Print the life of the water wave to the standard output stream
    print(nWaterLife)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
