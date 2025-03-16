package main

import (
	"fmt"
	"strings"
)

func main() {
	// Create a variable to read input from the console
	var s string
	fmt.Scanln(&s)

	// Get the length of the input string
	length := len(s)

	// Initialize a variable to store the last non-space, non-question mark character
	var ch rune

	// Loop through the string in reverse to find the last relevant character
	for i := length - 1; i >= 0; i-- {
		if s[i] != ' ' && s[i] != '?' {
			ch = rune(s[i]) // Store the character
			break           // Exit the loop once the character is found
		}
	}

	// Convert the character to lowercase for uniform comparison
	ch = rune(strings.ToLower(string(ch))[0])

	// Check if the character is a vowel or 'y'
	if ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y' {
		fmt.Println("YES") // Print "YES" if it is a vowel
	} else {
		fmt.Println("NO") // Print "NO" if it is not a vowel
	}
}

// <END-OF-CODE>
