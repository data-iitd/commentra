package main

import (
	"fmt"
	"strings"
)

func main() {
	var sum int
	var input string

	for {
		// Read a string from standard input
		fmt.Print("Enter a string of digits separated by spaces or newline: ")
		fmt.Scanln(&input)

		// Check if the first character is '0' to exit the loop
		if strings.HasPrefix(input, "0") {
			break
		}

		// Initialize sum to zero before processing each string
		sum = 0

		// Process each character in the string
		for _, char := range input {
			// Convert character to integer by subtracting '0'
			sum += int(char - '0')
		}

		// Print the sum of digits in the current string
		fmt.Printf("Sum of digits in previous string: %d\n", sum)
	}
}
