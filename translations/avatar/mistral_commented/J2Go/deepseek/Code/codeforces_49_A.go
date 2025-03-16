package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string

	// Read the next line from the console and store it in the string 's'
	fmt.Scanln(&s)

	// Get the length of the string 's'
	length := len(s)

	// Initialize a character variable 'ch' to store the first non-space and non-question mark character found in the string 's'
	var ch byte

	// Iterate through the string 's' from the end to the beginning
	for i := length - 1; i >= 0; i-- {
		// Check if the current character is not a space or a question mark
		if s[i] != ' ' && s[i] != '?' {
			// If yes, store the character in 'ch' and break out of the loop
			ch = s[i]
			break
		}
	}

	// Convert the character 'ch' to lowercase
	ch = strings.ToLower(string(ch))[0]

	// Check if the character 'ch' is a vowel or a y
	if ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y' {
		// If yes, print "YES" to the console
		fmt.Println("YES")
	} else {
		// If no, print "NO" to the console
		fmt.Println("NO")
	}
}

