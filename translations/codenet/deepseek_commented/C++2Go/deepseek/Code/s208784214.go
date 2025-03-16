package main

import (
	"fmt"
)

// Declare variables N and A to store user input.
var N, A int

func main() {
	// Read input values
	// Read two integer values from the standard input and store them in variables N and A.
	fmt.Scan(&N, &A)
	
	// Perform the required operation
	// Check if the remainder of N divided by 500 is less than or equal to A.
	// If the condition is true, print "Yes"; otherwise, print "No".
	if N % 500 <= A {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

