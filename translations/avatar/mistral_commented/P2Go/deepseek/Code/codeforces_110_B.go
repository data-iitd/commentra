package main

import (
	"fmt"
)

func main() {
	// Define a constant string "abcd"
	const LUCKY = "abcd"

	// Ask the user to input an integer n
	var n int
	fmt.Scan(&n)

	// Initialize an empty string s
	s := ""

	// Use a for loop to iterate through the range of integers from 0 to n-1
	for i := 0; i < n; i++ {
		// Add the character at index i % 4 of the string LUCKY to the string s
		s += string(LUCKY[i % 4])
	}

	// Print the final string s
	fmt.Println(s)
}

