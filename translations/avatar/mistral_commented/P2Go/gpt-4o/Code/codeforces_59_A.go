package main

import (
	"fmt"
	"strings"
)

func main() {
	// Get the text input from the user
	var txt string
	fmt.Scanln(&txt)

	// Initialize the count of uppercase and lowercase characters
	cu := 0
	cl := 0

	// Iterate through each character in the text input
	for _, z := range txt {
		// If the character is lowercase, increment the lowercase count
		if z >= 'a' && z <= 'z' {
			cl++
		} else if z >= 'A' && z <= 'Z' {
			// If the character is uppercase, increment the uppercase count
			cu++
		}
	}

	// Determine the output based on the count of uppercase and lowercase characters
	var out string
	if cu > cl {
		// If there are more uppercase characters than lowercase characters, convert the entire text to uppercase
		out = strings.ToUpper(txt)
	} else {
		// If there are more lowercase characters than uppercase characters, convert the entire text to lowercase
		out = strings.ToLower(txt)
	}

	// Print the output
	fmt.Println(out)
}

// <END-OF-CODE>
