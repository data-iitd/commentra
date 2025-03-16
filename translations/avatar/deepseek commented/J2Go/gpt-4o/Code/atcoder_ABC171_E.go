package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the number of elements (n) from the user
	a := make([]int, n) // Initialize a slice 'a' of size n to store the elements
	r := 0 // Initialize a variable 'r' to store the result of XOR operation

	// Read the elements of the slice 'a' from the user and perform XOR operation on each element
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		r ^= a[i]
	}

	// Print the result of XOR operation for each element in the slice 'a'
	for i := 0; i < n; i++ {
		if i != 0 {
			fmt.Print(" ") // Print a space before each element except the first one
		}
		fmt.Print(r ^ a[i]) // Print the result of XOR operation for each element
	}
}

// <END-OF-CODE>
