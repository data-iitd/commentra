package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	MAX_STRING = 30
	MAX_LINE   = 2000000
	MAX_HUMAN  = 200000
)

func main() {
	var sLongInputLine string // Buffer for long input line
	var anComingSec [MAX_HUMAN]int // Array to store the coming seconds of humans

	var nHumanNumber, nNextHumanIndex, nWaterLength, nWaterLife, nStart, nStop int

	// Read the first line of input containing number of humans and water length
	var sInput string
	fmt.Scanln(&sInput)
	parts := strings.Fields(sInput) // Tokenize the input
	nHumanNumber, _ = strconv.Atoi(parts[0]) // Convert first token to number of humans
	nWaterLength, _ = strconv.Atoi(parts[1]) // Convert to water length

	// Read the second line of input containing the coming seconds of humans
	fmt.Scanln(&sLongInputLine)
	parts = strings.Fields(sLongInputLine) // Tokenize the input
	for i := 0; i < nHumanNumber; i++ {
		anComingSec[i], _ = strconv.Atoi(parts[i]) // Store each coming second in the array
	}

	// Initialize the start time for water coverage
	nStart = anComingSec[0]

	// Main loop to calculate the total water life duration
	for nNextHumanIndex < nHumanNumber {
		nStop = nStart + nWaterLength // Calculate stop time based on water length
		if anComingSec[nNextHumanIndex] < nStop {
			// Process humans that arrive before the current stop time
			for nNextHumanIndex < nHumanNumber && anComingSec[nNextHumanIndex] < nStop {
				if nStop <= anComingSec[nNextHumanIndex]+nWaterLength {
					nStop = anComingSec[nNextHumanIndex] + nWaterLength // Extend stop time if necessary
					nNextHumanIndex++ // Move to the next human
				}
			}
			if nNextHumanIndex == nHumanNumber {
				nWaterLife += nStop - nStart // Add to water life if all humans are processed
				break
			}
		}
		nWaterLife += nStop - nStart // Add the duration of water coverage
		nStart = nStop // Update start time for the next iteration
		if nStart < anComingSec[nNextHumanIndex] {
			nStart = anComingSec[nNextHumanIndex] // Adjust start time if necessary
		}
	}

	// Output the total water life duration
	fmt.Println(nWaterLife)
}

// <END-OF-CODE>
