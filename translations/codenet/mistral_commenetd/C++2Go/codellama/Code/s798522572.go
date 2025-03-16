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

	// Allocate memory for a vector B of size N
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

	// Set the first element of vector B with the difference between the second element of array A and the initialized value of m
	B[1] = A[1] - m

	// Iterate through the remaining elements of array A starting from the third one
	for i := 2; i < N; i++ {
		// Update the value of m with the minimum value between it and the current element of array A
		m = int(math.Min(float64(m), float64(A[i])))

		// Set the current element of vector B with the difference between the current element of array A and the updated value of m
		B[i] = A[i] - m
	}

	// Print the output value to the standard output
	fmt.Println(count(B))
}

func count(B []int) int {
	// Initialize variable max with the maximum value among the elements of vector B
	max := B[0]
	for i := 1; i < len(B); i++ {
		if B[i] > max {
			max = B[i]
		}
	}

	// Initialize variable count with 0
	count := 0

	// Iterate through the elements of vector B
	for i := 0; i < len(B); i++ {
		// If the current element of vector B is equal to the initialized value of max, increment the value of count
		if B[i] == max {
			count++
		}
	}

	// Return the value of count
	return count
}

// 