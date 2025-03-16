
package main

import (
	"fmt"
)

func main() {
	// Declare variables
	var a, b, n, sum int
	var i, j int

	// Initialize variables
	for {
		// Read input values a, b, and n from the user
		if _, err := fmt.Scanf("%d %d %d", &a, &b, &n); err != nil {
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

	// Return 0 to indicate successful execution
	return 0
}

