package main

import (
	"fmt"
)

// Function to search for a key in the array A of size n
func search(A []int, n int, key int) int {
	i := 0 // Initialize index to 0
	A = append(A, key) // Sentinel value: place the key at the end of the array
	// Loop until the key is found in the array
	for A[i] != key {
		i++ // Increment index until the key is found
	}
	// Return true if the key was found before the sentinel, false otherwise
	return i
}

func main() {
	var n, q, key, sum int // Declare variables

	// Read the number of elements in the array
	fmt.Scan(&n)
	// Read the elements of the array
	A := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&A[i])
	}
	
	// Read the number of queries
	fmt.Scan(&q)
	// Process each query
	for i := 0; i < q; i++ {
		fmt.Scan(&key) // Read the key to search for
		// If the key is found in the array, increment the sum
		if search(A, n, key) < n {
			sum++
		}
	}
	
	// Output the total count of found keys
	fmt.Println(sum)
}

