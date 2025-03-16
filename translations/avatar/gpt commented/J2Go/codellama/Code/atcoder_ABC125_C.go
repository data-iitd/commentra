package main

import (
	"fmt"
	"math"
)

func main() {
	// Create a Scanner object to read input from the console
	sc := new(Scanner)

	// Read the number of elements
	var N int
	fmt.Scan(&N)

	// Initialize the array A with size N
	A := make([]int, N)

	// Read N integers from input and store them in array A
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	// Close the scanner to prevent resource leaks
	sc.Close()

	// Arrays to hold the GCD values from the left and right
	M := make([]int, N) // Not used in the code, can be removed
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
	answer := math.Max(L[N-2], R[1])

	// Iterate through the array to find the maximum GCD excluding the current element
	for i := 1; i < N-1; i++ {
		answer = math.Max(answer, gcd(L[i-1], R[i+1]))
	}

	// Print the final answer
	fmt.Println(answer)
}

// Method to calculate the GCD of two integers using the Euclidean algorithm
func gcd(a, b int) int {
	var tmp int

	// Ensure a is greater than or equal to b
	if b > a {
		tmp = a
		a = b
		b = tmp
	}

	// If b is zero, return a as the GCD
	if b == 0 {
		return a
	}

	// Calculate GCD using the Euclidean algorithm
	var r int
	for r = -1; r != 0; {
		r = a % b
		a = b
		b = r
	}

	// Return the GCD
	return a
}

// 