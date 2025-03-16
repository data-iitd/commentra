
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
var anComingSec []int = make([]int, MAX_HUMAN) // Array to store the coming seconds of humans

func main() {
    // Local variables
    var sInput string = "" // Buffer for the first line of input
    var psWord *string = nil // Pointer for tokenizing words
    var psInput *string = nil // Pointer for tokenizing input

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
    fmt.Fscan(os.Stdin, &sInput)
    psInput = strings.Split(sInput, " ")
    nHumanNumber, _ = strconv.Atoi(psInput[0])
    nWaterLength, _ = strconv.Atoi(psInput[1])

    // Read the second line of input containing the coming seconds of humans
    fmt.Fscan(os.Stdin, &sLongInputLine)
    psInput = strings.Split(sLongInputLine, " ")
    for i = 0; i < nHumanNumber; i++ {
        anComingSec[i], _ = strconv.Atoi(psInput[i])
    }

    // Initialize the start time for water coverage
    nStart = anComingSec[0]

    // Main loop to calculate the total water life duration
    for nNextHumanIndex = 0; nNextHumanIndex < nHumanNumber; nNextHumanIndex++ {
        if nNextHumanIndex == nHumanNumber {
            break // Exit if all humans have been processed
        } else {
            nStop = nStart + nWaterLength // Calculate stop time based on water length
            if anComingSec[nNextHumanIndex] < nStop {
                // Process humans that arrive before the current stop time
                for nNextHumanIndex = nNextHumanIndex; nNextHumanIndex < nHumanNumber && anComingSec[nNextHumanIndex] < nStop; nNextHumanIndex++ {
                    if nStop <= anComingSec[nNextHumanIndex] + nWaterLength {
                        nStop = anComingSec[nNextHumanIndex] + nWaterLength // Extend stop time if necessary
                    }
                }
                if nNextHumanIndex == nHumanNumber {
                    nWaterLife = nWaterLife + (nStop - nStart) // Add to water life if all humans are processed
                    break
                }
            }
            nWaterLife = nWaterLife + (nStop - nStart) // Add the duration of water coverage
            nStart = nStop // Update start time for the next iteration
            if nStart < anComingSec[nNextHumanIndex] {
                nStart = anComingSec[nNextHumanIndex] // Adjust start time if necessary
            }
        }
    }

    // Output the total water life duration
    fmt.Println(nWaterLife)
}

