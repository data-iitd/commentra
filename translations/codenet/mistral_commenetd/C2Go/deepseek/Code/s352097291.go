package main

import (
	"fmt"
	"strings"
)

// Declare variables
var c [11]rune // An array to store the input string
var ans []rune  // An array to store the output string

func main() {
	// Initialize variables
	var input string
	fmt.Scanln(&input) // Read a string from the standard input and store it in the 'input' variable

	// Convert input string to rune array
	for i, char := range input {
		c[i] = char
	}

	// Process the string
	for i := 0; i < len(c); i++ { // Iterate through each character in the string 'c'
		if c[i] != 'B' { // If the current character is not 'B'
			ans = append(ans, c[i]) // Append the character to the output string 'ans'
		} else { // If the current character is 'B'
			if len(ans) > 0 {
				ans = ans[:len(ans)-1] // Remove the last character from the output string 'ans'
			}
		}
	}

	// Print the output
	fmt.Println(string(ans)) // Print the final output string
}
