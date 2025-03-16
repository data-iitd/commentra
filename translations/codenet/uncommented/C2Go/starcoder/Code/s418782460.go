
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {

	var sLongInputLine string
	var sInput string
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

	// read line 1
	fmt.Scanf("%s", &sInput)
	psInput = strings.Split(sInput, " ")
	nHumanNumber, _ = strconv.Atoi(psInput[0])
	nWaterLength, _ = strconv.Atoi(psInput[1])

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	sLongInputLine = scanner.Text()
	if strings.Contains(sLongInputLine, "\n") {
		sLongInputLine = sLongInputLine[:len(sLongInputLine)-1]
	}
	psInput = strings.Split(sLongInputLine, " ")

	for i = 0; i < nHumanNumber; i++ {
		anComingSec[i], _ = strconv.Atoi(psInput[i])
	}

	nStart = anComingSec[0]

	for nNextHumanIndex = 0; nNextHumanIndex < nHumanNumber; nNextHumanIndex++ {
		if nNextHumanIndex == nHumanNumber {
			break
		} else {
			nStop = nStart + nWaterLength
			if anComingSec[nNextHumanIndex] < nStop {
				for nNextHumanIndex < nHumanNumber && anComingSec[nNextHumanIndex] < nStop {
					if nStop <= anComingSec[nNextHumanIndex]+nWaterLength {
						nStop = anComingSec[nNextHumanIndex]+nWaterLength
						nNextHumanIndex++
					}
				}
				if nNextHumanIndex == nHumanNumber {
					nWaterLife = nWaterLife + (nStop-nStart)
					break
				}
			}
			nWaterLife = nWaterLife + (nStop-nStart)
			nStart = nStop
			if nStart < anComingSec[nNextHumanIndex] {
				nStart = anComingSec[nNextHumanIndex]
			}
		}
	}
	fmt.Printf("%d\n", nWaterLife)

}

