package main

import (
	"fmt"
)

func main() {
	// Initialize the scanner for reading input
	var len int
	fmt.Scan(&len)

	// Allocate memory for the array of integers
	a := make([]int, len)

	// Read each integer from the user input and store it in the array
	for i := 0; i < len; i++ {
		fmt.Scan(&a[i])
	}

	// Initialize variables for left and right indices and a flag
	l := 0
	r := 0
	flag := false

	// Start the loop to search for two non-consecutive numbers
	for i := 0; i < len; i++ {
		// Check if the current number is not in its correct position
		if a[i] != i+1 && !flag {
			// Update the left index
			l = i + 1
			// Set the flag to true to indicate that we have found the first non-consecutive number
			flag = true
			// Continue to the next iteration of the loop
			continue
		}

		// Check if the current number is also not in its correct position and the flag is set
		if a[i] != i+1 && flag {
			// Update the right index
			r = i + 1

			// Check if the difference between the previous number and the current number is greater than 1
			if a[r-1] > a[r-2] {
				// Set the isTrue flag to true if the condition is satisfied
				fmt.Println(l, r)
				return
			}
		}
	}

	// Print the result based on the value of the isTrue flag
	fmt.Println("0 0")
}
