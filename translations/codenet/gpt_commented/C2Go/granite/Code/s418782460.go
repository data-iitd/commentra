
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Local variables
	var sInput string
	var psWord []string
	var psInput []string

	var nHumanNumber int
	var nNextHumanIndex int
	var nWaterLength int
	var nWaterLife int
	var nStart int
	var nStop int

	var nIndex int
	var i int
	var j int

	// Read the first line of input containing number of humans and water length
	reader := bufio.NewReader(os.Stdin)
	sInput, _ = reader.ReadString('\n')
	sInput = strings.TrimSpace(sInput)
	psInput = strings.Split(sInput, " ") // Tokenize the input
	nHumanNumber, _ = strconv.Atoi(psInput[0]) // Convert first token to number of humans
	nWaterLength, _ = strconv.Atoi(psInput[1]) // Convert to water length

	// Read the second line of input containing the coming seconds of humans
	sInput, _ = reader.ReadString('\n')
	sInput = strings.TrimSpace(sInput)
	psInput = strings.Split(sInput, " ") // Tokenize the input
	for i = 0; i < nHumanNumber; i++ {
		anComingSec[i], _ = strconv.Atoi(psInput[i]) // Store each coming second in the array
	}

	// Initialize the start time for water coverage
	nStart = anComingSec[0]

	// Main loop to calculate the total water life duration
	for nNextHumanIndex < nHumanNumber {
		if nNextHumanIndex == nHumanNumber {
			break // Exit if all humans have been processed
		} else {
			nStop = nStart + nWaterLength // Calculate stop time based on water length
			if anComingSec[nNextHumanIndex] < nStop {
				// Process humans that arrive before the current stop time
				for nNextHumanIndex < nHumanNumber && anComingSec[nNextHumanIndex] < nStop {
					if nStop <= anComingSec[nNextHumanIndex] + nWaterLength {
						nStop = anComingSec[nNextHumanIndex] + nWaterLength // Extend stop time if necessary
						nNextHumanIndex++ // Move to the next human
					}
				}
				if nNextHumanIndex == nHumanNumber {
					nWaterLife = nWaterLife + (nStop - nStart) // Add to water life if all humans are processed
					break
				}
			}
			nWaterLife = nWaterLife + (nStop - nStart) // Add the duration of water coverage
			nStart = nStop // Update start time for the next iteration
			if nStart < anComingSec[nNextHumanIndex] {
				nStart = anComingSec[nNextHumanIndex] // Adjust start time if necessary
			}
		}
	}

	// Output the total water life duration
	fmt.Println(nWaterLife)
}

// END-OF-CODE