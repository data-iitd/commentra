package main

import (
	"fmt"
)

func main() {
	var N, K int64 // Declare variables for number of elements and steps
	A := make([]int64, 200100) // Slice to store the input values
	B := make([]int64, 200100) // Slice to track the first visit time to each position
	for i := range B {
		B[i] = -1 // Initialize to -1 to indicate unvisited positions
	}
	now := int64(1) // Current position, starting at 1
	var cnt int64 = 0 // Counter for the number of steps taken

	// Read the number of elements (N) and the number of steps (K)
	fmt.Scan(&N, &K)

	// Read the elements into slice A
	for i := int64(1); i <= N; i++ {
		fmt.Scan(&A[i]) // Store input values in A, starting from index 1
	}

	// Mark the starting position as visited at step 0
	B[1] = 0 // Starting point is visited at step 0

	var j int64
	// Traverse the positions based on the values in A
	for j = 1; j <= K; j++ {
		now = A[now] // Move to the next position based on the current position

		// Check if the current position has been visited before
		if B[now] == -1 {
			B[now] = j // Mark the position with the current step count
		} else {
			// If the position has been visited, calculate the cycle length
			cnt = j // Store the current step count
			break // Exit the loop as we found a cycle
		}
	}

	// If we did not reach the maximum steps K
	if j < K {
		var tmp int64
		// Calculate how many additional steps to take within the cycle
		tmp = (K - B[now]) % (cnt - B[now])

		// Move to the final position after the calculated additional steps
		for k := int64(0); k < tmp; k++ {
			now = A[now] // Continue moving to the next position
		}
	}

	// Output the final position after all movements
	fmt.Println(now)
}

// <END-OF-CODE>
