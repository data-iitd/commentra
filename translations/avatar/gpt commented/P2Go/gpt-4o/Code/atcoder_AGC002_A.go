package main

import (
	"fmt"
)

func main() {
	var a, b int
	// Read two integers from input
	fmt.Scan(&a, &b)

	// Check if the first integer 'a' is positive
	if a > 0 {
		fmt.Println("Positive") // Output 'Positive' if 'a' is greater than 0
	} else if a <= 0 && b >= 0 {
		fmt.Println("Zero") // Output 'Zero' if 'a' is non-positive and 'b' is non-negative
	} else {
		// If 'a' is negative and 'b' is also negative
		if (a+b)%2 == 0 {
			fmt.Println("Negative") // Output 'Negative' if the sum of 'a' and 'b' is even
		} else {
			fmt.Println("Positive") // Output 'Positive' if the sum of 'a' and 'b' is odd
		}
	}
}

// <END-OF-CODE>
