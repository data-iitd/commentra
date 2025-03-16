

import sys

sLongInputLine = ""
anComingSec = []

for sInput in sys.stdin:
    sInput = sInput.strip()
    if "\n" in sInput:
        sInput = sInput.replace("\n", "")
    psWord = sInput.split(" ")
    if len(psWord) == 2:
        nHumanNumber = int(psWord[0])
        nWaterLength = int(psWord[1])
    else:
        anComingSec.append(int(psWord[0]))

nStart = anComingSec[0]
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
        nStart = nStop
        if nStart < anComingSec[nNextHumanIndex]:
            nStart = anComingSec[nNextHumanIndex]
    if nNextHumanIndex == nHumanNumber:
        nWaterLife += (nStop - nStart)
        break

print(nWaterLife)

