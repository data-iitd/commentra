package main

import (
	"fmt"
)

func main() {
	// Create a variable to read input from the user
	var a, b int

	// Read two integers from the input
	fmt.Scan(&a, &b)

	// Initialize sum to 0, this will store the sum of the two numbers
	sum := 0

	// Loop runs twice, each time adding the larger of the two numbers to sum
	// and decrementing that number by 1
	for i := 0; i < 2; i++ {
		if a >= b {
			sum += a
			a--
		} else {
			sum += b
			b--
		}
	}

	// Print the final sum to the console
	fmt.Println(sum)
}

// <END-OF-CODE>
