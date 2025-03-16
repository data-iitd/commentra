package main

import (
	"fmt"
)

func main() {
	// Declare an integer variable 'n' for the number of elements,
	// an array 'a' of size 101 to store the elements, and an integer 'i' for iteration.
	var n int
	var a [101]int

	// Read the number of elements 'n' from the user.
	fmt.Scan(&n)

	// Loop to read 'n' elements into the array 'a'.
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Output the last element of the array (a[n-1]).
	fmt.Print(a[n-1])

	// Loop to output the elements of the array in reverse order,
	// starting from the second last element down to the first element.
	for i := 1; i < n; i++ {
		fmt.Print(" ", a[n-i-1])
	}

	// Print a newline character at the end of the output.
	fmt.Println()
}

