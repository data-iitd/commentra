package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n) // Reading the number of elements

	list := make([]int, n) // Creating a slice to store the elements

	// Reading the elements and adding them to the slice
	for i := 0; i < n; i++ {
		fmt.Scan(&list[i])
	}

	sort.Ints(list) // Sorting the slice

	c := 1 // Initializing the counter variable

	// Iterating through the sorted list to find the smallest missing positive integer
	for _, value := range list {
		if value >= c {
			c++
		}
	}

	fmt.Println(c) // Printing the result
}

// Debug method for debugging purposes
func debug(args ...interface{}) {
	fmt.Println(args...)
}

// <END-OF-CODE>
