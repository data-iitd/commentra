package main

import (
	"fmt"
)

// Function to perform linear search on an array
func linearSearch(S []int, n int, key int) int {
	i := 0 // Initialize index for searching
	count := 0 // Initialize count to track if the key is found

	// Loop until the key is found or the end of the array is reached
	for S[i] != key {
		i++ // Move to the next index
		// If the index exceeds the size of the array, the key is not found
		if i >= n {
			count = 1 // Set count to indicate the key was not found
			return count // Return count
		}
	}
	return count // Return count (0 if key is found)
}

func main() {
	var n, q int
	S := make([]int, 10000) // Declare array S
	T := make([]int, 10000) // Declare array T
	count := 0 // Initialize count for missing keys

	// Read the number of elements in the first array
	fmt.Scan(&n)
	// Read the elements into the first array S
	for i := 0; i < n; i++ {
		fmt.Scan(&S[i])
	}

	// Read the number of queries
	fmt.Scan(&q)
	// Read the elements into the second array T (the keys to search for)
	for j := 0; j < q; j++ {
		fmt.Scan(&T[j])
	}

	// Loop through each key in T to check if it exists in S
	for j := 0; j < q; j++ {
		key := T[j] // Get the current key to search
		// If the key is not found in S, increment the count
		if linearSearch(S, n, key) == 0 {
			count++ // Increment count for each missing key
		}
	}

	// Print the total count of keys that were not found in S
	fmt.Println(count)
}

// <END-OF-CODE>
