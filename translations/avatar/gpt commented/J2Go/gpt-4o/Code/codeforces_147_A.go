package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

// Function to check if a character is a lowercase Latin letter
func isLatinLetter(c rune) bool {
	return c >= 'a' && c <= 'z' // Returns true if c is between 'a' and 'z'
}

// Function to check if a character is a punctuation mark
func isPunctuation(c rune) bool {
	// Check for specific punctuation characters
	return c == '.' || c == ',' || c == '!' || c == '?'
}

func main() {
	// Create a BufferedReader to read input from the console
	reader := bufio.NewReader(os.Stdin)
	// Read a line of input from the user
	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s) // Trim any trailing newline characters

	// Initialize a strings.Builder to construct the output string
	var sb strings.Builder
	n := len(s) // Get the length of the input string

	// Append the first character of the input string to the strings.Builder
	if n > 0 {
		sb.WriteRune(rune(s[0]))
	}

	// Loop through the input string starting from the second character
	for i := 1; i < n; i++ {
		c := rune(s[i]) // Get the current character

		// Check if the current character is a Latin letter
		if isLatinLetter(c) {
			// If the previous character is not a Latin letter, append a space
			if !isLatinLetter(rune(s[i-1])) {
				sb.WriteRune(' ')
			}
			// Append the current Latin letter to the strings.Builder
			sb.WriteRune(c)
		} else if isPunctuation(c) { // Check if the current character is a punctuation mark
			sb.WriteRune(c) // Append the punctuation mark to the strings.Builder
		}
	}

	// Print the constructed output string
	fmt.Println(sb.String()) // Output the result
}

// <END-OF-CODE>
