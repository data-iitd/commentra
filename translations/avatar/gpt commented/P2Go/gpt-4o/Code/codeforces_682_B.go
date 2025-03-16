package main

import (
	"fmt"
	"sort"
)

func main() {
	// Read the number of elements
	var n int
	fmt.Scan(&n) // Number of elements in the list

	// Read the list of integers
	l := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&l[i]) // List of integers from input
	}

	// Initialize a variable to track unique counts
	f := 1 // Starting count for unique elements
	sort.Ints(l) // Sort the list to facilitate counting unique elements

	// Initialize a counter for unique elements
	c := 0 // Counter for unique elements

	// Iterate through the sorted list to count unique elements
	for _, i := range l {
		if i > c { // Check if the current element is greater than the counter
			c++ // Increment the counter for unique elements
		}
	}

	// Output the total count of unique elements
	fmt.Println(c + 1) // Print the count of unique elements (including the first element)
}

// <END-OF-CODE>
