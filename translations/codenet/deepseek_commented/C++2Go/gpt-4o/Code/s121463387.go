package main

import (
	"fmt"
	"math"
)

func main() {
	// Declare variables to store input and intermediate results
	var n int

	// Read the value of n from standard input
	fmt.Scan(&n)

	// Loop through numbers from 1 to n
	for i := 1; i <= n; i++ {
		// Initialize x with the current number i
		x := i

		// Check if the number is divisible by 3 or ends with 3
		if x%3 == 0 || x%10 == 3 {
			fmt.Print(" ", i) // Output the number if the condition is met
			continue
		} else {
			// Check each digit of the number to see if it contains 3
			k := int(math.Log10(float64(x))) // Get the number of digits
			for k >= 0 {
				j := int(math.Pow(10, float64(k)))
				if (x/j)%10 == 3 {
					fmt.Print(" ", i) // Output the number if '3' is found in any digit
					break
				}
				k--
			}
		}
	}

	// Output a newline character at the end of the program
	fmt.Println()
}

// <END-OF-CODE>
