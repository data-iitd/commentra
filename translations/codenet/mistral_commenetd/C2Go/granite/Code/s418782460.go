

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var (
		sLongInputLine string
		sInput           string
		psWord           string
		psInput          string
		nHumanNumber     int
		nNextHumanIndex int
		nWaterLength     int
		nWaterLife       int
		nStart            int
		nStop             int
		nIndex            int
		i                 int
		j                 int
	)

	// Read the first line of input
	scanner := bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		sInput = scanner.Text()
		if strings.Contains(sInput, "\n") {
			sInput = sInput[:len(sInput)-1]
		}
		psInput = strings.Split(sInput, " ")[0]
		nHumanNumber, _ = strconv.Atoi(psInput)
		psInput = strings.Split(sInput, " ")[1]
		nWaterLength, _ = strconv.Atoi(psInput)
	}

	// Read the second line of input
	if scanner.Scan() {
		sLongInputLine = scanner.Text()
		if strings.Contains(sLongInputLine, "\n") {
			sLongInputLine = sLongInputLine[:len(sLongInputLine)-1]
		}
		// Parse the second line of input and store the arrival times of the humans in the anComingSec array
		anComingSec := make([]int, nHumanNumber)
		for i = 0; i < nHumanNumber; i++ {
			psWord = strings.Split(sLongInputLine, " ")[i]
			anComingSec[i], _ = strconv.Atoi(psWord)
		}

		// Initialize the start time of the water wave to the arrival time of the first human
		nStart = anComingSec[0]

		// Calculate the life of the water wave by iterating through the humans and finding the overlapping periods
		for nNextHumanIndex = 0; nNextHumanIndex < nHumanNumber; {
			if nNextHumanIndex == nHumanNumber {
				break
			} else {
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
						break
					}
				}

				// If the next human arrives after the stop time of the water wave, we can update the start time to the arrival time of the next human and continue the loop
				nStart = nStop
				if nStart < anComingSec[nNextHumanIndex] {
					nStart = anComingSec[nNextHumanIndex] // Update the start time to the arrival time of the next human
				}
			}
		}

		// Print the life of the water wave to the standard output stream
		fmt.Println(nWaterLife)
	}
}

