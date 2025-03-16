package main

import (
	"fmt"
	"sort"
)

func main() {
	// Declare variables for the number of elements (N) and a threshold (T)
	var N, T int

	// Read the number of elements and the threshold from input
	fmt.Scanf("%d %d\n", &N, &T)

	// Initialize an array A to hold the input values
	A := make([]int, N)

	// Read N integers into the array A
	for i := 0; i < N; i++ {
		fmt.Scanf("%d\n", &A[i])
	}

	// Initialize m with the first element of A
	m := A[0]

	// Calculate the first element of B based on the first element of A and update m
	B := make([]int, N)
	B[1] = A[1] - m
	m = min(m, A[1])

	// Loop through the remaining elements of A to fill B and update m
	for i := 2; i < N; i++ {
		// Fill B[i] with the difference between A[i] and the minimum value found so far (m)
		B[i] = A[i] - m

		// Update m to be the minimum of the current m and A[i]
		m = min(m, A[i])
	}

	// Count and output the number of times the maximum element in B appears
	fmt.Println(count(B, max(B)))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a []int) int {
	m := a[0]
	for _, v := range a {
		if v > m {
			m = v
		}
	}
	return m
}

func count(a []int, m int) int {
	c := 0
	for _, v := range a {
		if v == m {
			c++
		}
	}
	return c
}

