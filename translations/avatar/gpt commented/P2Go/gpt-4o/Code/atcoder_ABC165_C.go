package main

import (
	"fmt"
	"os"
)

func solve(N, M, Q int, a, b, c, d []int) {
	// Initialize the result variable to store the maximum score
	res := 0

	// Recursive function to explore combinations of numbers
	var rec func(A []int)
	rec = func(A []int) {
		// Base case: if the length of A equals N, calculate the score
		if len(A) == N {
			ans := 0
			// Check each query to see if it contributes to the score
			for i := 0; i < Q; i++ {
				if A[b[i]-1]-A[a[i]-1] == c[i] {
					ans += d[i] // Add the score from the query if it matches
				}
			}
			// Update the maximum score found
			if ans > res {
				res = ans
			}
			return
		}

		// Determine the starting point for the next number to be added
		lastMax := 1
		if len(A) > 0 {
			lastMax = A[len(A)-1]
		}

		// Iterate through possible values to add to the combination
		for i := lastMax; i <= M; i++ {
			rec(append(A, i)) // Recursively call with the new number added to A
		}
	}

	// Start the recursive exploration with an empty slice
	rec([]int{})

	// Print the maximum score found
	fmt.Println(res)
}

func main() {
	// Read the values of N, M, and Q from input
	var N, M, Q int
	fmt.Scan(&N, &M, &Q)

	// Initialize slices to hold the query parameters
	a := make([]int, Q)
	b := make([]int, Q)
	c := make([]int, Q)
	d := make([]int, Q)

	// Read the query parameters from input
	for i := 0; i < Q; i++ {
		fmt.Scan(&a[i], &b[i], &c[i], &d[i])
	}

	// Call the solve function with the parsed input
	solve(N, M, Q, a, b, c, d)
}

// <END-OF-CODE>
