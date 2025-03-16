
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func isLatinLetter(c byte) bool {
	return c >= 'a' && c <= 'z'
}

func isPunctuation(c byte) bool {
	if c == '.' {
		return true
	}
	if c == ',' {
		return true
	}
	if c == '!' {
		return true
	}
	if c == '?' {
		return true
	}
	return false
}

func main() {
	// Create a new buffered reader.
	reader := bufio.NewReader(os.Stdin)
	// Read the input string.
	input, _ := reader.ReadString('\n')
	// Remove the newline character.
	input = strings.TrimSuffix(input, "\n")
	// Create a new string builder.
	builder := strings.Builder{}
	// Append the first character of the input string.
	builder.WriteByte(input[0])
	// Loop through the input string starting from the second character.
	for i := 1; i < len(input); i++ {
		// Get the current character.
		c := input[i]
		// Check if the character is a Latin letter.
		if isLatinLetter(c) {
			// Check if the previous character is not a Latin letter.
			if!isLatinLetter(input[i-1]) {
				// Add a space.
				builder.WriteByte(' ')
			}
			// Append the current Latin letter.
			builder.WriteByte(c)
		}
		// Check if the character is a punctuation mark.
		if isPunctuation(c) {
			// Append the punctuation mark.
			builder.WriteByte(c)
		}
	}
	// Print the final string with spaces added between Latin letters.
	fmt.Println(builder.String())
}

