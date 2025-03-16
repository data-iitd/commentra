package main

import (
	"fmt"
	"math"
)

func main() {
	// Declare variables for minimum index and minimum difference
	var iMin, min int
	var i, j, k int
	var X, N int

	// Read the values of X and N from user input
	fmt.Scan(&X, &N)

	// If N is 0, print X and exit the program
	if N == 0 {
		fmt.Println(X)
		return
	}

	// Initialize slices to hold positive and negative values
	plus := make([]int, 256)
	minus := make([]int, 256)

	// Fill the plus slice with indices and minus slice with negative indices
	for i := 0; i < 256; i++ {
		plus[i] = i
		minus[i] = -1 * i
	}

	// Read N values and set corresponding indices in the plus slice to 0
	for i = 0; i < N; i++ {
		fmt.Scan(&j)
		plus[j] = 0 // Mark the value as unavailable
	}

	// Initialize minimum index and minimum difference
	iMin = 0
	min = math.MaxInt32

	// Iterate through the plus slice in reverse order to find the closest value to X
	for i = 255; i >= 0; i-- {
		// Skip indices that are marked as unavailable (0) and are greater than 0
		if plus[i] == 0 && i > 0 {
			continue
		}

		// Calculate the difference between X and the current value in the plus slice
		k = X - plus[i]
		if k < 0 {
			k *= -1 // Take the absolute value of the difference
		}

		// Update minimum difference and index if a closer value is found
		if k <= min {
			min = k
			iMin = i // Store the index of the closest value
		}
	}

	// Print the index of the closest value found
	fmt.Println(iMin)
}

// <END-OF-CODE>
