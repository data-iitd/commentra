package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Declare variables for input values and calculations
	var a, b, n int
	var sum int
	var i, j int

	// Infinite loop to continuously accept input until an error occurs
	for {
		// Read three integers a, b, and n from standard input
		// Break the loop if input fails (scanf returns -1)
		_, err := fmt.Scanf("%d %d %d", &a, &b, &n)
		if err != nil {
			if err == os.EOF {
				break
			}
			fmt.Println(err)
			os.Exit(1)
		}

		// Adjust 'a' to be the remainder when divided by 'b'
		a -= a / b * b
		// Initialize sum to accumulate the result
		sum = 0

		// Loop 'n' times to process each digit
		for i = 1; i <= n; i++ {
			// Scale 'a' by 10 to shift left for the next digit
			a *= 10

			// Find the largest digit 'j' (0-9) such that b*j <= a
			for j = 9; j >= 0; j-- {
				if b*j <= a {
					break
				}
			}

			// Subtract the value of b*j from 'a'
			a -= b * j
			// Add the digit 'j' to the sum
			sum += j
		}

		// Output the final sum for the current input set
		fmt.Println(sum)
	}

	// Return 0 to indicate successful completion of the program
	os.Exit(0)
}

