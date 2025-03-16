package main

import (
	"fmt"
)

func main() {
	// Create a variable to hold the number of elements in the array
	var n int
	fmt.Scan(&n)

	// Initialize a slice to hold the input integers
	a := make([]int, n)

	// Variable to hold the cumulative XOR of all elements
	r := 0

	// Read each integer from input and compute the cumulative XOR
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		r ^= a[i] // Update the cumulative XOR with the current element
	}

	// For each element in the array, print the result of XORing the cumulative XOR with the element
	for i := 0; i < n; i++ {
		if i != 0 {
			fmt.Print(" ") // Print a space before the next number if it's not the first element
		}
		fmt.Print(r ^ a[i]) // Print the result of XORing the cumulative XOR with the current element
	}
}

// <END-OF-CODE>
