package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	// Read the number of elements
	var N int
	fmt.Scan(&N)

	// Initialize a slice to store the elements
	A := make([]int64, N)

	// Input the elements into the slice
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	// Sort the slice in descending order
	sort.Slice(A, func(i, j int) bool {
		return A[i] > A[j]
	})

	// Initialize variables to track the minimum difference and the corresponding index
	var index int
	minDiff := int64(math.MaxInt64)

	// Find the element in the slice that minimizes the difference with twice the second largest element
	for i := 1; i < N; i++ {
		// Calculate the absolute difference and update if it's smaller than the current minDiff
		diff := int64(math.Abs(float64(A[0] - 2*A[i])))
		if minDiff > diff {
			minDiff = diff
			index = i // Store the index of the element that gives the minimum difference
		}
	}

	// Output the largest element and the element that minimizes the difference
	fmt.Println(A[0], A[index])
}

// <END-OF-CODE>
