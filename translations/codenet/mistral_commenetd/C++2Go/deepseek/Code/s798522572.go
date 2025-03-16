package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Initialize variables
	var N, T int

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
		if A[i] < m {
			m = A[i]
		}

		// Set the current element of slice B with the difference between the current element of array A and the updated value of m
		B[i] = A[i] - m
	}

	// Find the maximum value in slice B
	maxB := B[0]
	for i := 1; i < N; i++ {
		if B[i] > maxB {
			maxB = B[i]
		}
	}

	// Count the number of times the maximum value appears in slice B
	count := 0
	for i := 0; i < N; i++ {
		if B[i] == maxB {
			count++
		}
	}

	// Print the output value to the standard output
	fmt.Println(count)

	// End of main function
