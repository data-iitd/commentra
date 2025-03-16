package main

import (
	"fmt"
)

// Function declaration for linear search
func linearSearch(a []int, n int, key int) bool {
	i := 0 // Initializing index i to zero

	// Adding the key to the end of the array for the case when the key is already present at the beginning
	a = append(a, key)

	// Linear search algorithm to find the index of the key in the array
	for a[i] != key {
		i++ // Incrementing index i until the key is found
	}

	// Returning true if the key is found, and false otherwise
	return i != n
}

func main() {
	var n, q, t int // Declaring variables n for array size, q for number of queries, and t for query elements
	count := 0     // Initializing count to zero

	// Reading the size of the array from user input
	fmt.Scan(&n)

	// Declaring an array s of size n
	s := make([]int, n)

	// Reading array elements into the array s
	for i := 0; i < n; i++ {
		fmt.Scan(&s[i])
	}

	// Reading the number of queries from user input
	fmt.Scan(&q)

	// Looping through each query
	for i := 0; i < q; i++ {
		fmt.Scan(&t) // Reading a query element from user input

		// Calling the linear search function to check if the query element is present in the array
		if linearSearch(s, n, t) {
			count++ // If the query element is present, increment the count
		}
	}

	// Printing the final count of query elements present in the array
	fmt.Println(count)
}

// <END-OF-CODE>
