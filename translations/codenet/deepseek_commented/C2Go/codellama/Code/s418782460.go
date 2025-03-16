
package main

import (
	"bufio"
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
	NEW_LINE    = "\n"
	BLANK_SPACE = " "
)

// Declare global arrays and variables
var (
	sLongInputLine string
	anComingSec    []int
)

func main() {

	// Declare variables for input and processing
	var (
		sInput       string
		psWord       string
		psInput      string
		nHumanNumber int
		nNextHumanIndex int
		nWaterLength int
		nWaterLife   int
		nStart       int
		nStop        int
		nIndex       int
		i            int
		j            int
	)

	// Read the first line of input which contains the number of humans and the water length
	reader := bufio.NewReader(os.Stdin)
	sInput, _ = reader.ReadString('\n')
	sInput = strings.TrimSuffix(sInput, NEW_LINE)
	psInput = strings.Split(sInput, BLANK_SPACE)[0]
	nHumanNumber, _ = strconv.Atoi(psInput)
	psInput = strings.Split(sInput, BLANK_SPACE)[1]
	nWaterLength, _ = strconv.Atoi(psInput)

	// Read the second line of input which contains the seconds when each human arrives
	sLongInputLine, _ = reader.ReadString('\n')
	sLongInputLine = strings.TrimSuffix(sLongInputLine, NEW_LINE)
	psInput = strings.Split(sLongInputLine, BLANK_SPACE)
	anComingSec = make([]int, nHumanNumber)
	for i = 0; i < nHumanNumber; i++ {
		anComingSec[i], _ = strconv.Atoi(psInput[i])
	}

	// Initialize the start time to the first human's arrival time
	nStart = anComingSec[0]

	// Process the data to calculate the water life
	for nNextHumanIndex = 0; nNextHumanIndex < nHumanNumber; nNextHumanIndex++ {
		if nNextHumanIndex == nHumanNumber-1 {
			break
		} else {
			nStop = nStart + nWaterLength
			if anComingSec[nNextHumanIndex] < nStop {
				for nNextHumanIndex < nHumanNumber && anComingSec[nNextHumanIndex] < nStop; nNextHumanIndex++ {
					if nStop <= anComingSec[nNextHumanIndex]+nWaterLength {
						nStop = anComingSec[nNextHumanIndex] + nWaterLength
					}
				}
				if nNextHumanIndex == nHumanNumber-1 {
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

