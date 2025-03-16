import sys

MAX_STRING = 30
MAX_LINE = 2000000
MAX_HUMAN = 200000

sLongInputLine = ""
anComingSec = []

def main():
    global sLongInputLine, anComingSec

    # Read line 1
    sInput = input().strip()
    nHumanNumber, nWaterLength = map(int, sInput.split())

    sLongInputLine = input().strip()
    anComingSec = list(map(int, sLongInputLine.split()))

    nStart = anComingSec[0]
    nNextHumanIndex = 0
    nWaterLife = 0

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

    print(nWaterLife)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
