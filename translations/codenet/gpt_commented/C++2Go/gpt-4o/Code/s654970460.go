package main

import (
	"fmt"
)

func main() {
	// Declare an integer variable 'n' for the number of elements,
	// a slice 'a' to store the elements, and an integer 'i' for iteration.
	var n int
	a := make([]int, 101)

	// Read the number of elements 'n' from the user.
	fmt.Scan(&n)

	// Loop to read 'n' elements into the slice 'a'.
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Output the last element of the slice (a[n-1]).
	fmt.Print(a[n-1])

	// Loop to output the elements of the slice in reverse order,
	// starting from the second last element down to the first element.
	for i := 1; i < n; i++ {
		fmt.Print(" ", a[n-i-1])
	}

	// Print a newline character at the end of the output.
	fmt.Println()
}

// <END-OF-CODE>
