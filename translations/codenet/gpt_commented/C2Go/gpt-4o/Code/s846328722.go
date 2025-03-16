package main

import (
	"fmt"
)

// Function to perform linear search
func linearSearch(a []int, n int, key int) bool {
	// Sentinel value: place the key at the end of the slice
	a = append(a, key)

	i := 0
	// Search for the key in the array
	for a[i] != key {
		i++ // Increment index until the key is found
	}

	// Return true if the key was found within the original array bounds
	return i != n
}

func main() {
	var n, q, t int
	count := 0

	// Read the number of elements in the array
	fmt.Scan(&n)

	// Create a slice to hold the elements
	s := make([]int, n)

	// Read n elements into the slice s
	for i := 0; i < n; i++ {
		fmt.Scan(&s[i])
	}

	// Read the number of queries
	fmt.Scan(&q)

	// Process each query to check if the element exists in the array
	for i := 0; i < q; i++ {
		fmt.Scan(&t) // Read the query element
		// Use linear search to check if the element t is in the slice s
		if linearSearch(s, n, t) {
			count++ // Increment count if found
		}
	}

	// Output the total count of found elements
	fmt.Println(count)
}

// <END-OF-CODE>
