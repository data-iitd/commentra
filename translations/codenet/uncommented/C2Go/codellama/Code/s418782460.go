
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var nHumanNumber int
	var nWaterLength int
	var nWaterLife int
	var nStart int
	var nStop int
	var nNextHumanIndex int
	var nIndex int
	var i int
	var j int
	var anComingSec [200000]int

	// read line 1
	reader := bufio.NewReader(os.Stdin)
	sInput, _ := reader.ReadString('\n')
	sInput = strings.TrimSuffix(sInput, "\n")
	sInput = strings.TrimSuffix(sInput, "\r")
	sInput = strings.TrimSpace(sInput)
	sInputArray := strings.Split(sInput, " ")
	nHumanNumber, _ = strconv.Atoi(sInputArray[0])
	nWaterLength, _ = strconv.Atoi(sInputArray[1])

	// read line 2
	sLongInputLine, _ := reader.ReadString('\n')
	sLongInputLine = strings.TrimSuffix(sLongInputLine, "\n")
	sLongInputLine = strings.TrimSuffix(sLongInputLine, "\r")
	sLongInputLine = strings.TrimSpace(sLongInputLine)
	sLongInputLineArray := strings.Split(sLongInputLine, " ")
	for i = 0; i < nHumanNumber; i++ {
		anComingSec[i], _ = strconv.Atoi(sLongInputLineArray[i])
	}

	nStart = anComingSec[0]

	for nNextHumanIndex = 0; nNextHumanIndex < nHumanNumber; {
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
	fmt.Println(nWaterLife)
}

