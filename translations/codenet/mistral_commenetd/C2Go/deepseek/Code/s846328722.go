package main

import (
	"fmt"
)

// Function declaration for linear search
func linearSearch(a []int, n int, key int) bool {
	// Linear search algorithm to find the index of the key in the array
	for i := 0; i < n; i++ {
		if a[i] == key {
			return true
		}
	}
	return false
}

func main() {
	var n, q, t int
	var s []int

	// Reading the size of the array from user input
	fmt.Scan(&n)

	// Reading array elements into the array s
	s = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&s[i])
	}

	// Reading the number of queries from user input
	fmt.Scan(&q)

	// Initializing count to zero
	count := 0

	// Looping through each query
	for i := 0; i < q; i++ {
		// Reading a query element from user input
		fmt.Scan(&t)

		// Calling the linear search function to check if the query element is present in the array
		if linearSearch(s, n, t) {
			count++ // If the query element is present, increment the count
		}
	}

	// Printing the final count of query elements present in the array
	fmt.Println(count)
}

