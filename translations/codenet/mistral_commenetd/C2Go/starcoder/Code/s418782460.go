
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

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
		sInput         string
		psWord         *string
		psInput        *string
		nHumanNumber   int
		nNextHumanIndex int
		nWaterLength   int
		nWaterLife     int
		nStart         int
		nStop          int
		nIndex         int
		i              int
		j              int
	)

<<<<<<< HEAD
	sLongInputLine = ""
	sInput = ""
	psWord = nil
	psInput = nil
	nHumanNumber = 0
	nNextHumanIndex = 0
	nWaterLength = 0
	nWaterLife = 0
	nStart = 0
	nStop = 0
	nIndex = 0
	i = 0
	j = 0

	// Read the first line of input
	sInput = readLine()
	psInput = strings.Split(sInput, " ")
	nHumanNumber, _ = strconv.Atoi(psInput[0])
	psInput = strings.Split(sInput, " ")
	nWaterLength, _ = strconv.Atoi(psInput[1])

	// Read the second line of input
	sLongInputLine = readLine()

	// Parse the second line of input and store the arrival times of the humans in the anComingSec array
	for i = 0; i < nHumanNumber; i++ {
		psWord = strings.Split(sLongInputLine, " ")
=======
	// Read the first line of input
	fmt.Scanf("%s\n", &sInput)
	psInput = strings.Split(sInput, " ")
	nHumanNumber, _ = strconv.Atoi(psInput[0])
	nWaterLength, _ = strconv.Atoi(psInput[1])

	// Read the second line of input
	sLongInputLine = bufio.NewReader(os.Stdin).ReadString('\n')
	sLongInputLine = strings.TrimSuffix(sLongInputLine, "\n")
	psWord = strings.Split(sLongInputLine, " ")

	// Parse the second line of input and store the arrival times of the humans in the anComingSec array
	anComingSec := make([]int, nHumanNumber)
	for i = 0; i < nHumanNumber; i++ {
>>>>>>> 98c87cb78a (data updated)
		anComingSec[i], _ = strconv.Atoi(psWord[i])
	}

	// Initialize the start time of the water wave to the arrival time of the first human
	nStart = anComingSec[0]

	// Calculate the life of the water wave by iterating through the humans and finding the overlapping periods
	for nNextHumanIndex = 0; nNextHumanIndex < nHumanNumber; nNextHumanIndex++ {
<<<<<<< HEAD
		if nNextHumanIndex == nHumanNumber {
			break
		} else {
			// Calculate the stop time of the water wave based on the start time and the length of the water wave
			nStop = nStart + nWaterLength

			// Check if the next human arrives before the stop time of the water wave
			if anComingSec[nNextHumanIndex] < nStop {
				// If the next human arrives before the stop time, we need to find the maximum stop time that includes both the current and next human
				for nNextHumanIndex < nHumanNumber && anComingSec[nNextHumanIndex] < nStop {
					if nStop <= anComingSec[nNextHumanIndex] + nWaterLength {
						nStop = anComingSec[nNextHumanIndex] + nWaterLength
						nNextHumanIndex++
					}
				}

				// If we have reached the end of the array, we have found the maximum stop time that includes all the humans
				if nNextHumanIndex == nHumanNumber {
					nWaterLife += (nStop - nStart)
					break
				}
			}

			// If the next human arrives after the stop time of the water wave, we can update the start time to the arrival time of the next human and continue the loop
			nStart = nStop
			if nStart < anComingSec[nNextHumanIndex] {
				nStart = anComingSec[nNextHumanIndex]
			}
		}
=======
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
>>>>>>> 98c87cb78a (data updated)
	}

	// Print the life of the water wave to the standard output stream
	fmt.Printf("%d\n", nWaterLife)
}

<<<<<<< HEAD
func readLine() string {
	var (
		sInput string
	)

	sInput = bufio.NewReader(os.Stdin).ReadString('\n')
	sInput = strings.TrimSuffix(sInput, "\n")
	sInput = strings.TrimSuffix(sInput, "\r")

	return sInput
}

=======
>>>>>>> 98c87cb78a (data updated)
