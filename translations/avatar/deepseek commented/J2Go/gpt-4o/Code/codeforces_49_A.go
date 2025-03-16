package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scanln(&s) // Read a line of input from the user and store it in a string variable s

	length := len(s) // Calculate the length of the string s
	var ch rune // Initialize a character variable ch

	// Iterate through the string s in reverse order, starting from the last character
	for i := length - 1; i >= 0; i-- {
		if s[i] != ' ' && s[i] != '?' { // Check if the current character is not a space or a question mark
			ch = rune(s[i]) // Assign the current character to the variable ch
			break // Exit the loop
		}
	}

	ch = rune(strings.ToLower(string(ch))[0]) // Convert the character ch to lowercase

	// Check if ch is one of the vowels (a, e, i, o, u, y)
	if ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y' {
		fmt.Println("YES") // Print "YES" if ch is a vowel
	} else {
		fmt.Println("NO") // Print "NO" if ch is not a vowel
	}
}

// <END-OF-CODE>
