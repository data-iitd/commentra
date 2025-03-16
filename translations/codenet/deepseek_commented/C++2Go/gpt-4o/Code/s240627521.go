package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N) // Read the number of elements in the array A
	A := make([]int64, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i]) // Read the elements of the array A
	}
	sort.Slice(A, func(i, j int) bool {
		return A[i] > A[j] // Sort the array A in descending order
	})

	var index int
	max := int64(math.MaxInt64) // Initialize max with a large value
	for i := 1; i < N; i++ { // Iterate through the array to find the optimal pair
		if max > int64(math.Abs(float64(A[0]-2*A[i]))) { // Check if the current difference is smaller than the previous minimum
			max = int64(math.Abs(float64(A[0] - 2*A[i]))) // Update the minimum difference
			index = i // Store the index of the current element
		}
	}
	fmt.Println(A[0], A[index]) // Output the first and the found optimal pair
}

// <END-OF-CODE>
