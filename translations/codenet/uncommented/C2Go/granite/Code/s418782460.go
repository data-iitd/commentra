
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var (
		sInput         string
		psWord          string
		psInput         string
		nHumanNumber    int
		nNextHumanIndex int
		nWaterLength    int
		nWaterLife      int
		nStart           int
		nStop            int
		nIndex           int
		i                int
		j                int
	)

	// read line 1
	reader := bufio.NewReader(os.Stdin)
	sInput, _ = reader.ReadString('\n')
	sInput = strings.Replace(sInput, "\n", "", -1)
	psInput = strings.Split(sInput, " ")[0]
	nHumanNumber, _ = strconv.Atoi(psInput)
	psInput = strings.Split(sInput, " ")[1]
	nWaterLength, _ = strconv.Atoi(psInput)

	sInput, _ = reader.ReadString('\n')
	sInput = strings.Replace(sInput, "\n", "", -1)
	psInput = strings.Split(sInput, " ")
	for i = 0; i < nHumanNumber; i++ {
		anComingSec[i], _ = strconv.Atoi(psInput[i])
	}

	nStart = anComingSec[0]

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
	fmt.Println(nWaterLife)
}

