package main

import "fmt"

// Function declaration for linear search
func linersearch(a []int, n int, key int) int {
	i := 0 // Initializing index i to zero

	// Adding the key to the end of the array for the case when the key is already present at the beginning
	a = append(a, key)

	// Linear search algorithm to find the index of the key in the array
	for a[i] != key {
		i++ // Incrementing index i until the key is found
	}

	// Returning 1 if the key is found, and 0 otherwise
	if i != n {
		return 1
	} else {
		return 0
	}
}

func main() {
	var i, n int // Declaring variables i and n for array index and size
	var s []int  // Declaring an array s of size 100000
	var q, t int // Declaring variables q and t for number of queries and query elements
	var count int = 0 // Initializing count to zero

	// Reading the size of the array from user input
	fmt.Scan(&n)

	// Reading array elements into the array s
	for i = 0; i < n; i++ {
		fmt.Scan(&s[i])
	}

	// Reading the number of queries from user input
	fmt.Scan(&q)

	// Looping through each query
	for i = 0; i < q; i++ {
		fmt.Scan(&t) // Reading a query element from user input

		// Calling the linear search function to check if the query element is present in the array
		if linersearch(s, n, t) == 1 {
			count++ // If the query element is present, increment the count
		}
	}

	// Printing the final count of query elements present in the array
	fmt.Println(count)
}

