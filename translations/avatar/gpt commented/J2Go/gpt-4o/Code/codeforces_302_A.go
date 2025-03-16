package main

import (
	"fmt"
)

func main() {
	// Read the number of elements in the array and the number of queries
	var n, k int
	fmt.Scan(&n, &k)

	// Initialize a slice to hold the input values
	arr := make([]int, n)

	// Populate the slice with input values
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}

	// Counters for the number of 1s (o) and 0s (e) in the array
	o, e := 0, 0

	// Count the number of 1s and 0s in the array
	for i := 0; i < n; i++ {
		if arr[i] == 1 {
			o++ // Increment count of 1s
		} else {
			e++ // Increment count of 0s
		}
	}

	// Process each query
	for i := 0; i < k; i++ {
		// Read the left and right indices for the current query
		var l, r int
		fmt.Scan(&l, &r)

		// Check if the number of elements in the range is odd
		if (r-l+1)%2 == 1 {
			fmt.Println("0") // If odd, print "0"
		} else {
			// If even, check if we can form a valid pair of 1s and 0s
			if (r-l+1)/2 <= o && (r-l+1)/2 <= e {
				fmt.Println("1") // Print "1" if valid pairs can be formed
			} else {
				fmt.Println("0") // Otherwise, print "0"
			}
		}
	}
}

// <END-OF-CODE>
