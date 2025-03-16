
import sys

# Define constants for maximum sizes
MAX_STRING = 30
MAX_LINE = 2000000
MAX_HUMAN = 200000

# Declare global arrays and variables
sLongInputLine = ""
anComingSec = [0] * MAX_HUMAN

def main():
    # Declare variables for input and processing
    sInput = ""
    psWord = None
    psInput = None

    nHumanNumber = 0
    nNextHumanIndex = 0
    nWaterLength = 0
    nWaterLife = 0
    nStart = 0
    nStop = 0

    nIndex = 0
    i = 0
    j = 0

    # Read the first line of input which contains the number of humans and the water length
    sInput = input()
    psInput = sInput.split(" ")
    nHumanNumber = int(psInput[0])
    nWaterLength = int(psInput[1])

    # Read the second line of input which contains the seconds when each human arrives
    sLongInputLine = input()
    psInput = sLongInputLine.split(" ")
    for i in range(nHumanNumber):
        anComingSec[i] = int(psInput[i])

    # Initialize the start time to the first human's arrival time
    nStart = anComingSec[0]

    # Process the data to calculate the water life
    while nNextHumanIndex < nHumanNumber:
        if nNextHumanIndex == nHumanNumber:
            break
        else:
            nStop = nStart + nWaterLength
            if anComingSec[nNextHumanIndex] < nStop:
                while nNextHumanIndex < nHumanNumber and anComingSec[nNextHumanIndex] < nStop:
                    if nStop <= anComingSec[nNextHumanIndex] + nWaterLength:
                        nStop = anComingSec[nNextHumanIndex] + nWaterLength
                        nNextHumanIndex += 1
                if nNextHumanIndex == nHumanNumber:
                    nWaterLife = nWaterLife + (nStop - nStart)
                    break
            nWaterLife = nWaterLife + (nStop - nStart)
            nStart = nStop
            if nStart < anComingSec[nNextHumanIndex]:
                nStart = anComingSec[nNextHumanIndex]

    # Output the result which is the total water life
    print(nWaterLife)

if __name__ == "__main__":
    main()

