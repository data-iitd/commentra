package main

import (
	"fmt"
)

func main() {
	// Declare variables to hold the number of elements (n), the threshold (k), and the number of queries (q)
	var n, k, q int64

	// Read the values of n, k, and q from user input
	fmt.Scan(&n, &k, &q)

	// Initialize a slice to count occurrences of each element, with size n+1 (to use 1-based indexing)
	arr := make([]int64, n+1)

	// Process each query to count occurrences of the queried elements
	for i := int64(0); i < q; i++ {
		var temp int64
		// Read the queried element and increment its count in the array
		fmt.Scan(&temp)
		arr[temp] += 1 // Increment the count for the queried element
	}

	// Check each element from 1 to n to see if its count exceeds the threshold (q - k)
	for i := int64(1); i <= n; i++ {
		// If the count of the element is greater than (q - k), print "Yes"
		if arr[i] > (q - k) {
			fmt.Println("Yes")
		} else {
			// Otherwise, print "No"
			fmt.Println("No")
		}
	}
}

// <END-OF-CODE>
