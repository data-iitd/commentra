package main

import (
	"fmt"
)

func main() {
	// Declare variables
	var N, ans, i, count int

	// Read the number of elements in the array
	fmt.Scan(&N)

	// Initialize an array of size N
	A := make([]int, N)

	// Input the elements into the array
	for i = 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	// Initialize index and counters
	i = 0
	ans = 0
	count = 0

	// Loop through the array until the second last element
	for i < N-1 {
		// Check if the current element is equal to the next element
		if A[i] == A[i+1] {
			count++ // Increment count for consecutive elements

			// If count is odd, increment the answer
			if count%2 != 0 {
				ans++
			}
		} else {
			// Reset count if elements are not equal
			count = 0
		}
		i++ // Move to the next element
	}

	// Output the final answer
	fmt.Println(ans)
}

