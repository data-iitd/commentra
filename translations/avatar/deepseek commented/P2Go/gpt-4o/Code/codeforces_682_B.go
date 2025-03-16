package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the number of elements

	l := make([]int, n) // Initialize a slice to hold the elements

	for i := 0; i < n; i++ {
		fmt.Scan(&l[i]) // Read the list of elements
	}

	sort.Ints(l) // Sort the list

	c := 0 // Counter variable

	// Iterate through the list to find the maximum number of unique elements
	for _, i := range l {
		if i > c {
			c++ // Increment the counter if the current element is greater than the counter
		}
	}

	// Print the result
	fmt.Println(c + 1) // Print the maximum number of unique elements
}

// <END-OF-CODE>
