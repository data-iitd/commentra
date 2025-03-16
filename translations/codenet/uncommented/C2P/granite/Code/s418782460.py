
import sys

sInput = input()
psInput = sInput.split(" ")
nHumanNumber = int(psInput[0])
nWaterLength = int(psInput[1])

sLongInputLine = input()
psInput = sLongInputLine.split(" ")
anComingSec = [int(i) for i in psInput]

nStart = anComingSec[0]
nWaterLife = 0
nNextHumanIndex = 0

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
                nWaterLife += (nStop - nStart)
                break
        nWaterLife += (nStop - nStart)
        nStart = nStop
        if nStart < anComingSec[nNextHumanIndex]:
            nStart = anComingSec[nNextHumanIndex]

print(nWaterLife)

