package main

import (
	"fmt"
)

func main() {
	// Read the number of test cases
	var n int
	fmt.Scan(&n)

	// Read the array of integers
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Initialize variables
	currentLevel := 0
	counter := 0
	counterTurns := -1

	// Main loop
	for counter < len(a) {
		// Increment turns counter
		counterTurns++

		// Iterate through the array
		for i := 0; i < len(a); i++ {
			// If current index is valid and its value is less than or equal to current level
			if a[i] != -1 && a[i] <= counter {
				// Increment counter and mark the index as visited
				counter++
				a[i] = -1
			}
		}

		// Reverse the array
		for left, right := 0, len(a)-1; left < right; left, right = left+1, right-1 {
			a[left], a[right] = a[right], a[left]
		}
	}

	// Print the result
	fmt.Println(counterTurns)
}

// <END-OF-CODE>
