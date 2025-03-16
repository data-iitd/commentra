package main

import (
	"fmt"
)

const N = 1000000
const Q = 50000

var n int
var S []int
var T []int

// Function to perform binary search on an array
func binarySearch(key int) int {
	left, right := 0, n // Initialize left and right pointers
	for left < right {   // While the array is not yet searched completely
		mid := (left + right) / 2 // Calculate the middle index
		if S[mid] == key {
			return 1 // If key is found, return 1
		} else if key < S[mid] {
			right = mid // If key is smaller, search in left half
		} else {
			left = mid + 1 // If key is greater, search in right half
		}
	}
	return 0 // If key is not present in the array, return 0
}

func main() {
	var q, c int // Initialize variables

	// Read the size of the array
	fmt.Print("Enter the size of the array: ")
	fmt.Scan(&n)

	// Allocate memory for the array
	S = make([]int, n)

	// Read the elements of the array
	fmt.Printf("Enter %d integers:\n", n)
	for i := 0; i < n; i++ {
		fmt.Printf("Element %d: ", i+1)
		fmt.Scan(&S[i])
	}

	// Read the number of queries
	fmt.Print("Enter the number of queries: ")
	fmt.Scan(&q)

	// Allocate memory for the queries
	T = make([]int, q)

	// Read the queries
	fmt.Printf("Enter %d integers to be searched:\n", q)
	for i := 0; i < q; i++ {
		fmt.Printf("Query %d: ", i+1)
		fmt.Scan(&T[i])

		// Check if the query is present in the array
		if binarySearch(T[i]) == 1 {
			c++
		}
	}

	// Print the number of queries present in the array
	fmt.Printf("Number of queries present in the array: %d\n", c)
}

// <END-OF-CODE>
