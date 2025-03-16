# Disable warning for unused variables
# pylint: disable=W0612

# Import necessary modules
import sys

# Define constants
MAX_STRING = 30
MAX_LINE = 2000000
MAX_HUMAN = 200000

# Global variables
sLongInputLine = ""  # Buffer for long input line
anComingSec = []  # Array to store the coming seconds of humans

def main():
    # Local variables
    sInput = ""  # Buffer for the first line of input
    psInput = None  # Pointer for tokenizing input

    nHumanNumber = 0  # Number of humans
    nNextHumanIndex = 0  # Index for the next human
    nWaterLength = 0  # Length of water coverage
    nWaterLife = 0  # Total water life duration
    nStart = 0  # Start time for water coverage
    nStop = 0  # Stop time for water coverage

    # Read the first line of input containing number of humans and water length
    sInput = input().strip()
    psInput = sInput.split()
    nHumanNumber = int(psInput[0])
    nWaterLength = int(psInput[1])

    # Read the second line of input containing the coming seconds of humans
    sLongInputLine = input().strip()
    anComingSec = list(map(int, sLongInputLine.split()))

    # Initialize the start time for water coverage
    nStart = anComingSec[0]

    # Main loop to calculate the total water life duration
    while nNextHumanIndex < nHumanNumber:
        nStop = nStart + nWaterLength
        if nNextHumanIndex < nHumanNumber and anComingSec[nNextHumanIndex] < nStop:
            # Process humans that arrive before the current stop time
            while nNextHumanIndex < nHumanNumber and anComingSec[nNextHumanIndex] < nStop:
                if nStop <= anComingSec[nNextHumanIndex] + nWaterLength:
                    nStop = anComingSec[nNextHumanIndex] + nWaterLength
                    nNextHumanIndex += 1
            if nNextHumanIndex == nHumanNumber:
                nWaterLife += nStop - nStart
                break
        nWaterLife += nStop - nStart
        nStart = nStop
        if nStart < anComingSec[nNextHumanIndex]:
            nStart = anComingSec[nNextHumanIndex]

    # Output the total water life duration
    print(nWaterLife)

if __name__ == "__main__":
    main()
