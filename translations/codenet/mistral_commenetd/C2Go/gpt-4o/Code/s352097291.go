package main

import (
	"fmt"
	"strings"
)

func main() {
	// Declare variables
	var c string // A string to store the input
	ans := ""    // A string to store the output

	// Read a string from the standard input
	fmt.Scan(&c)

	// Process the string
	for _, char := range c { // Iterate through each character in the string 'c'
		if char != 'B' { // If the current character is not 'B'
			ans += string(char) // Append the character to the output string 'ans'
		} else { // If the current character is 'B'
			if len(ans) > 0 { // Check if 'ans' is not empty
				ans = ans[:len(ans)-1] // Remove the last character from the output string 'ans'
			}
		}
	}

	// Print the output
	fmt.Println(ans) // Print the final output string
}

// The comments explain the purpose of each logical block and make the code more readable.
