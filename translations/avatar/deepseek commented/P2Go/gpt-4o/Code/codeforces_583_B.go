package main

import (
	"fmt"
)

func main() {
	// Read the number of elements from the user
	var n int
	fmt.Scan(&n)

	// Read the list of integers from the user input
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Initialize variables to track the current level and the number of turns
	currentLevel := 0
	counter := 0
	counterTurns := -1

	// Start a loop that continues until all elements are processed
	for counter < len(a) {
		// Increment the turn counter
		counterTurns++
		// Iterate over the list 'a' to process each element
		for i := 0; i < len(a); i++ {
			// Check if the element is not -1 and is less than or equal to the current level
			if a[i] != -1 && a[i] <= counter {
				// Increment the counter and mark the element as processed
				counter++
				a[i] = -1
			}
		}
		// Reverse the list 'a' to process elements in a different order in the next iteration
		reverse(a)
	}

	// Print the number of turns taken to process all elements
	fmt.Println(counterTurns)
}

// Function to reverse a slice of integers
func reverse(s []int) {
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
}

// <END-OF-CODE>
