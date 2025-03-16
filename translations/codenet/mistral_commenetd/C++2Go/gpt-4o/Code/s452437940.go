package main

import (
	"fmt"
)

func main() {
	// Declare variables
	var a, b, x int64

	// Read input values from standard input
	fmt.Scanf("%d %d %d", &a, &b, &x)

	// Calculate the difference between the number of complete x-blocks in b and a
	s := (b / x) - (a / x)

	// If a is a multiple of x, then the last x-block in a is complete, so add 1 to the result
	if a%x == 0 {
		s++
	}

	// Print the result to standard output
	fmt.Println(s)
}

// <END-OF-CODE>
