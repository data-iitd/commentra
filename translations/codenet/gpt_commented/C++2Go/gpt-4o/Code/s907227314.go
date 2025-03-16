package main

import (
	"fmt"
)

func main() {
	// Declare a string variable to hold the input
	var s string
	
	// Read input string from the user
	fmt.Scan(&s)
	
	// Declare variables to store the positions of 'A' and 'Z'
	var a, z int
	foundA, foundZ := false, false
	
	// Loop through the string to find the first occurrence of 'A'
	for i := 0; i < len(s); i++ {
		if s[i] == 'A' {
			a = i // Store the index of 'A'
			foundA = true
			break // Exit the loop once 'A' is found
		}
	}
	
	// Loop through the string in reverse to find the last occurrence of 'Z'
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == 'Z' {
			z = i // Store the index of 'Z'
			foundZ = true
			break // Exit the loop once 'Z' is found
		}
	}
	
	// Check if both 'A' and 'Z' were found
	if foundA && foundZ {
		// Calculate the number of characters between 'A' and 'Z' (inclusive) and print the result
		fmt.Println(z - a + 1)
	} else {
		// If 'A' or 'Z' is not found, print 0
		fmt.Println(0)
	}
}

// <END-OF-CODE>
