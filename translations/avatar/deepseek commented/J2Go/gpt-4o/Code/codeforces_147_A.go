package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

// Function to check if a character is a Latin letter
func isLatinLetter(c rune) bool {
	return c >= 'a' && c <= 'z'
}

// Function to check if a character is a punctuation mark
func isPunctuation(c rune) bool {
	return c == '.' || c == ',' || c == '!' || c == '?'
}

func main() {
	// Create a buffered reader to read input from the console
	reader := bufio.NewReader(os.Stdin)
	// Read the input string
	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s) // Trim any trailing newline characters

	// Create a strings.Builder to build the output string
	var sb strings.Builder
	n := len(s)

	// Append the first character of the input string to the strings.Builder
	if n > 0 {
		sb.WriteRune(rune(s[0]))
	}

	// Loop through the input string starting from the second character
	for i := 1; i < n; i++ {
		c := rune(s[i])
		// Check if the character is a Latin letter
		if isLatinLetter(c) {
			// If the previous character is not a Latin letter, add a space
			if !isLatinLetter(rune(s[i-1])) {
				sb.WriteRune(' ')
			}
			// Append the current Latin letter to the strings.Builder
			sb.WriteRune(c)
		} else if isPunctuation(c) { // Check if the character is a punctuation mark
			// Append the punctuation mark to the strings.Builder
			sb.WriteRune(c)
		}
	}

	// Print the final string with spaces added between Latin letters
	fmt.Println(sb.String())
}

// <END-OF-CODE>
