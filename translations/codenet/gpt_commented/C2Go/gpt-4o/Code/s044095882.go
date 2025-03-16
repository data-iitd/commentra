package main

import (
	"fmt"
)

func main() {
	// Declare a variable to hold the size of the array
	var n int64

	// Read the size of the array from user input
	fmt.Scan(&n)

	// Declare two slices: one to hold the input values and another to count occurrences
	a := make([]int64, n)
	count := make([]int64, n)

	// Read the input values into the slice 'a', starting from index 1
	for i := int64(1); i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Initialize the count slice to zero for all indices
	for i := int64(0); i < n; i++ {
		count[i] = 0
	}

	// Count the occurrences of each value in the slice 'a'
	// The value at a[i] is used to index into the count slice
	for i := int64(1); i < n; i++ {
		count[a[i]-1]++
	}

	// Print the counts of each index in the count slice
	for i := int64(0); i < n; i++ {
		fmt.Println(count[i])
	}
}

// <END-OF-CODE>
