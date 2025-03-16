package main

import (
	"fmt"
)

func main() {
	var n int

	// Read an integer n from the standard input
	fmt.Scan(&n)

	// Iterate from 1 to n (inclusive)
	for i := 1; i <= n; i++ {
		a := i

		// Check if the current number i is divisible by 3
		if a%3 == 0 {
			fmt.Printf(" %d", i)
		} else {
			// Check each digit of i to see if it contains the digit 3
			for a > 0 {
				if a%10 == 3 {
					fmt.Printf(" %d", i)
					break
				}
				a = a / 10
			}
		}
	}

	// Print a newline character
	fmt.Println()
}

// <END-OF-CODE>
