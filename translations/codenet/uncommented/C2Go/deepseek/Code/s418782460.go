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

	sInput, _ := reader.ReadString('\n')
	sInput = strings.TrimRight(sInput, "\n")
	parts := strings.Split(sInput, " ")
	nHumanNumber, _ := strconv.Atoi(parts[0])
	nWaterLength, _ := strconv.Atoi(parts[1])

	sLongInputLine, _ = reader.ReadString('\n')
	sLongInputLine = strings.TrimRight(sLongInputLine, "\n")
	parts = strings.Split(sLongInputLine, " ")
	for i := 0; i < nHumanNumber; i++ {
		anComingSec[i], _ = strconv.Atoi(parts[i])
	}

	nStart := anComingSec[0]
	nNextHumanIndex := 0
	nWaterLife := 0
	nStop := 0

	for nNextHumanIndex < nHumanNumber {
		nStop = nStart + nWaterLength
		if nNextHumanIndex < nHumanNumber && anComingSec[nNextHumanIndex] < nStop {
			for nNextHumanIndex < nHumanNumber && anComingSec[nNextHumanIndex] < nStop {
				if nStop <= anComingSec[nNextHumanIndex]+nWaterLength {
					nStop = anComingSec[nNextHumanIndex] + nWaterLength
				}
				nNextHumanIndex++
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
	fmt.Println(nWaterLife)
}

