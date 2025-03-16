package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	MAX_STRING  = 30
	MAX_LINE    = 2000000
	MAX_HUMAN   = 200000
)

func main() {
	var sLongInputLine string
	var anComingSec [MAX_HUMAN]int

	var nHumanNumber, nNextHumanIndex, nWaterLength, nWaterLife, nStart, nStop int

	// read line 1
	var sInput string
	fmt.Scanln(&sInput)
	parts := strings.Fields(sInput)
	nHumanNumber, _ = strconv.Atoi(parts[0])
	nWaterLength, _ = strconv.Atoi(parts[1])

	// read line 2
	fmt.Scanln(&sLongInputLine)
	comingSecParts := strings.Fields(sLongInputLine)
	for i := 0; i < nHumanNumber; i++ {
		anComingSec[i], _ = strconv.Atoi(comingSecParts[i])
	}

	nStart = anComingSec[0]

	for nNextHumanIndex < nHumanNumber {
		if nNextHumanIndex == nHumanNumber {
			break
		} else {
			nStop = nStart + nWaterLength
			if anComingSec[nNextHumanIndex] < nStop {
				for nNextHumanIndex < nHumanNumber && anComingSec[nNextHumanIndex] < nStop {
					if nStop <= anComingSec[nNextHumanIndex]+nWaterLength {
						nStop = anComingSec[nNextHumanIndex] + nWaterLength
						nNextHumanIndex++
					}
				}
				if nNextHumanIndex == nHumanNumber {
					nWaterLife += (nStop - nStart)
					break
				}
			}
			nWaterLife += (nStop - nStart)
			nStart = nStop
			if nStart < anComingSec[nNextHumanIndex] {
				nStart = anComingSec[nNextHumanIndex]
			}
		}
	}
	fmt.Println(nWaterLife)
}

// <END-OF-CODE>
