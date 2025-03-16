# -*- coding: utf-8 -*-

import sys

# <START-OF-CODE>

def main():
    # read line 1
    line1 = sys.stdin.readline()
    line1 = line1.strip()
    line1 = line1.split()
    nHumanNumber = int(line1[0])
    nWaterLength = int(line1[1])

    # read line 2
    line2 = sys.stdin.readline()
    line2 = line2.strip()
    line2 = line2.split()
    anComingSec = []
    for i in range(nHumanNumber):
        anComingSec.append(int(line2[i]))

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


if __name__ == "__main__":
    main()

# 