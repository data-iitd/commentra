
<<<<<<< HEAD

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
=======
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
>>>>>>> 98c87cb78a (data updated)
)

// Define constants for maximum sizes
const (
<<<<<<< HEAD
	MAX_STRING = 30
	MAX_LINE   = 2000000
	MAX_HUMAN  = 200000
)

// Declare global arrays and variables
var sLongInputLine [MAX_LINE + 1]byte
=======
    MAX_STRING = 30
    MAX_LINE   = 2000000
    MAX_HUMAN  = 200000
)

// Declare global arrays and variables
var sLongInputLine [MAX_LINE+1]byte
>>>>>>> 98c87cb78a (data updated)
var anComingSec [MAX_HUMAN]int

func main() {

<<<<<<< HEAD
	// Declare variables for input and processing
	var sInput [MAX_STRING + 1]byte
	var psWord *byte
	var psInput *byte

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
	fmt.Fscan(bufio.NewReader(os.Stdin), &sInput)
	psInput = (*byte)(unsafe.Pointer(C.CString(string(sInput))))
	psWord = C.strtok(psInput, (*C.char)(unsafe.Pointer(C.CString(" "))))
	nHumanNumber, _ = strconv.Atoi(C.GoString(psWord))
	psWord = C.strtok(nil, (*C.char)(unsafe.Pointer(C.CString(" "))))
	nWaterLength, _ = strconv.Atoi(C.GoString(psWord))

	// Read the second line of input which contains the seconds when each human arrives
	fmt.Fscan(bufio.NewReader(os.Stdin), &sLongInputLine)
	psInput = (*byte)(unsafe.Pointer(C.CString(string(sLongInputLine))))
	psWord = C.strtok(psInput, (*C.char)(unsafe.Pointer(C.CString(" "))))
	for i = 0; i < nHumanNumber; i++ {
		anComingSec[i], _ = strconv.Atoi(C.GoString(psWord))
		psWord = C.strtok(nil, (*C.char)(unsafe.Pointer(C.CString(" "))))
	}

	// Initialize the start time to the first human's arrival time
	nStart = anComingSec[0]

	// Process the data to calculate the water life
	for nNextHumanIndex = 0; nNextHumanIndex < nHumanNumber; nNextHumanIndex++ {
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
	fmt.Printf("%d\n", nWaterLife)

=======
    // Declare variables for input and processing
    var sInput [MAX_STRING+1]byte
    var psWord *byte
    var psInput *byte

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
    fmt.Fscan(bufio.NewReader(os.Stdin), &sInput)
    psInput = (*byte)(unsafe.Pointer(C.CString(string(sInput))))
    psWord = C.strtok(psInput, (*C.char)(unsafe.Pointer(C.CString(" "))))
    nHumanNumber, _ = strconv.Atoi(C.GoString(psWord))
    psWord = C.strtok(nil, (*C.char)(unsafe.Pointer(C.CString(" "))))
    nWaterLength, _ = strconv.Atoi(C.GoString(psWord))

    // Read the second line of input which contains the seconds when each human arrives
    fmt.Fscan(bufio.NewReader(os.Stdin), &sLongInputLine)
    psInput = (*byte)(unsafe.Pointer(C.CString(string(sLongInputLine))))
    psWord = C.strtok(psInput, (*C.char)(unsafe.Pointer(C.CString(" "))))
    for i = 0; i < nHumanNumber; i++ {
        anComingSec[i], _ = strconv.Atoi(C.GoString(psWord))
        psWord = C.strtok(nil, (*C.char)(unsafe.Pointer(C.CString(" "))))
    }

    // Initialize the start time to the first human's arrival time
    nStart = anComingSec[0]

    // Process the data to calculate the water life
    for nNextHumanIndex = 0; nNextHumanIndex < nHumanNumber; nNextHumanIndex++ {
        if nNextHumanIndex == nHumanNumber {
            break
        } else {
            nStop = nStart + nWaterLength
            if anComingSec[nNextHumanIndex] < nStop {
                for nNextHumanIndex = nNextHumanIndex; nNextHumanIndex < nHumanNumber && anComingSec[nNextHumanIndex] < nStop; nNextHumanIndex++ {
                    if nStop <= anComingSec[nNextHumanIndex]+nWaterLength {
                        nStop = anComingSec[nNextHumanIndex]+nWaterLength
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

    // Output the result which is the total water life
    fmt.Printf("%d\n", nWaterLife)
>>>>>>> 98c87cb78a (data updated)
}

