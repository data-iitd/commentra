package main

import (
	"fmt"
	"sort"
)

func main() {
	// Read the number of elements
	var n int
	fmt.Scan(&n)

	// Initialize a slice to store the input integers
	list := make([]int, n)

	// Read n integers from input and add them to the slice
	for i := 0; i < n; i++ {
		fmt.Scan(&list[i])
	}

	// Sort the slice of integers in ascending order
	sort.Ints(list)

	// Initialize a counter to track the maximum consecutive integer
	c := 1

	// Iterate through the sorted slice to find the maximum consecutive integer
	for i := 0; i < n; i++ {
		// If the current integer is greater than or equal to the counter, increment the counter
		if list[i] >= c {
			c++
		}
	}

	// Print the result which is the maximum consecutive integer found
	fmt.Println(c)
}

// Debugging method to print objects to the error output
func debug(args ...interface{}) {
	fmt.Println(args...)
}

// <END-OF-CODE>
