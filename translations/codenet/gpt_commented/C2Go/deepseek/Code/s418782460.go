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

	// Local variables
	var sInput [MAX_STRING + 1]string
	var psInput []string
	var nHumanNumber, nNextHumanIndex, nWaterLength, nWaterLife, nStart, nStop int

	// Read the first line of input containing number of humans and water length
	sInput, _ = reader.ReadString('\n')
	sInput = strings.TrimRight(sInput, "\n")
	psInput = strings.Split(sInput, " ")
	nHumanNumber, _ = strconv.Atoi(psInput[0])
	nWaterLength, _ = strconv.Atoi(psInput[1])

	// Read the second line of input containing the coming seconds of humans
	sLongInputLine, _ = reader.ReadString('\n')
	sLongInputLine = strings.TrimRight(sLongInputLine, "\n")
	psInput = strings.Split(sLongInputLine, " ")
	for i := 0; i < nHumanNumber; i++ {
		anComingSec[i], _ = strconv.Atoi(psInput[i])
	}

	// Initialize the start time for water coverage
	nStart = anComingSec[0]

	// Main loop to calculate the total water life duration
	for nNextHumanIndex < nHumanNumber {
		nStop = nStart + nWaterLength
		if nNextHumanIndex == nHumanNumber {
			break
		} else {
			for nNextHumanIndex < nHumanNumber && anComingSec[nNextHumanIndex] < nStop {
				if nStop <= anComingSec[nNextHumanIndex] + nWaterLength {
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

	// Output the total water life duration
	fmt.Println(nWaterLife)
}

