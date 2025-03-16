package main

import (
	"fmt"
)

func main() {
	// Declare two integer variables A and B
	var A, B int

	// Read input values for A and B from the user
	fmt.Scan(&A, &B)

	// Calculate the sum of A and B and store it in variable C
	C := A + B

	// Check if A, B, and C are all not divisible by 3
	if A%3 != 0 && B%3 != 0 && C%3 != 0 {
		// If the condition is true, output "Impossible"
		fmt.Println("Impossible")
	} else {
		// If the condition is false, output "Possible"
		fmt.Println("Possible")
	}
}

