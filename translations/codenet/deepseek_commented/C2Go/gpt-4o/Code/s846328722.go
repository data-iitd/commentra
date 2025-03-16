package main

import (
	"fmt"
)

func linearSearch(a []int, n int, key int) bool {
	// Modify the slice to facilitate the search
	a = append(a, key)

	// Perform the linear search
	i := 0
	for a[i] != key {
		i++
	}

	// Return true if the key is found, false otherwise
	return i != n
}

func main() {
	var n, q, t int
	count := 0

	// Read the number of elements
	fmt.Scan(&n)

	// Create a slice to hold the elements
	s := make([]int, n)

	// Read the elements into the slice s
	for i := 0; i < n; i++ {
		fmt.Scan(&s[i])
	}

	// Read the number of queries
	fmt.Scan(&q)

	// Perform a linear search for each query
	for i := 0; i < q; i++ {
		fmt.Scan(&t)
		if linearSearch(s, n, t) {
			count++
		}
	}

	// Print the total count of successful searches
	fmt.Println(count)
}

// <END-OF-CODE>
