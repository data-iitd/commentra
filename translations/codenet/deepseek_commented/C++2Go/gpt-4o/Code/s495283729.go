package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	// Read a string from the user input
	fmt.Scan(&s)
	flag := 0
	// Initialize a flag to check for invalid characters
	for i := 0; i < len(s); i++ {
		// Loop through each character in the string
		if i%2 == 0 {
			// Check if the index is even
			switch s[i] {
			// Check if the character is 'R', 'U', or 'D'
			case 'R', 'U', 'D':
				// valid characters for even index
			default:
				flag = 1
			}
		} else {
			// Check if the index is odd
			switch s[i] {
			// Check if the character is 'L', 'U', or 'D'
			case 'L', 'U', 'D':
				// valid characters for odd index
			default:
				flag = 1
			}
		}
	}
	if flag == 0 {
		// If no invalid characters were found, print "Yes"
		fmt.Println("Yes")
	} else {
		// If invalid characters were found, print "No"
		fmt.Println("No")
	}
}

// <END-OF-CODE>
