package main

import (
	"fmt"
)

func main() {
	// Declare variables for sum
	var sum int
	var x string

	// Read the first input string
	fmt.Scan(&x)

	// Loop to process input until the termination condition is met
	for x[0] != '0' {
		// Reset sum for the current input
		sum = 0

		// Iterate through the characters of the input string
		for i := 0; i < len(x); i++ {
			// Convert character to integer and add to sum
			sum += int(x[i] - '0') // '0' is represented by '0' in Go
		}

		// Print the sum of the digits in the string
		fmt.Println(sum)

		// Read the next input string
		fmt.Scan(&x)
	}
}
