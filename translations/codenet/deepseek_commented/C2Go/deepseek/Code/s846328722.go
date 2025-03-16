package main

import (
	"fmt"
)

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

	// Read the number of elements
	fmt.Scan(&n)

	// Read the elements into the array s
	s := make([]int, n)
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

