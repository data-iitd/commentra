package main

import (
	"fmt"
)

const (
	INF     = int(2e9) // Constant for infinity
	M_PI    = 3.14159265358979323846 // Constant for pi
)

func main() {
	var N int // Variable to store the number of elements in the array

	// Read the number of elements from the standard input
	fmt.Scan(&N)

	// Allocate memory for the array and read its elements
	a := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&a[i])
	}

	// Initialize variables
	idx := 1 // Index for checking the current element in the array
	ans := 0 // Variable to store the answer

	// Process the array
	for i := 0; i < N; i++ {
		// Check if the current element matches the index
		if a[i] == idx {
			// Increment the index
			idx++
		} else {
			// Increment the answer
			ans++
		}
	}

	// Output the result
	if idx == 1 {
		fmt.Println(-1) // Output -1 if all elements are the same
	} else {
		fmt.Println(ans) // Output the answer otherwise
	}
}

// <END-OF-CODE>
