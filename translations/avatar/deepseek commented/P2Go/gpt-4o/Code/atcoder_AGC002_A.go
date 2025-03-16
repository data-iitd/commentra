package main

import (
	"fmt"
)

func main() {
	var a, b int
	fmt.Scan(&a, &b) // Read two integers a and b

	if a > 0 {
		// Check if a is greater than 0
		fmt.Println("Positive")
	} else if a <= 0 && b >= 0 {
		// Check if a is less than or equal to 0 and b is greater than or equal to 0
		fmt.Println("Zero")
	} else {
		// Check if the sum of a and b is even or odd
		if (a+b)%2 == 0 {
			// If it's even, print 'Negative'
			fmt.Println("Negative")
		} else {
			// If it's odd, print 'Positive'
			fmt.Println("Positive")
		}
	}
}

// <END-OF-CODE>
