package main

import (
	"fmt"
	"strings"
)

func main() {
	// Optimize input/output operations
	fmt.Println("Enter a string:")
	var z string
	fmt.Scanln(&z)

	// Get the size of the input string
	a := len(z)

	// Check for consecutive identical characters in the string
	for i := 0; i < a-1; i++ {
		// If two consecutive characters are the same, print "Bad" and exit
		if z[i] == z[i+1] {
			fmt.Println("Bad")
			return
		}
	}

	// If no consecutive identical characters were found, print "Good"
	fmt.Println("Good")
}

