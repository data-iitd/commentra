package main

import (
	"fmt"
)

// Function to solve the problem
func solve(N int, // Number of elements in T
	T []int, // Input vector T
	M int, // Number of queries
	P []int, // Position of each query
	X []int // Value of each query
) {
	// Initialize a variable to store the answer for each query
	var ans int

	// Iterate through each query
	for i := 0; i < M; i++ {
		// Initialize the answer variable to zero
		ans = 0

		// Iterate through each element in T up to the position of the current query
		for j := 0; j < N; j++ {
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

// Main function
func main() {
	// Initialize iostream objects
	// cin.tie(0);
	// ios::sync_with_stdio(false);

	// Read the number of elements in T from the standard input
	var N int
	fmt.Scan(&N)

	// Initialize a vector T of size N
	T := make([]int, N)

	// Read the elements of T from the standard input
	for i := 0; i < N; i++ {
		fmt.Scan(&T[i])
	}

	// Read the number of queries from the standard input
	var M int
	fmt.Scan(&M)

	// Initialize vectors P and X of size M
	P := make([]int, M)
	X := make([]int, M)

	// Read the positions and values of the queries from the standard input
	for i := 0; i < M; i++ {
		fmt.Scan(&P[i], &X[i])
	}

	// Call the solve function with the given arguments
	solve(N, T, M, P, X)

	// Return 0 to indicate successful execution
	// return 0
}

