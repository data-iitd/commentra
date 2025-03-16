package main

import (
	"fmt"
)

func main() {
	// Declare a variable for the input string
	var z string
	
	// Read the input string
	fmt.Scan(&z)
	
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

// <END-OF-CODE>
