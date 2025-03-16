package main

import (
	"fmt"
)

const (
	N = 1000000  // Maximum size for the array S
	Q = 50000    // Maximum size for the array T
)

var (
	n    int
	S    [N]int  // Declare variables: n for the number of elements, S for the sorted array, T for the query array
	T    [Q]int
	c    int  // Declare variables: c for count of found keys
)

// Function to perform binary search on the sorted array S
func binarySearch(key int) int {
	left, right := 0, n
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
	var i, q int

	// Read the number of elements in the sorted array S
	fmt.Scan(&n)

	// Read the elements into the sorted array S
	for i = 0; i < n; i++ {
		fmt.Scan(&S[i])
	}

	// Read the number of queries
	fmt.Scan(&q)

	// Process each query to check if it exists in the sorted array S
	for i = 0; i < q; i++ {
		fmt.Scan(&T[i])
		if binarySearch(T[i]) == 1 {
			c++
		}
	}

	// Output the total count of found elements
	fmt.Println(c)
}

