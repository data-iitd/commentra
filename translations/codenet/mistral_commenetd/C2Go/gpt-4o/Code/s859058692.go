package main

import (
	"fmt"
)

func main() {
	var sum int64 = 0 // Initialize sum to 0
	var m, n, min, max int // Declare variables

	// Read the number of integers to be input from the user
	fmt.Scan(&n)

	// Initialize min and max with the first input
	fmt.Scan(&m)
	sum += int64(m)
	min, max = m, m // Set both min and max to the first input

	// Iterate through the remaining integers
	for i := 1; i < n; i++ {
		fmt.Scan(&m) // Read an integer input and assign it to m
		sum += int64(m) // Add the current integer input to the sum

		// Update min and max values if the current input is smaller or larger
		if m < min {
			min = m // Set min to the current input if it's smaller
		}
		if m > max {
			max = m // Set max to the current input if it's larger
		}
	}

	// Print the minimum value, maximum value, and sum of the input integers
	fmt.Printf("%d %d %d\n", min, max, sum)
}

// <END-OF-CODE>
