package main

import (
	"fmt"
)

func main() {
	var a, b int
	fmt.Scan(&a, &b) // Read two integers from standard input

	sum := 0 // Initialize sum variable to 0

	for i := 0; i < 2; i++ { // Iterate through two iterations
		if a >= b { // Check if a is greater than or equal to b
			sum += a // Add a to sum
			a--      // Decrement a by 1
		} else {
			sum += b // Add b to sum
			b--      // Decrement b by 1
		}
	}

	fmt.Println(sum) // Print the value of sum to standard output
}

// <END-OF-CODE>
