package main

import (
	"fmt"
)

func main() {
	// Create a variable to read input from the console
	var len int
	// Read the length of the array
	fmt.Scan(&len)

	// Initialize a slice of the specified length
	a := make([]int, len)

	// Populate the slice with user input
	for i := 0; i < len; i++ {
		fmt.Scan(&a[i])
	}

	// Initialize variables to track the left and right indices of the mismatch
	l, r := 0, 0

	// Flags to indicate the state of the search for mismatches
	flag := false
	isTrue := false

	// Loop through the slice to find the first and second mismatches
	for i := 0; i < len; i++ {
		// Check if the current element does not match its expected value
		if a[i] != i+1 && !flag {
			// Set the left index to the current position (1-based index)
			l = i + 1
			// Set the flag to indicate the first mismatch has been found
			flag = true
			continue
		}
		// Check for the second mismatch
		if a[i] != i+1 && flag {
			// Set the right index to the current position (1-based index)
			r = i + 1
			// Check if the previous element is less than the current element
			if a[r-1]-a[r-2] > 0 {
				// Set the isTrue flag to indicate a valid mismatch has been found
				isTrue = true
				break
			}
		}
	}

	// Output the result based on whether a valid mismatch was found
	if !isTrue {
		fmt.Printf("%d %d\n", l, r)
	} else {
		fmt.Println("0 0")
	}
}

// <END-OF-CODE>
