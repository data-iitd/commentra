package main

import (
	"fmt"
)

// Function to search for a key in the array A of size n
func search(A []int, n, key int) bool {
	i := 0 // Initialize index to 0
	A = append(A, key) // Sentinel value: place the key at the end of the array
	// Loop until the key is found in the array
	for A[i] != key {
		i++ // Increment index until the key is found
	}
	// Return true if the key was found before the sentinel, false otherwise
	return i != n
}

func main() {
	var n, q, key, sum int // Declare variables
	fmt.Scan(&n)
	A := make([]int, n) // Create a slice of size n

	// Read the elements of the array
	for i := 0; i < n; i++ {
		fmt.Scan(&A[i])
	}

	// Read the number of queries
	fmt.Scan(&q)
	// Process each query
	for i := 0; i < q; i++ {
		fmt.Scan(&key) // Read the key to search for
		// If the key is found in the array, increment the sum
		if search(A, n, key) {
			sum++
		}
	}

	// Output the total count of found keys
	fmt.Println(sum)
}

// <END-OF-CODE>
