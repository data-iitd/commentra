package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scanln(&n)

	// Initialize slices to store the elements
	h := make([]int, n)
	g := make([]int, n)

	// Read n pairs of integers from the standard input
	for i := 0; i < n; i++ {
		fmt.Scan(&h[i], &g[i])
	}

	// Initialize the result variable to 0
	result := 0

	// Iterate through each element in slice h
	for i := 0; i < n; i++ {
		// Compare each element in slice h with each element in slice g
		for j := 0; j < n; j++ {
			if h[i] == g[j] {
				// If a match is found, increment the result
				result++
			}
		}
	}

	// Print the value of result
	fmt.Println(result)
}

// <END-OF-CODE>
