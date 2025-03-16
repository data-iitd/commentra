package main

import (
	"fmt"
)

// Function to search for a key in an array
func search(A []int, n, key int) bool {
	// Add the key to the end of the array
	A = append(A, key)
	i := 0
	// Search for the key in the array using a while loop
	for A[i] != key {
		i++
	}
	// Return true if the key was found before the end of the array, otherwise return false
	return i != n
}

func main() {
	var n, q, key, sum int

	// Read the number of elements in the array from the user
	fmt.Scan(&n)
	A := make([]int, n) // Create a slice to store the elements

	// Read the elements of the array from the user
	for i := 0; i < n; i++ {
		fmt.Scan(&A[i])
	}

	// Read the number of queries from the user
	fmt.Scan(&q)

	// For each query, search for the key in the array and if it is found, increment the sum
	for i := 0; i < q; i++ {
		fmt.Scan(&key) // Read the key to be searched for
		// Call the search function to find the key in the array
		if search(A, n, key) {
			sum++ // If the key is found, increment the sum
		}
	}

	// Print the number of keys found
	fmt.Println(sum)
}

// <END-OF-CODE>
