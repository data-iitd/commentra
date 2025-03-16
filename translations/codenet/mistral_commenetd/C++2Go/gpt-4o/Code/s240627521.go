package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	var N int // Variable to store the number of elements in the slice
	fmt.Scan(&N) // Read the number of elements from the standard input
	A := make([]int64, N) // Declare and initialize a slice A of size N

	for i := 0; i < N; i++ { // Iterate through the range [0, N) and read each element into the slice
		fmt.Scan(&A[i])
	}

	sort.Slice(A, func(i, j int) bool { return A[i] > A[j] }) // Sort the slice A in descending order

	var index int // Variable to store the index of the second smallest element
	max := int64(math.MaxInt64) // Initialize the maximum difference to an infinite value

	for i := 1; i < N; i++ { // Iterate through the range [1, N)
		if max > int64(math.Abs(float64(A[0]-2*A[i]))) { // Check if the current difference is greater than the maximum difference
			max = int64(math.Abs(float64(A[0] - 2*A[i]))) // Update the maximum difference if it is
			index = i // Update the index of the second smallest element
		}
	}

	fmt.Println(A[0], A[index]) // Output the smallest and second smallest elements
}

// <END-OF-CODE>
