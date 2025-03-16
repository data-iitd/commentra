package main

import (
	"fmt"
	"strings"
)

func main() {
	var i int
	var sum int
	var flag int
	var x string

	// Read a string from standard input and store it in 'x' variable
	fmt.Print("Enter a string of digits separated by spaces or newline: ")
	fmt.Scanln(&x)

	for {
		// Initialize sum to zero before processing each string
		sum = 0

		// Process each character in the string 'x'
		for i = 0; i < len(x); i++ {
			// Add the integer value of the character to the sum
			sum += int(x[i] - '0')
		}

		// Print the sum of digits in the previous string
		fmt.Printf("Sum of digits in previous string: %d\n", sum)

		// Read next string from standard input
		fmt.Print("Enter a string of digits separated by spaces or newline: ")
		fmt.Scanln(&x)

		// Check if the first character of the input string is '0'
		if strings.HasPrefix(x, "0") {
			break
		}
	}
}

