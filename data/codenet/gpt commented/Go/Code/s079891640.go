package main

import (
	"fmt"
	"os"
	"strings"
)

var (
	s string // Declare a variable to hold the input string
)

func main() {
	// Read input from the user and store it in the variable 's'
	fmt.Scan(&s)

	// Iterate over each character in the string 's'
	for i := 0; i < len(s); i++ {
		// Check if the current character exists in the substring that follows it
		if strings.Contains(s[i+1:], string(s[i])) {
			// If the character is found in the remaining substring, print "no" and exit
			fmt.Println("no")
			os.Exit(0)
		}
	}

	// If no duplicate characters were found, print "yes"
	fmt.Println("yes")
}
