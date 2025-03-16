// Importing necessary Go libraries for reading input and writing output
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

// Function to check if a character is a Latin letter
func isLatinLetter(c rune) bool {
	// Check if the character falls within the Unicode range of Latin letters
	return c >= 'a' && c <= 'z'
}

// Function to check if a character is a punctuation mark
func isPunctuation(c rune) bool {
	// Check if the character is a dot, comma, exclamation mark, or question mark
	return c == '.' || c == ',' || c == '!' || c == '?'
}

func main() {
	// Creating a buffered reader to read input from the console
	reader := bufio.NewReader(os.Stdin)

	// Reading a line of input from the console
	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s) // Trim any trailing newline characters

	// Creating a strings.Builder to store the output
	var sb strings.Builder

	// Finding the length of the input string
	n := len(s)

	// Appending the first character of the input string to the strings.Builder
	if n > 0 {
		sb.WriteRune(rune(s[0]))
	}

	// Iterating through the rest of the characters in the input string
	for i := 1; i < n; i++ {
		c := rune(s[i]) // Getting the current character from the input string

		// If the current character is a Latin letter, append it to the strings.Builder with a space before it if the previous character was not a Latin letter
		if isLatinLetter(c) {
			if !isLatinLetter(rune(s[i-1])) {
				sb.WriteRune(' ')
			}
			sb.WriteRune(c)
		} else if isPunctuation(c) { // If the current character is a punctuation mark, append it directly to the strings.Builder without a space
			sb.WriteRune(c)
		}
	}

	// Writing the output to the console
	fmt.Println(sb.String())
}

// <END-OF-CODE>
