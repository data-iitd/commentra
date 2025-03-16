package main

import (
	"fmt"
)

func main() {
	var a, c, k, b int

	// Loop to read input values from the standard input
	for {
		_, err := fmt.Scan(&a)
		if err != nil {
			break
		}

		// Initialize c and k to zero
		c = 0
		k = 0

		// Check if the input value is less than 3
		if a < 3 {
			// If yes, print 0 and exit the loop
			fmt.Println("0")
			break
		}

		// Assign the value of input 'a' to variable 'b'
		b = a

		// Loop to process each digit of the input number 'a'
		for a > 0 {
			// Decrement the value of 'b' by 1
			b--

			// Increment the value of 'c' by 1
			c++

			// Check if the value of 'c' is equal to 3
			if c == 3 {
				// If yes, increment the value of 'k' by 1 and reset the value of 'c' to zero
				k++
				c = 0
			}

			// Decrement 'a' to process the next digit
			a--
		}

		// Print the value of 'k' as the output
		fmt.Println(k)
	}
}

// <END-OF-CODE>
