package main

import (
	"fmt"
)

func main() {
	// Define a constant string containing the characters 'a', 'b', 'c', and 'd'
	LUCKY := "abcd"

	// Read an integer input from the user, which determines the length of the output string
	var n int
	fmt.Scan(&n)

	// Initialize an empty string to store the result
	var s string

	// Loop through a range of 'n' to build the output string
	for i := 0; i < n; i++ {
		// Append the character from LUCKY based on the current index modulo 4
		// This ensures that the characters 'a', 'b', 'c', 'd' are repeated in the output
		s += LUCKY[i%4]
	}

	// Print the final constructed string
	fmt.Println(s)
}

