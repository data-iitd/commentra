package main

import (
	"fmt"
	"sort"
)

func main() {
	// Read the number of elements
	var N int
	fmt.Scanf("%d", &N)

	// Initialize a vector to store the elements
	A := make([]int, N)

	// Input the elements into the vector
	for i := 0; i < N; i++ {
		fmt.Scanf("%d", &A[i])
	}

	// Sort the vector in descending order
	sort.Slice(A, func(i, j int) bool { return A[i] > A[j] })

	// Initialize variables to track the minimum difference and the corresponding index
	var index int
	max := int(1e9)

	// Find the element in the vector that minimizes the difference with twice the second largest element
	for i := 1; i < N; i++ {
		// Calculate the absolute difference and update if it's smaller than the current max
		if max > abs(A[0] - 2*A[i]) {
			max = abs(A[0] - 2*A[i])
			index = i // Store the index of the element that gives the minimum difference
		}
	}

	// Output the largest element and the element that minimizes the difference
	fmt.Printf("%d %d\n", A[0], A[index])
}

