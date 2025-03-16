package main

import (
	"fmt"
)

func solve(N int64, T []int64, M int64, P []int64, X []int64) {
	// Iterate over each modification request
	for i := int64(0); i < M; i++ {
		ans := int64(0) // Initialize the answer for the current modification
		// Calculate the total time considering the current modification
		for j := int64(0); j < N; j++ {
			// If the current index matches the modified position, add the new time value
			if j == P[i]-1 {
				ans += X[i]
			} else {
				// Otherwise, add the original time value
				ans += T[j]
			}
		}
		// Output the result for the current modification
		fmt.Println(ans)
	}
}

func main() {
	var N int64 // Number of original time values
	fmt.Scan(&N) // Read the number of time values
	T := make([]int64, N) // Slice to store the original time values
	for i := int64(0); i < N; i++ {
		fmt.Scan(&T[i]) // Read the original time values into the slice
	}

	var M int64 // Number of modifications
	fmt.Scan(&M) // Read the number of modifications
	P := make([]int64, M) // Slice to store the positions of modifications
	X := make([]int64, M) // Slice to store the new time values for modifications
	for i := int64(0); i < M; i++ {
		fmt.Scan(&P[i], &X[i]) // Read the modification positions and new time values
	}

	// Call the solve function to process the modifications and output results
	solve(N, T, M, P, X)
}

// <END-OF-CODE>
