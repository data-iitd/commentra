package main

import (
	"fmt"
)

func main() {
	// Read the number of elements
	var n int
	fmt.Scan(&n)

	// Initialize a slice to store the input elements
	a := make([]int, n)

	// Read n integers into the slice
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Initialize a counter for the current expected number
	curr := 0

	// Iterate through the slice to find the longest prefix of consecutive integers starting from 1
	for i := 0; i < n; i++ {
		if a[i] == curr+1 {
			curr++ // Increment curr if the current element matches the expected value
		}
	}

	// Check if any consecutive integers were found
	if curr > 0 {
		// Print the number of elements not in the consecutive sequence
		fmt.Println(n - curr)
	} else {
		// If no consecutive integers were found, print -1
		fmt.Println(-1)
	}
}

// <END-OF-CODE>
