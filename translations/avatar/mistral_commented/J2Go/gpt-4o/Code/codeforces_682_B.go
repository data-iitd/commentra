package main

import (
	"fmt"
	"sort"
)

func main() {
	// Reading the number of elements in the list from the input
	var n int
	fmt.Scan(&n)

	// Creating a slice to store the elements
	list := make([]int, n)

	// Reading 'n' elements from the input and adding them to the slice
	for i := 0; i < n; i++ {
		fmt.Scan(&list[i]) // Reading an integer from the input and adding it to the slice
	}

	// Sorting the slice in ascending order
	sort.Ints(list)

	// Initializing a variable 'c' to keep track of the number of distinct elements
	c := 1

	// Iterating through the slice to find the number of distinct elements
	for i := 0; i < n; i++ {
		// If the current element is greater than or equal to the current count 'c', increment the count
		if list[i] >= c {
			c++
		}
	}

	// Writing the result to the output
	fmt.Println(c)
}

// Debugging method to print the deep representation of an object
func debug(obj ...interface{}) {
	fmt.Println(obj)
}

// <END-OF-CODE>
