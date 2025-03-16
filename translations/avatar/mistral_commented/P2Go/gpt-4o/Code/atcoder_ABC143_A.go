package main

import (
	"fmt"
)

func main() {
	var A, B int

	// Read two integers from the user, separated by a space
	fmt.Scan(&A, &B)

	// Calculate the difference between A and 2 times B
	ans := A - 2*B

	// Check if the difference is negative
	if ans < 0 {
		// If it is, set it to zero
		ans = 0
	}

	// Print the final answer
	fmt.Println(ans)
}

// <END-OF-CODE>
