package main

import (
	"fmt"
	"math"
)

// Initialize the array A and read its elements from the standard input
func main() {
	var N int
	fmt.Scan(&N) // Read the number of elements in the array A

	// Create a slice A to store the elements of the array A
	A := make([]int, N)

	// Read the elements of the array A from the standard input
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	// Initialize slices M, L, and R
	M := make([]int, N)
	L := make([]int, N)
	R := make([]int, N)

	// Initialize the first elements of L and R slices
	L[0] = A[0]
	R[N-1] = A[N-1]

	// Calculate the gcd of consecutive pairs of elements in the array A,
	// starting from the second element, and store the results in the L slice
	for i := 1; i < N; i++ {
		L[i] = gcd(L[i-1], A[i])
	}

	// Calculate the gcd of consecutive pairs of elements in the array A,
	// starting from the last element, and store the results in the R slice
	for i := N - 2; i >= 0; i-- {
		R[i] = gcd(R[i+1], A[i])
	}

	// Find the maximum value among the gcd of consecutive pairs of elements
	// in the subarrays [0, i] and [i+1, N-1] for all i from 0 to N-2
	answer := int(math.Max(float64(L[N-2]), float64(R[1])))
	for i := 1; i < N-1; i++ {
		answer = int(math.Max(float64(answer), float64(gcd(L[i-1], R[i+1]))))
	}

	// Print the result
	fmt.Println(answer)
}

// Calculate the greatest common divisor of two integers using Euclid's algorithm
func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

