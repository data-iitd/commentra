package main

import (
	"fmt"
)

func main() {
	// Get the number of elements in the array from user input
	var N int
	fmt.Scan(&N)

	// Initialize a slice 'n' of size N
	n := make([]int, N)

	// Get the elements of the array from user input and store them in 'n'
	for i := 0; i < N; i++ {
		fmt.Scan(&n[i])
	}

	// Initialize variables 'a' and 'pos'
	a := 1
	pos := 0

	// Iterate through the array 'n' starting from the second element
	for i := 1; i < N; i++ {
		// Check if the current element is greater than the previous one
		if n[pos] > n[i] {
			// Increment the variable 'a' if the condition is true
			a++
			// Update the position of the previous greater element
			pos = i
		}
	}

	// Print the value of 'a' as the output
	fmt.Println(a)
}

// <END-OF-CODE>
