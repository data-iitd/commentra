package main

import (
	"bufio"
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

var (
	sLongInputLine [MAX_LINE + 1]byte
	anComingSec    [MAX_HUMAN]int
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	
	var sInput [MAX_STRING + 1]byte
	var psInput, psWord *byte
	var nHumanNumber, nWaterLength, nWaterLife, nStart, nStop, nNextHumanIndex int
	
	// Read the first line of input
	sInput, _ = reader.ReadBytes('\n')
	if len(sInput) > 0 && sInput[len(sInput)-2] == '\r' {
		sInput[len(sInput)-2] = 0
	} else {
		sInput[len(sInput)-1] = 0
	}
	psInput = sInput[:strings.IndexByte(string(sInput), ' ')]
	nHumanNumber, _ = strconv.Atoi(string(psInput))
	psInput = sInput[strings.IndexByte(string(sInput), ' ')+1:]
	nWaterLength, _ = strconv.Atoi(string(psInput))
	
	// Read the second line of input
	sLongInputLine, _ = reader.ReadBytes('\n')
	if len(sLongInputLine) > 0 && sLongInputLine[len(sLongInputLine)-2] == '\r' {
		sLongInputLine[len(sLongInputLine)-2] = 0
	} else {
		sLongInputLine[len(sLongInputLine)-1] = 0
	}
	
	// Parse the second line of input and store the arrival times of the humans in the anComingSec array
	words := strings.Split(string(sLongInputLine), " ")
	for i := 0; i < nHumanNumber; i++ {
		anComingSec[i], _ = strconv.Atoi(words[i])
	}
	
	// Initialize the start time of the water wave to the arrival time of the first human
	nStart = anComingSec[0]
	
	// Calculate the life of the water wave by iterating through the humans and finding the overlapping periods
	for nNextHumanIndex < nHumanNumber {
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
	}
	
	// Print the life of the water wave to the standard output stream
	fmt.Println(nWaterLife)
}

