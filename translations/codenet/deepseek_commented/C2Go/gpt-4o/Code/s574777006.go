package main

import (
	"fmt"
)

func main() {
	var n, q int
	var sum int
	var x [10000]int
	var y [500]int

	fmt.Scan(&n) // Read the number of elements

	for i := 0; i < n; i++ {
		fmt.Scan(&x[i]) // Read the elements of array x
	}

	fmt.Scan(&q) // Read the number of queries

	for i := 0; i < q; i++ {
		fmt.Scan(&y[i]) // Read the elements of array y
	}

	for i := 0; i < q; i++ { // For each query
		for j := 0; j < n; j++ { // Check each element in array x
			if y[i] == x[j] { // If the query matches an element in x
				sum++ // Increment the sum
				break // Break out of the inner loop
			}
		}
	}

	fmt.Println(sum) // Print the sum of matches
}

// <END-OF-CODE>
