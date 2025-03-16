
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read an integer input which represents the number of elements
	reader := bufio.NewReader(os.Stdin)
	nTemp, err := reader.ReadString('\n')
	checkError(err)
	n, err := strconv.ParseInt(strings.TrimSpace(nTemp), 10, 64)
	checkError(err)

	// Read a line of input, split it by spaces, and convert it to a list of integers
	aTemp, err := reader.ReadString('\n')
	checkError(err)
	aTemp = strings.TrimSpace(aTemp)
	a := strings.Split(aTemp, " ")
	aValues := make([]int64, len(a))
	for i, aTemp := range a {
		aValue, err := strconv.ParseInt(aTemp, 10, 64)
		checkError(err)
		aValues[i] = aValue
	}

	// Initialize the current level and counters
	currentLevel := int64(0)
	counter := int64(0)
	counterTurns := int64(-1) // Start with -1 to account for the first turn increment

	// Loop until all elements have been processed
	for counter < n {
		counterTurns++ // Increment the turn counter

		// Iterate through the list to find elements that can be processed
		for i := int64(0); i < n; i++ {
			// Check if the current element is not marked (-1) and is less than or equal to the current counter
			if aValues[i]!= -1 && aValues[i] <= counter {
				counter++ // Increment the counter as we can process this element
				aValues[i] = -1 // Mark the element as processed by setting it to -1
			}
		}

		// Reverse the list to prepare for the next round of processing
		for i, aValue := range aValues {
			aValues[i] = aValues[n-1-i]
		}
	}

	// Print the total number of turns taken to process all elements
	fmt.Println(counterTurns)
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

