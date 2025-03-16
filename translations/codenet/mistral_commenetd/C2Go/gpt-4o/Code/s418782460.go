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

var (
	sLongInputLine = make([]byte, MAX_LINE+1) // Initialize a byte slice to store a long input line
	anComingSec    = make([]int, MAX_HUMAN)    // Initialize a slice to store the arrival time of humans
)

func main() {
	var sInput string // Initialize a string to store a single input line
	var nHumanNumber, nWaterLength, nStart, nStop, nWaterLife int // Initialize variables

	// Read the first line of input
	fmt.Scanln(&sInput) // Read a line from the standard input
	parts := strings.Fields(sInput) // Split the input line into parts
	nHumanNumber, _ = strconv.Atoi(parts[0]) // Convert the first token to an integer representing the number of humans
	nWaterLength, _ = strconv.Atoi(parts[1]) // Convert the second token to an integer representing the length of the water wave

	// Read the second line of input
	fmt.Scanln(&sLongInputLine) // Read a line from the standard input
	// Parse the second line of input and store the arrival times of the humans in the anComingSec slice
	for i := 0; i < nHumanNumber; i++ {
		var arrivalTime int
		fmt.Sscanf(string(sLongInputLine), "%d", &arrivalTime) // Read the arrival time
		anComingSec[i] = arrivalTime // Store it in the anComingSec slice
		sLongInputLine = sLongInputLine[strings.IndexByte(string(sLongInputLine), ' ')+1:] // Remove the processed part
	}

	// Initialize the start time of the water wave to the arrival time of the first human
	nStart = anComingSec[0]

	// Calculate the life of the water wave by iterating through the humans and finding the overlapping periods
	nNextHumanIndex := 0 // Initialize a counter for the index of the next human

	for nNextHumanIndex < nHumanNumber {
		// Calculate the stop time of the water wave based on the start time and the length of the water wave
		nStop = nStart + nWaterLength

		// Check if the next human arrives before the stop time of the water wave
		if anComingSec[nNextHumanIndex] < nStop {
			// If the next human arrives before the stop time, we need to find the maximum stop time that includes both the current and next human
			for nNextHumanIndex < nHumanNumber && anComingSec[nNextHumanIndex] < nStop {
				if nStop <= anComingSec[nNextHumanIndex]+nWaterLength {
					nStop = anComingSec[nNextHumanIndex] + nWaterLength // Update the stop time to include the next human
					nNextHumanIndex++ // Move to the next human
				}
			}

			// If we have reached the end of the array, we have found the maximum stop time that includes all the humans
			if nNextHumanIndex == nHumanNumber {
				nWaterLife += (nStop - nStart) // Calculate the life of the water wave based on the start and stop times
				break // Exit the loop
			}
		}

		// If the next human arrives after the stop time of the water wave, we can update the start time to the arrival time of the next human and continue the loop
		nStart = nStop
		if nStart < anComingSec[nNextHumanIndex] {
			nStart = anComingSec[nNextHumanIndex] // Update the start time to the arrival time of the next human
		}
	}

	// Print the life of the water wave to the standard output
	fmt.Println(nWaterLife)
}

// <END-OF-CODE>
