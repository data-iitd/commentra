package main

import (
	"fmt"
)

func main() {
	// Take the number of elements in the list as input
	var n int
	fmt.Scan(&n)

	// Initialize a slice 'l' to store the input elements
	l := make([]int, n)

	// Read the list elements from the standard input
	for i := 0; i < n; i++ {
		fmt.Scan(&l[i])
	}

	// Initialize variables 'high' and 'tower' with initial values
	high := 1
	tower := n
	maximum := 1 // Initialize maximum to 1

	// Iterate through the list starting from the second element
	for i := 1; i < n; i++ {
		// If the current element is same as the previous one, decrement 'tower' and increment 'high'
		if l[i] == l[i-1] {
			tower--
			high++
		} else {
			// If the current element is different, check if 'high' is greater than the current maximum and update it if true
			if high > maximum {
				maximum = high
			}
			high = 1
		}
	}

	// Check if the last 'high' value is greater than the current maximum and update it if true
	if high > maximum {
		maximum = high
	}

	// Print the final result
	fmt.Println(maximum, tower)
}

// <END-OF-CODE>
