package main

import (
	"fmt"
)

// Function to perform linear search
func linearSearch(a []int, n int, key int) bool {
	for i := 0; i < n; i++ {
		if a[i] == key {
			return true
		}
	}
	return false
}

func main() {
	var n, q, t, count int

	// Read the number of elements in the array
	fmt.Scan(&n)

	// Read n elements into the array s
	s := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&s[i])
	}

	// Read the number of queries
	fmt.Scan(&q)

	// Process each query to check if the element exists in the array
	for i := 0; i < q; i++ {
		fmt.Scan(&t) // Read the query element
		// Use linear search to check if the element t is in the array s
		if linearSearch(s, n, t) {
			count++ // Increment count if found
		}
	}

	// Output the total count of found elements
	fmt.Println(count)
}
