package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read an integer input which represents the number of elements
	var n int
	fmt.Scan(&n)

	// Read a line of input, split it by spaces, and convert it to a slice of integers
	var a []int
	var input string
	fmt.Scan(&input)
	for _, s := range strings.Split(input, " ") {
		num, _ := strconv.Atoi(s)
		a = append(a, num)
	}

	// Initialize the current level and counters
	currentLevel := 0
	counter := 0
	counterTurns := -1 // Start with -1 to account for the first turn increment

	// Loop until all elements have been processed
	for counter < len(a) {
		counterTurns++ // Increment the turn counter

		// Iterate through the slice to find elements that can be processed
		for i := 0; i < len(a); i++ {
			// Check if the current element is not marked (-1) and is less than or equal to the current counter
			if a[i] != -1 && a[i] <= counter {
				counter++ // Increment the counter as we can process this element
				a[i] = -1 // Mark the element as processed by setting it to -1
			}
		}

		// Reverse the slice to prepare for the next round of processing
		for i, j := 0, len(a)-1; i < j; i, j = i+1, j-1 {
			a[i], a[j] = a[j], a[i]
		}
	}

	// Print the total number of turns taken to process all elements
	fmt.Println(counterTurns)
}

// <END-OF-CODE>
