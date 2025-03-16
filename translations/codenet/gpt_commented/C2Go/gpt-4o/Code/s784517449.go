package main

import (
	"fmt"
)

var A [1000000]int // Declare an array A to hold up to 1,000,000 integers
var n int          // Variable n for the number of elements

// BinarySearch performs a binary search on the sorted array A for the given key
func binarySearch(key int) int {
	left := 0          // Initialize the left boundary of the search range
	right := n         // Initialize the right boundary of the search range

	// Continue searching while the left boundary is less than the right boundary
	for left < right {
		mid := (left + right) / 2 // Calculate the midpoint index
		if key == A[mid] {
			return 1 // If the key is found, return 1
		}
		if key > A[mid] {
			left = mid + 1 // If the key is greater, search in the right half
		} else {
			right = mid // If the key is smaller, search in the left half
		}
	}
	return 0 // If the key is not found, return 0
}

func main() {
	var i, q, k, sum int // Declare variables for iteration, number of queries, the key to search, and a sum counter

	// Read the number of elements in the array
	fmt.Scan(&n)

	// Read the elements into the array A
	for i = 0; i < n; i++ {
		fmt.Scan(&A[i])
	}

	// Read the number of queries
	fmt.Scan(&q)

	// Process each query
	for i = 0; i < q; i++ {
		fmt.Scan(&k) // Read the key to search for
		if binarySearch(k) == 1 { // Perform binary search for the key
			sum++ // Increment the sum if the key is found
		}
	}

	// Output the total number of keys found in the array
	fmt.Println(sum)
}

// <END-OF-CODE>
