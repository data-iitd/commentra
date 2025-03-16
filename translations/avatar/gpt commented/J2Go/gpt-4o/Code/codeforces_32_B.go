package main

import (
	"fmt"
)

func main() {
	// Reading a string input from the console
	var input string
	fmt.Scan(&input)

	// Converting the string to a slice of runes (characters)
	n := []rune(input)

	// Initializing a boolean variable to track the state of the previous character
	s := false

	// Iterating through each character in the slice of runes
	for i := 0; i < len(n); i++ {
		// Checking if the current character is a dot '.'
		if n[i] == '.' {
			// If the previous character was also a dot, print 1 and reset the state
			if s {
				fmt.Print(1)
				s = false // Resetting the state
			} else {
				// If the previous character was not a dot, print 0
				fmt.Print(0)
			}
		} else {
			// If the current character is not a dot
			if s {
				// If the previous character was also not a dot, print 2 and reset the state
				fmt.Print(2)
				s = false // Resetting the state
			} else {
				// If the previous character was a dot, set the state to true
				s = true
			}
		}
	}
}

// <END-OF-CODE>
