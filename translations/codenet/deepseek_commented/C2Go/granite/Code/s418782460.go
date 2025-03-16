
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare variables for input and processing
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

    // Read the first line of input which contains the number of humans and the water length
    reader := bufio.NewReader(os.Stdin)
    sInput, _ = reader.ReadString('\n')
    psInput = strings.Split(sInput, " ")
    nHumanNumber, _ = strconv.Atoi(psInput[0])
    nWaterLength, _ = strconv.Atoi(psInput[1])

    // Read the second line of input which contains the seconds when each human arrives
    sInput, _ = reader.ReadString('\n')
    psInput = strings.Split(sInput, " ")
    for i = 0; i < nHumanNumber; i++ {
        anComingSec[i], _ = strconv.Atoi(psInput[i])
    }

    // Initialize the start time to the first human's arrival time
    nStart = anComingSec[0]

    // Process the data to calculate the water life
    for {
        if nNextHumanIndex == nHumanNumber {
            break
        } else {
            nStop = nStart + nWaterLength
            if anComingSec[nNextHumanIndex] < nStop {
                for {
                    if nNextHumanIndex == nHumanNumber {
                        break
                    } else {
                        if nStop <= anComingSec[nNextHumanIndex]+nWaterLength {
                            nStop = anComingSec[nNextHumanIndex] + nWaterLength
                            nNextHumanIndex++
                        } else {
                            break
                        }
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

