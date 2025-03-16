package main

import (
	"fmt"
)

func main() {
	// Declare a character array to store the input string
	var S string

	// Read a string input from the user and store it in S
	fmt.Scan(&S)

	// Loop through each character in the string S
	for i := 0; i < len(S)-1; i++ {
		// Check if the current character is 'A' and the next character is 'C'
		if S[i] == 'A' && S[i+1] == 'C' {
			// If the condition is met, print "Yes" and exit the program
			fmt.Println("Yes")
			return
		}
	}

	// If the condition is not met after the loop completes, print "No" and exit the program
	fmt.Println("No")
}

// <END-OF-CODE>
