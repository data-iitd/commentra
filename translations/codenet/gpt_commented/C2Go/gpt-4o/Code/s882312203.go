package main

import (
	"fmt"
	"strings"
)

func main() {
	// Declare a string to hold the input (max length 25)
	var s string

	// Read a string from standard input
	fmt.Scan(&s)

	// Loop through each character in the string
	for j := 0; j < len(s); j++ {
		// Compare the current character with every other character in the string
		for i := 0; i < len(s); i++ {
			// Check if the characters are the same and they are not the same position
			if i != j && s[i] == s[j] {
				// If a duplicate character is found, print "no" and exit the program
				fmt.Println("no")
				return
			}
		}
	}

	// If no duplicates were found, print "yes"
	fmt.Println("yes")
}

// <END-OF-CODE>
