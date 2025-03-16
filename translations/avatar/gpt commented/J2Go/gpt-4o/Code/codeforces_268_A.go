package main

import (
	"fmt"
)

func main() {
	// Reading the number of elements (n) from the user
	var n int
	fmt.Scanln(&n)

	// Initializing a variable to store the result of matching elements
	result := 0

	// Creating two slices to hold the input values
	h := make([]int, n) // Slice to store the first set of integers
	g := make([]int, n) // Slice to store the second set of integers

	// Reading n integers into the first slice (h)
	for i := 0; i < n; i++ {
		fmt.Scan(&h[i]) // Storing input in slice h
	}

	// Reading n integers into the second slice (g)
	for i := 0; i < n; i++ {
		fmt.Scan(&g[i]) // Storing input in slice g
	}

	// Comparing each element of slice h with each element of slice g
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			// If a match is found, increment the result counter
			if h[i] == g[j] {
				result++ // Incrementing the count of matches
			}
		}
	}

	// Outputting the total number of matches found
	fmt.Println(result)
}

// <END-OF-CODE>
