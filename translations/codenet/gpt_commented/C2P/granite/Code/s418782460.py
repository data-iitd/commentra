
import sys

# Read the first line of input containing number of humans and water length
sInput = sys.stdin.readline().strip()
psInput = sInput.split()
nHumanNumber = int(psInput[0])
nWaterLength = int(psInput[1])

# Read the second line of input containing the coming seconds of humans
sLongInputLine = sys.stdin.readline().strip()
psInput = sLongInputLine.split()
anComingSec = [int(x) for x in psInput]

# Initialize the start time for water coverage
nStart = anComingSec[0]

# Main loop to calculate the total water life duration
nWaterLife = 0
nNextHumanIndex = 0
while nNextHumanIndex < nHumanNumber:
    if nNextHumanIndex == nHumanNumber:
        break
    nStop = nStart + nWaterLength
    if anComingSec[nNextHumanIndex] < nStop:
        while nNextHumanIndex < nHumanNumber and anComingSec[nNextHumanIndex] < nStop:
            if nStop <= anComingSec[nNextHumanIndex] + nWaterLength:
                nStop = anComingSec[nNextHumanIndex] + nWaterLength
                nNextHumanIndex += 1
            else:
                break
    nWaterLife += (nStop - nStart)
    nStart = nStop
    if nStart < anComingSec[nNextHumanIndex]:
        nStart = anComingSec[nNextHumanIndex]

# Output the total water life duration
print(nWaterLife)

# End of the program

