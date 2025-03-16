package main

import (
	"fmt"
)

func main() {
	// Read input from the user
	var s string
	fmt.Scanln(&s)

	// Initialize an empty string to store the resulting characters
	myStr := ""

	// Iterate through each character in the input string
	for _, c := range s {
		// Check if the character is '0' or '1'
		if c == '0' || c == '1' {
			// If it is, append it to the result string
			myStr += string(c)
		} else if c == 'B' && len(myStr) != 0 {
			// Check if the character is 'B' and the result string is not empty
			// If it is, remove the last character from the result string
			myStr = myStr[:len(myStr)-1]
		}
	}

	// Print the final result string
	fmt.Println(myStr)
}

// <END-OF-CODE>
