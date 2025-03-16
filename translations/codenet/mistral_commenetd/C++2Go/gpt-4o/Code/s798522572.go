package main

import (
	"fmt"
	"math"
)

func main() {
	// Initialize variables
	var N, T int // N is the number of elements in the array A, T is an input value

	// Read input values from the standard input
	fmt.Scan(&N, &T)

	// Allocate memory for an integer array A of size N
	A := make([]int, N)

	// Allocate memory for a slice B of size N
	B := make([]int, N)

	// Read integer values from the standard input and store them in array A
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	// Initialize variable m with the minimum value among the first two elements of array A
	m := A[0]
	if A[1] < m {
		m = A[1]
	}

	// Set the first element of slice B with the difference between the second element of array A and the initialized value of m
	B[1] = A[1] - m

	// Iterate through the remaining elements of array A starting from the third one
	for i := 2; i < N; i++ {
		// Update the value of m with the minimum value between it and the current element of array A
		m = int(math.Min(float64(m), float64(A[i])))

		// Set the current element of slice B with the difference between the current element of array A and the updated value of m
		B[i] = A[i] - m
	}

	// Find the maximum element in slice B
	maxB := B[0]
	for _, value := range B {
		if value > maxB {
			maxB = value
		}
	}

	// Count occurrences of maxB in slice B
	count := 0
	for _, value := range B {
		if value == maxB {
			count++
		}
	}

	// Print the output value to the standard output
	fmt.Println(count)
}

// <END-OF-CODE>
