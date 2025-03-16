package main

import (
	"fmt"
)

func main() {
	var A, B int

	// Read two integers A and B from user input, separated by a space
	fmt.Scan(&A, &B)

	// Calculate the result by subtracting twice the value of B from A
	ans := A - 2*B

	// If the result is negative, set it to zero
	if ans < 0 {
		ans = 0
	}

	// Print the final result
	fmt.Println(ans)
}

// <END-OF-CODE>
