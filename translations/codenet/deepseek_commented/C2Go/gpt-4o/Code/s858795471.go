package main

import (
	"fmt"
)

func search(A []int, n, key int) bool {
	// Add the key to the end of the slice to handle the case where the key is not found
	A = append(A, key)
	i := 0
	// Loop until the key is found in the slice
	for A[i] != key {
		i++
	}
	// Return true if the key is found, otherwise return false
	return i != n
}

func main() {
	var n, q, key, sum int

	// Read the size of the array
	fmt.Scan(&n)
	A := make([]int, n)

	// Read the array elements
	for i := 0; i < n; i++ {
		fmt.Scan(&A[i])
	}

	// Read the number of queries
	fmt.Scan(&q)

	// Process each query
	for i := 0; i < q; i++ {
		fmt.Scan(&key)
		// Perform the search operation for the current query element
		if search(A, n, key) {
			sum++
		}
	}

	// Print the count of successful searches
	fmt.Println(sum)
}

// <END-OF-CODE>
