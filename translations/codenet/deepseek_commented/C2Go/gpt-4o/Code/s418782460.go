package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define constants for maximum sizes
const (
	MAX_STRING  = 30
	MAX_LINE    = 2000000
	MAX_HUMAN   = 200000
)

func main() {
	// Declare variables for input and processing
	var sInput string
	var anComingSec [MAX_HUMAN]int

	var nHumanNumber, nWaterLength int
	var nNextHumanIndex, nWaterLife int

	// Read the first line of input which contains the number of humans and the water length
	fmt.Scanln(&sInput)
	parts := strings.Fields(sInput)
	nHumanNumber, _ = strconv.Atoi(parts[0])
	nWaterLength, _ = strconv.Atoi(parts[1])

	// Read the second line of input which contains the seconds when each human arrives
	fmt.Scanln(&sInput)
	parts = strings.Fields(sInput)
	for i := 0; i < nHumanNumber; i++ {
		anComingSec[i], _ = strconv.Atoi(parts[i])
	}

	// Initialize the start time to the first human's arrival time
	nStart := anComingSec[0]

	// Process the data to calculate the water life
	for nNextHumanIndex < nHumanNumber {
		nStop := nStart + nWaterLength
		if anComingSec[nNextHumanIndex] < nStop {
			for nNextHumanIndex < nHumanNumber && anComingSec[nNextHumanIndex] < nStop {
				if nStop <= anComingSec[nNextHumanIndex]+nWaterLength {
					nStop = anComingSec[nNextHumanIndex] + nWaterLength
					nNextHumanIndex++
				}
			}
			if nNextHumanIndex == nHumanNumber {
				nWaterLife += nStop - nStart
				break
			}
		}
		nWaterLife += nStop - nStart
		nStart = nStop
		if nStart < anComingSec[nNextHumanIndex] {
			nStart = anComingSec[nNextHumanIndex]
		}
	}

	// Output the result which is the total water life
	fmt.Println(nWaterLife)
}

// <END-OF-CODE>
