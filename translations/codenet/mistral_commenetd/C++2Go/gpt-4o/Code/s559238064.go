package main

import (
	"fmt"
)

func main() {
	var z string
	// Read input string from standard input
	fmt.Scan(&z)

	// Assign size of the string to variable 'a'
	a := len(z)

	// Check if there are any consecutive identical characters in the string
	for i := 0; i < a-1; i++ {
		// Check if current character is same as next character
		if z[i] == z[i+1] {
			// If yes, print "Bad" and exit the program
			fmt.Println("Bad")
			return
		}
	}
	// If no consecutive identical characters are found, print "Good"
	fmt.Println("Good")
}

// <END-OF-CODE>
