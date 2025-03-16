package main

import (
	"fmt"
)

// Function to calculate the GCD of two integers using the Euclidean algorithm
func gcd(a, b int) int {
	if b > a {
		a, b = b, a
	}
	if b == 0 {
		return a
	}
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func main() {
	// Read the number of elements
	var N int
	fmt.Scan(&N)

	// Initialize the array A with size N
	A := make([]int, N)

	// Read N integers from input and store them in array A
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	// Arrays to hold the GCD values from the left and right
	L := make([]int, N) // GCD values from the left
	R := make([]int, N) // GCD values from the right

	// Initialize the first element of L with the first element of A
	L[0] = A[0]

	// Calculate GCD from the left side
	for i := 1; i < N; i++ {
		L[i] = gcd(L[i-1], A[i])
	}

	// Initialize the last element of R with the last element of A
	R[N-1] = A[N-1]

	// Calculate GCD from the right side
	for i := N - 2; i >= 0; i-- {
		R[i] = gcd(R[i+1], A[i])
	}

	// Calculate the maximum GCD excluding the last element
	answer := max(L[N-2], R[1])

	// Iterate through the array to find the maximum GCD excluding the current element
	for i := 1; i < N-1; i++ {
		answer = max(answer, gcd(L[i-1], R[i+1]))
	}

	// Print the final answer
	fmt.Println(answer)
}

// Helper function to return the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>
