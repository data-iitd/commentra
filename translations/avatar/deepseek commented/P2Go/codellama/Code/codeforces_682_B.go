
package main

import (
	"fmt"
	"sort"
)

func main() {
	// Read the number of elements
	var n int
	fmt.Scan(&n)

	// Read the list of elements
	l := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&l[i])
	}

	// Initialize variables
	f := 1 // Flag variable
	sort.Ints(l) // Sort the list
	c := 0 // Counter variable

	// Iterate through the list to find the maximum number of unique elements
	for i := 0; i < n; i++ {
		if l[i] > c {
			c++ // Increment the counter if the current element is greater than the counter
		}
	}

	// Print the result
	fmt.Println(c + 1) // Print the maximum number of unique elements
}

