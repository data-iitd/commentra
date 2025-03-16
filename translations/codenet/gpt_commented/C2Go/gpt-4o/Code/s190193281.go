package main

import (
	"fmt"
)

const N = 1000000 // Maximum size for the array S
const Q = 50000   // Maximum size for the array T

var n int
var S [N]int // Declare the sorted array S
var T [Q]int // Declare the query array T

// Function to perform binary search on the sorted array S
func binarySearch(key int) int {
	left, right := 0, n // Initialize left and right pointers for the search range
	for left < right {   // Continue searching while the range is valid
		mid := (left + right) / 2 // Calculate the middle index
		if S[mid] == key {
			return 1 // If the key is found, return 1
		} else if key < S[mid] {
			right = mid // Narrow the search to the left half
		} else {
			left = mid + 1 // Narrow the search to the right half
		}
	}
	return 0 // If the key is not found, return 0
}

func main() {
	var q, c int // Declare variables: q for number of queries, c for count of found keys

	// Read the number of elements in the sorted array S
	fmt.Scan(&n)

	// Read the elements into the sorted array S
	for i := 0; i < n; i++ {
		fmt.Scan(&S[i])
	}

	// Read the number of queries
	fmt.Scan(&q)

	// Process each query to check if it exists in the sorted array S
	for i := 0; i < q; i++ {
		fmt.Scan(&T[i]) // Read the query element into array T
		if binarySearch(T[i]) == 1 { // If the element is found, increment the count
			c++
		}
	}

	// Output the total count of found elements
	fmt.Println(c)
}

// <END-OF-CODE>
