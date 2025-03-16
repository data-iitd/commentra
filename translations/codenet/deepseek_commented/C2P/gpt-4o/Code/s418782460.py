import sys

# Define constants for maximum sizes
MAX_STRING = 30
MAX_LINE = 2000000
MAX_HUMAN = 200000

# Declare global variables
sLongInputLine = ""
anComingSec = []

def main():
    global sLongInputLine, anComingSec

    # Read the first line of input which contains the number of humans and the water length
    sInput = input().strip()
    nHumanNumber, nWaterLength = map(int, sInput.split())

    # Read the second line of input which contains the seconds when each human arrives
    sLongInputLine = input().strip()
    anComingSec = list(map(int, sLongInputLine.split()))

    # Initialize the start time to the first human's arrival time
    nStart = anComingSec[0]
    nNextHumanIndex = 0
    nWaterLife = 0

    # Process the data to calculate the water life
    while nNextHumanIndex < nHumanNumber:
        nStop = nStart + nWaterLength
        if anComingSec[nNextHumanIndex] < nStop:
            while nNextHumanIndex < nHumanNumber and anComingSec[nNextHumanIndex] < nStop:
                if nStop <= anComingSec[nNextHumanIndex] + nWaterLength:
                    nStop = anComingSec[nNextHumanIndex] + nWaterLength
                    nNextHumanIndex += 1
            if nNextHumanIndex == nHumanNumber:
                nWaterLife += (nStop - nStart)
                break
        nWaterLife += (nStop - nStart)
        nStart = nStop
        if nStart < anComingSec[nNextHumanIndex]:
            nStart = anComingSec[nNextHumanIndex]

    # Output the result which is the total water life
    print(nWaterLife)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
