#pragma warning(disable:4996)
import sys

# Global variables
sLongInputLine = "" # Buffer for long input line
anComingSec = [] # Array to store the coming seconds of humans

def main():
    # Local variables
    sInput = "" # Buffer for the first line of input
    psWord = None # Pointer for tokenizing words
    psInput = None # Pointer for tokenizing input

    nHumanNumber = 0 # Number of humans
    nNextHumanIndex = 0 # Index for the next human
    nWaterLength = 0 # Length of water coverage
    nWaterLife = 0 # Total water life duration
    nStart = 0 # Start time for water coverage
    nStop = 0 # Stop time for water coverage

    nIndex = 0 # General index variable
    i = 0 # Loop counter
    j = 0 # Loop counter

    # Read the first line of input containing number of humans and water length
    sInput = sys.stdin.readline()
    sInput = sInput.strip()
    psInput = sInput.split(" ")
    nHumanNumber = int(psInput[0])
    nWaterLength = int(psInput[1])

    # Read the second line of input containing the coming seconds of humans
    sLongInputLine = sys.stdin.readline()
    sLongInputLine = sLongInputLine.strip()
    psInput = sLongInputLine.split(" ")
    for i in range(nHumanNumber):
        anComingSec.append(int(psInput[i]))

    # Initialize the start time for water coverage
    nStart = anComingSec[0]

    # Main loop to calculate the total water life duration
    while nNextHumanIndex < nHumanNumber:
        if nNextHumanIndex == nHumanNumber:
            break # Exit if all humans have been processed
        else:
            nStop = nStart + nWaterLength # Calculate stop time based on water length
            if anComingSec[nNextHumanIndex] < nStop:
                # Process humans that arrive before the current stop time
                while nNextHumanIndex < nHumanNumber and anComingSec[nNextHumanIndex] < nStop:
                    if nStop <= anComingSec[nNextHumanIndex] + nWaterLength:
                        nStop = anComingSec[nNextHumanIndex] + nWaterLength # Extend stop time if necessary
                        nNextHumanIndex += 1 # Move to the next human
                if nNextHumanIndex == nHumanNumber:
                    nWaterLife += (nStop - nStart) # Add to water life if all humans are processed
                    break
            nWaterLife += (nStop - nStart) # Add the duration of water coverage
            nStart = nStop # Update start time for the next iteration
            if nStart < anComingSec[nNextHumanIndex]:
                nStart = anComingSec[nNextHumanIndex] # Adjust start time if necessary
        nNextHumanIndex += 1

    # Output the total water life duration
    print(nWaterLife)

    return 0 # End of the program

if __name__ == "__main__":
    main()

