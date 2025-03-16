package main

import (
	"fmt"
)

func main() {
	// Variable declarations
	var a, b, n int // Input values and loop counters
	var sum int      // To store the sum of the digits
	var i, j int     // Loop counters

	// Infinite loop
	for {
		// Read three integers from standard input
		_, err := fmt.Scan(&a, &b, &n)
		if err != nil {
			break // Break if input reading fails
		}

		// Reduce 'a' to its remainder when divided by 'b'
		a -= a / b * b

		// Initialize sum to zero
		sum = 0

		// Outer loop runs 'n' times
		for i := 1; i <= n; i++ {
			// Multiply 'a' by 10 to shift the decimal point
			a *= 10

			// Inner loop iterates from 9 down to 0
			for j = 9; j >= 0; j-- {
				// Find the largest digit 'j' such that 'b*j' is less than or equal to 'a'
				if b*j <= a {
					break
				}
			}

			// Subtract 'b*j' from 'a' and add 'j' to the sum
			a -= b * j
			sum += j
		}

		// Output the sum of the digits
		fmt.Println(sum)
	}
}

