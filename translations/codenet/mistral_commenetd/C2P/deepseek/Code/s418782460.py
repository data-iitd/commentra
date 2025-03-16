import sys

MAX_STRING = 30
MAX_LINE = 2000000
MAX_HUMAN = 200000

sLongInputLine = ""
anComingSec = []

def main():
    global sLongInputLine, anComingSec

    sInput = ""
    psInput = None
    psWord = None
    nHumanNumber = 0
    nNextHumanIndex = 0
    nWaterLength = 0
    nWaterLife = 0
    nStart = 0
    nStop = 0
    nIndex = 0
    i = 0
    j = 0

    sInput = input().strip()
    psInput = sInput.split(" ")
    nHumanNumber = int(psInput[0])
    nWaterLength = int(psInput[1])

    sLongInputLine = input().strip()
    anComingSec = list(map(int, sLongInputLine.split(" ")))

    nStart = anComingSec[0]

    while nNextHumanIndex < nHumanNumber:
        nStop = nStart + nWaterLength

        if nNextHumanIndex < nHumanNumber and anComingSec[nNextHumanIndex] < nStop:
            while nNextHumanIndex < nHumanNumber and anComingSec[nNextHumanIndex] < nStop:
                if nStop <= anComingSec[nNextHumanIndex] + nWaterLength:
                    nStop = anComingSec[nNextHumanIndex] + nWaterLength
                    nNextHumanIndex += 1

            nWaterLife += (nStop - nStart)
            break

        nStart = nStop
        if nStart < anComingSec[nNextHumanIndex]:
            nStart = anComingSec[nNextHumanIndex]

    print(nWaterLife)

if __name__ == "__main__":
    main()
