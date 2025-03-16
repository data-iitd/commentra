package main

import (
	"fmt"
)

func main() {
	// Creating a variable to hold the number of elements (N)
	var N int
	// Reading the number of elements from the input
	fmt.Scan(&N)

	// Creating a map to store the mapping of integer values to their order of input
	idorder := make(map[int]int)

	// Looping through the range from 1 to N to read N integers
	for i := 1; i <= N; i++ {
		var A int
		// Reading an integer A from the input
		fmt.Scan(&A)
		// Storing the integer A in the map with its order of input (i)
		idorder[A] = i
	}

	// Looping through the range from 1 to N to print the order of each integer
	for i := 1; i <= N; i++ {
		// Retrieving and printing the order of the integer i from the map
		fmt.Print(idorder[i])
		// Printing a space after each output
		fmt.Print(" ")
	}
}

// <END-OF-CODE>
