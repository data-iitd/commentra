package main

import (
	"fmt"
)

func main() {
	var a, b, n, sum int
	var i, j int

	for {
		// Read input values a, b, and n from the user
		_, err := fmt.Scan(&a, &b, &n)
		if err != nil {
			// Break the loop if the input is invalid
			break
		}

		// Calculate a = a - a/b * b
		a -= a / b * b

		// Initialize sum to zero
		sum = 0

		// Perform the main calculation for n times
		for i = 1; i <= n; i++ {
			// Multiply a by 10
			a *= 10

			// Find the largest multiple of b less than or equal to a
			for j = 9; j >= 0; j-- {
				// Check if b*j is less than or equal to a
				if b*j <= a {
					// Subtract the multiple of b from a
					a -= b * j

					// Add the digit j to the sum
					sum += j

					// Break the inner loop since we have found the largest multiple
					break
				}
			}
		}

		// Print the result
		fmt.Println(sum)
	}
}

