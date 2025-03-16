package main

import (
	"fmt"
	"math"
)

func main() {
	var N, K int
	fmt.Scan(&N, &K) // Read the number of elements in the array and the size of the sliding window

	// Allocate a slice of integers to store the input elements
	S := make([]int, N)

	// Read the remaining elements of the array from the standard input
	for i := 0; i < N; i++ {
		fmt.Scan(&S[i]) // Read the next integer and store it in the slice
	}

	// Initialize variables for calculating the answer
	temp := 0
	ans := math.MaxInt32 // Use the maximum integer value as initial answer

	// Check the special case when the size of the sliding window is 1
	if K == 1 {
		// Iterate through the array to find the minimum absolute value
		for i := 0; i < N; i++ {
			temp = S[i] // Read the current element
			ans = min(abs(temp), ans) // Update the answer if necessary
		}

		// Print the answer
		fmt.Println(ans)
	} else if N-K != 0 { // Check the case when the size of the sliding window is not equal to the size of the array
		// Initialize variables for calculating the minimum and maximum elements in the sliding window
		var min, max int

		// Iterate through all possible positions of the sliding window
		for i := 0; i <= N-K; i++ {
			// Find the minimum and maximum elements in the current sliding window
			min = S[i]
			max = S[i+K-1]

			// Calculate the sum of the absolute values of the minimum and maximum elements
			// and update the answer if necessary
			if min < 0 && max > 0 {
				temp = 2*abs(min) + max
			} else {
				temp = max(abs(min), abs(max))
			}
			ans = min(ans, temp)
		}

		// Print the answer
		fmt.Println(ans)
	} else { // Check the case when the size of the sliding window is equal to the size of the array
		min = S[0]
		max = S[N-1]

		// Calculate the sum of the absolute values of the minimum and maximum elements
		// and print the answer directly
		if min < 0 && max > 0 {
			fmt.Println(min(2*abs(min)+max, abs(min)+2*max))
		} else {
			fmt.Println(max(abs(min), abs(max)))
		}
	}
}

// Helper function to calculate the absolute value
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Helper function to find the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>
