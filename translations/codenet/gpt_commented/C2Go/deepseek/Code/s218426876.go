package main

import (
	"fmt"
	"strconv"
)

func main() {
	var x [1002]string
	var sum int

	// Read the first input string
	fmt.Scanln(&x[0])

	// Loop to process input until the termination condition is met
	for x[0] != "0" {
		// Iterate through the characters of the input string
		for i := 0; i < len(x[0]); i++ {
			// Convert character to integer and add to sum
			digit, _ := strconv.Atoi(string(x[0][i]))
			sum += digit
		}

		// Print the sum of the digits in the string
		fmt.Println(sum)

		// Reset sum for the next input
		sum = 0

		// Read the next input string
		fmt.Scanln(&x[0])
	}
}

