
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Global variables
var sLongInputLine string = "" // Buffer for long input line
var anComingSec []int = make([]int, 200000) // Array to store the coming seconds of humans

func main() {
	// Local variables
	var sInput string = "" // Buffer for the first line of input
	var psWord string = "" // Pointer for tokenizing words
	var psInput string = "" // Pointer for tokenizing input

	var nHumanNumber int = 0 // Number of humans
	var nNextHumanIndex int = 0 // Index for the next human
	var nWaterLength int = 0 // Length of water coverage
	var nWaterLife int = 0 // Total water life duration
	var nStart int = 0 // Start time for water coverage
	var nStop int = 0 // Stop time for water coverage

	var nIndex int = 0 // General index variable
	var i int = 0 // Loop counter
	var j int = 0 // Loop counter

	// Read the first line of input containing number of humans and water length
	sInput = readLine()
	psInput = strings.Split(sInput, " ")[0]
	nHumanNumber, _ = strconv.Atoi(psInput) // Convert first token to number of humans
	psInput = strings.Split(sInput, " ")[1]
	nWaterLength, _ = strconv.Atoi(psInput) // Convert to water length

	// Read the second line of input containing the coming seconds of humans
	sLongInputLine = readLine()
	psInput = strings.Split(sLongInputLine, " ")[0]
	anComingSec[0], _ = strconv.Atoi(psInput) // Store each coming second in the array
	for i = 1; i < nHumanNumber; i++ {
		psInput = strings.Split(sLongInputLine, " ")[i]
		anComingSec[i], _ = strconv.Atoi(psInput) // Store each coming second in the array
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
					if nStop <= anComingSec[nNextHumanIndex]+nWaterLength {
						nStop = anComingSec[nNextHumanIndex] + nWaterLength // Extend stop time if necessary
						nNextHumanIndex++                                   // Move to the next human
					}
				}
				if nNextHumanIndex == nHumanNumber {
					nWaterLife = nWaterLife + (nStop - nStart) // Add to water life if all humans are processed
					break
				}
			}
			nWaterLife = nWaterLife + (nStop - nStart) // Add the duration of water coverage
			nStart = nStop                             // Update start time for the next iteration
			if nStart < anComingSec[nNextHumanIndex] {
				nStart = anComingSec[nNextHumanIndex] // Adjust start time if necessary
			}
		}
	}

	// Output the total water life duration
	fmt.Println(nWaterLife)
}

func readLine() string {
	reader := bufio.NewReader(os.Stdin)
	sInput, _ := reader.ReadString('\n')
	return sInput
}

