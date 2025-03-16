package main

import (
	"fmt"
	"strings"
)

func main() {
	// Declare a string to hold the input
	var s string

	// Read a string from standard input
	fmt.Scan(&s)

	// Initialize a flag to track validity
	flag := 0

	// Iterate through each character in the string
	for i, char := range s {
		// Check if the index is even
		if i%2 == 0 {
			// Switch case for characters at even indices
			switch char {
			case 'R', 'U', 'D':
				// 'R', 'U', 'D' are valid, do nothing
			default:
				// If character is not valid, set flag to indicate an error
				flag = 1
			}
		} else {
			// Switch case for characters at odd indices
			switch char {
			case 'L', 'U', 'D':
				// 'L', 'U', 'D' are valid, do nothing
			default:
				// If character is not valid, set flag to indicate an error
				flag = 1
			}
		}
	}

	// Check the flag to determine if the input string was valid
	if flag == 0 {
		// If flag is still 0, print "Yes" indicating valid input
		fmt.Println("Yes")
	} else {
		// If flag is set, print "No" indicating invalid input
		fmt.Println("No")
	}
}

// <END-OF-CODE>
