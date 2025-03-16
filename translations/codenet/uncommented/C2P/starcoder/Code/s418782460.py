#pragma warning(disable:4996)
import sys
import re

def main():
	sInput = sys.stdin.readline()
	sInput = sInput.strip()
	nHumanNumber = int(sInput)
	sInput = sys.stdin.readline()
	sInput = sInput.strip()
	nWaterLength = int(sInput)
	sLongInputLine = sys.stdin.readline()
	sLongInputLine = sLongInputLine.strip()
	anComingSec = re.split("\s+", sLongInputLine)
	anComingSec = [int(x) for x in anComingSec]
	nStart = anComingSec[0]
	nStop = 0
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
					nWaterLife = nWaterLife + (nStop - nStart)
					break
			nWaterLife = nWaterLife + (nStop - nStart)
			nStart = nStop
			if nStart < anComingSec[nNextHumanIndex]:
				nStart = anComingSec[nNextHumanIndex]
	print(nWaterLife)

if __name__ == "__main__":
	main()

