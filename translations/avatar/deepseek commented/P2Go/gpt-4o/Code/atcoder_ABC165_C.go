package main

import (
	"fmt"
	"os"
)

func solve(N, M, Q int, a, b, c, d []int) {
	res := 0 // Initialize the result variable to store the maximum score

	// Define the recursive function to generate sequences
	var rec func(A []int)
	rec = func(A []int) {
		if len(A) == N { // If the sequence length is equal to N
			ans := 0 // Initialize the answer for this sequence
			for i := 0; i < Q; i++ { // Iterate over all constraints
				if A[b[i]-1]-A[a[i]-1] == c[i] { // Check if the constraint is satisfied
					ans += d[i] // Add the value of the constraint to the answer
				}
			}
			if ans > res { // Update the result with the maximum score
				res = ans
			}
			return
		}
		lastMax := 1
		if len(A) > 0 {
			lastMax = A[len(A)-1] // Determine the starting point for the next number
		}
		for i := lastMax; i <= M; i++ { // Generate the next number in the sequence
			rec(append(A, i))
		}
	}

	rec([]int{}) // Start the recursive function with an empty slice
	fmt.Println(res) // Print the result
}

func main() {
	var N, M, Q int
	fmt.Scan(&N, &M, &Q) // Read the values of N, M, Q

	a := make([]int, Q)
	b := make([]int, Q)
	c := make([]int, Q)
	d := make([]int, Q)

	for i := 0; i < Q; i++ {
		fmt.Scan(&a[i]) // Read the list a
	}
	for i := 0; i < Q; i++ {
		fmt.Scan(&b[i]) // Read the list b
	}
	for i := 0; i < Q; i++ {
		fmt.Scan(&c[i]) // Read the list c
	}
	for i := 0; i < Q; i++ {
		fmt.Scan(&d[i]) // Read the list d
	}

	solve(N, M, Q, a, b, c, d) // Call the solve function with the input values
}

// <END-OF-CODE>
