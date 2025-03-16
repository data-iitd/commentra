package main

import (
	"fmt"
)

// Function to search for a key in an array
func search(A []int, n int, key int) int {
	// Add the key to the end of the array
	A = append(A, key)
	// Search for the key in the array using a while loop
	for i := 0; A[i] != key; i++ {
	}
	// Return 1 if the key was found before the end of the array, otherwise return 0
	return i != n
}

func main() {
	var n, // Number of elements in the array
		q, // Number of queries
		key, // Key to be searched for
		sum int // Variable to store the number of keys found
		A []int // Array to store the elements
		i int // Loop counter

	// Read the number of elements in the array from the user
	fmt.Scan(&n)
	// Read the elements of the array from the user
	A = make([]int, n)
	for i = 0; i < n; i++ {
		fmt.Scan(&A[i])
	}
	// Read the number of queries from the user
	fmt.Scan(&q)
	// For each query, search for the key in the array and if it is found, increment the sum
	for i = 0; i < q; i++ {
		fmt.Scan(&key) // Read the key to be searched for
		// Call the search function to find the key in the array
		if search(A, n, key) { // If the key is found, increment the sum
			sum++
		}
	}
	// Print the number of keys found
	fmt.Println(sum)
}

