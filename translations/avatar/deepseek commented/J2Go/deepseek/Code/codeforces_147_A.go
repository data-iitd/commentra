package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

// Function to check if a character is a Latin letter
func isLatinLetter(c byte) bool {
	return c >= 'a' && c <= 'z'
}

// Function to check if a character is a punctuation mark
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
	// Create a new reader to read input from the console
	reader := bufio.NewReader(os.Stdin)
	// Read the input string
	input, _ := reader.ReadString('\n')
	// Remove the newline character from the input string
	input = strings.TrimSuffix(input, "\n")
	// Create a new StringBuilder to build the output string
	var sb strings.Builder
	// Append the first character of the input string to the StringBuilder
	sb.WriteByte(input[0])
	// Loop through the input string starting from the second character
	for i := 1; i < len(input); i++ {
		c := input[i]
		// Check if the character is a Latin letter
		if isLatinLetter(c) {
			// If the previous character is not a Latin letter, add a space
			if !isLatinLetter(input[i-1]) {
				sb.WriteByte(' ')
			}
			// Append the current Latin letter to the StringBuilder
			sb.WriteByte(c)
		}
		// Check if the character is a punctuation mark
		else if isPunctuation(c) {
			// Append the punctuation mark to the StringBuilder
			sb.WriteByte(c)
		}
	}
	// Print the final string with spaces added between Latin letters
	fmt.Println(sb.String())
}

