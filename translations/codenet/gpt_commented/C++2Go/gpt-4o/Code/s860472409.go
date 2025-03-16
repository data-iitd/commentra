package main

import (
	"fmt"
)

func main() {
	// Declare variables
	var N, ans, count int

	// Read the number of elements in the array
	fmt.Scan(&N)

	// Initialize a slice of size N
	A := make([]int, N)

	// Input the elements into the slice
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	// Initialize index and counters
	i := 0
	ans = 0    // To store the final answer
	count = 0  // To count consecutive equal elements

	// Loop through the slice until the second last element
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
