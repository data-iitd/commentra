package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read an integer input which represents the number of elements
	n, _ := strconv.Atoi(readLine(0))

	// Read a line of input, split it by spaces, and convert it to a list of integers
	a := strings.Split(readLine(1), " ")
	for i := 0; i < len(a); i++ {
		a[i], _ = strconv.Atoi(a[i])
	}

	// Initialize the current level and counters
	currentLevel := 0
	counter := 0
	counterTurns := -1 // Start with -1 to account for the first turn increment

	// Loop until all elements have been processed
	for counter < len(a) {
		counterTurns++ // Increment the turn counter

		// Iterate through the list to find elements that can be processed
		for i := 0; i < len(a); i++ {
			// Check if the current element is not marked (-1) and is less than or equal to the current counter
			if a[i] != -1 && a[i] <= counter {
				counter++ // Increment the counter as we can process this element
				a[i] = -1 // Mark the element as processed by setting it to -1
			}
		}

		// Reverse the list to prepare for the next round of processing
		for i := 0; i < len(a)/2; i++ {
			a[i], a[len(a)-1-i] = a[len(a)-1-i], a[i]
		}
	}

	// Print the total number of turns taken to process all elements
	fmt.Println(counterTurns)
}

// readLine reads a line of input from stdin and returns it as a string
func readLine(n int) string {
	var str string
	if n == 0 {
		fmt.Scan(&str)
	} else {
		str = readLine(n - 1)
	}
	return str
}

// 