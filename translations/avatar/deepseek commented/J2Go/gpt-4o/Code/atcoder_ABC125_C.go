package main

import (
	"fmt"
)

func gcd(a, b int) int {
	if b > a {
		a, b = b, a
	}
	if b == 0 {
		return a
	}
	for r := -1; r != 0; {
		r = a % b
		a, b = b, r
	}
	return a
}

func main() {
	var N int
	fmt.Scan(&N) // Read the number of elements
	A := make([]int, N) // Initialize the array A with size N

	// Read the elements of A from the input
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	// Arrays to store the prefix and suffix GCDs
	L := make([]int, N)
	R := make([]int, N)

	// Calculate the prefix GCD array L
	L[0] = A[0]
	for i := 1; i < N; i++ {
		L[i] = gcd(L[i-1], A[i])
	}

	// Calculate the suffix GCD array R
	R[N-1] = A[N-1]
	for i := N - 2; i >= 0; i-- {
		R[i] = gcd(R[i+1], A[i])
	}

	// Initialize the answer with the maximum of the GCD of the first and last elements of L and R
	answer := max(L[N-2], R[1])

	// Iterate through the array to find the maximum GCD
	for i := 1; i < N-1; i++ {
		answer = max(answer, gcd(L[i-1], R[i+1]))
	}

	// Print the final answer
	fmt.Println(answer)
}

// Helper function to find the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
