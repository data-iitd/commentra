package main

import (
	"fmt"
	"unsafe"
)

const (
	N = 1000000
	Q = 50000
)

var (
	n  int
	S  [N]int
	T  [Q]int
)

// Function to perform binary search on an array
func binarySearch(key int) int {
	left := 0
	right := n
	for left < right {
		mid := (left + right) / 2
		if S[mid] == key {
			return 1
		} else if key < S[mid] {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return 0
}

func main() {
	var i, j, q, c int

	// Read the size of the array
	fmt.Print("Enter the size of the array: ")
	fmt.Scan(&n)

	// Allocate memory for the array
	S = [N]int{}

	// Read the elements of the array
	fmt.Printf("Enter %d integers:\n", n)
	for i = 0; i < n; i++ {
		fmt.Printf("Element %d: ", i+1)
		fmt.Scan(&S[i])
	}

	// Read the number of queries
	fmt.Print("Enter the number of queries: ")
	fmt.Scan(&q)

	// Allocate memory for the queries
	T = [Q]int{}

	// Read the queries
	fmt.Printf("Enter %d integers to be searched:\n", q)
	for i = 0; i < q; i++ {
		fmt.Printf("Query %d: ", i+1)
		fmt.Scan(&T[i])

		// Check if the query is present in the array
		if binarySearch(T[i]) == 1 {
			c++
		}
	}

	// Print the number of queries present in the array
	fmt.Printf("Number of queries present in the array: %d\n", c)

	// <END-OF-CODE>