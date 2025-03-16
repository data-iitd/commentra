package main

import (
	"fmt"
	"math"
)

func main() {
	// Read the number of elements in the slice
	var N int
	fmt.Scan(&N)

	// Initialize a slice of size N with integers
	A := make([]int64, N)
	for i := 0; i < N; i++ { // Iterate through each element in the slice and read its value
		fmt.Scan(&A[i])
	}

	// Initialize the answer variable to 0
	var answer int64 = 0

	// Outer loop iterates through each element in the slice except the last one
	for i := 0; i < N-1; i++ {
		// Inner loop iterates through the remaining elements in the slice starting from the next element
		for j := i + 1; j < N; j++ {
			// Calculate the absolute difference between the current and next elements
			diff := int64(math.Abs(float64(A[i] - A[j])))

			// Update the answer variable with the maximum difference found so far
			if diff > answer {
				answer = diff
			}
		}
	}

	// Print the answer
	fmt.Println(answer)
}

// <END-OF-CODE>
