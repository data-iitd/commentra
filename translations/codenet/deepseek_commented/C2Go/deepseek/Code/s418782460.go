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
	sLongInputLine [MAX_LINE + 1]string
	anComingSec    [MAX_HUMAN]int
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Declare variables for input and processing
	var sInput [MAX_STRING + 1]string
	var psWord *string
	var psInput *string

	var nHumanNumber int
	var nNextHumanIndex int
	var nWaterLength int
	var nWaterLife int
	var nStart int
	var nStop int

	var nIndex int
	var i int
	var j int

	// Read the first line of input which contains the number of humans and the water length
	sInput, _ = reader.ReadString('\n')
	sInput = strings.TrimRight(sInput, "\n")
	psInput = strings.Split(sInput, " ")
	nHumanNumber, _ = strconv.Atoi(psInput[0])
	nWaterLength, _ = strconv.Atoi(psInput[1])

	// Read the second line of input which contains the seconds when each human arrives
	sLongInputLine, _ = reader.ReadString('\n')
	sLongInputLine = strings.TrimRight(sLongInputLine, "\n")
	psInput = strings.Split(sLongInputLine, " ")
	for i = 0; i < nHumanNumber; i++ {
		anComingSec[i], _ = strconv.Atoi(psInput[i])
	}

	// Initialize the start time to the first human's arrival time
	nStart = anComingSec[0]

	// Process the data to calculate the water life
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
					nWaterLife = nWaterLife + (nStop - nStart)
					break
				}
			}
			nWaterLife = nWaterLife + (nStop - nStart)
			nStart = nStop
			if nStart < anComingSec[nNextHumanIndex] {
				nStart = anComingSec[nNextHumanIndex]
			}
		}
	}

	// Output the result which is the total water life
	fmt.Println(nWaterLife)
}

