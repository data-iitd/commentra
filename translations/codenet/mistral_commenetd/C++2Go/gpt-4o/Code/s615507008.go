package main

import (
	"fmt"
)

func solve(N int64, T []int64, M int64, P []int64, X []int64) {
	// Iterate through each query
	for i := int64(0); i < M; i++ {
		// Initialize the answer variable to zero
		ans := int64(0)

		// Iterate through each element in T up to the position of the current query
		for j := int64(0); j < N; j++ {
			// If the current index j is equal to the position of the current query - 1
			if j == P[i]-1 {
				// Add the value of X[i] to the answer variable
				ans += X[i]
			} else {
				// Otherwise, add the value of the current element in T to the answer variable
				ans += T[j]
			}
		}

		// Print the answer for the current query
		fmt.Println(ans)
	}
}

func main() {
	// Read the number of elements in T from the standard input
	var N int64
	fmt.Scan(&N)

	// Initialize a slice T of size N
	T := make([]int64, N)

	// Read the elements of T from the standard input
	for i := int64(0); i < N; i++ {
		fmt.Scan(&T[i])
	}

	// Read the number of queries from the standard input
	var M int64
	fmt.Scan(&M)

	// Initialize slices P and X of size M
	P := make([]int64, M)
	X := make([]int64, M)

	// Read the positions and values of the queries from the standard input
	for i := int64(0); i < M; i++ {
		fmt.Scan(&P[i], &X[i])
	}

	// Call the solve function with the given arguments
	solve(N, T, M, P, X)
}

// <END-OF-CODE>
