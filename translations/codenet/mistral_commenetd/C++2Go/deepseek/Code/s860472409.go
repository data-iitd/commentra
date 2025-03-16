package main

import (
	"fmt"
)

func main() {
	// Declare variables
	var N, ans, i, count int

	// Read the number of elements in the array from the user
	fmt.Scan(&N)

	// Declare and initialize an integer array A of size N
	A := make([]int, N)

	// Read elements of the array A from the user
	for i = 0; i < N; i++ {
		fmt.Scan(&A[i]) // Read the i-th element of array A
	}

	// Initialize variables i, ans, and count to 0
	i = 0
	ans = 0
	count = 0

	// Traverse the array using a while loop
	for i < N-1 {
		// Check if the current and next elements of the array are equal
		if A[i] == A[i+1] {
			// Increment the count if the current and next elements are equal
			count++

			// If the count is odd, increment the answer
			if count%2 != 0 {
				ans++
			}
		} else {
			// Reset the count to 0 if the current and next elements are not equal
			count = 0
		}

		// Increment the index i to move to the next element of the array
		i++
	}

	// Print the answer
	fmt.Println(ans)
}

