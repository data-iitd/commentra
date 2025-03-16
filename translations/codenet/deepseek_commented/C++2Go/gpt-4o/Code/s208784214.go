package main

import (
	"fmt"
)

func main() {
	// Step 1: Declare variables
	// We declare two integer variables, N and A, to store user input.
	var N, A int

	// Step 2: Read input values
	// We read two integer values from the standard input and store them in variables N and A.
	fmt.Scan(&N, &A)

	// Step 3: Perform the required operation
	// We check if the remainder of N divided by 500 is less than or equal to A.
	// If the condition is true, we print "Yes"; otherwise, we print "No".
	if N%500 <= A {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}

	// Step 4: Return from the main function
	// In Go, we do not need to explicitly return from the main function.
}

// <END-OF-CODE>
