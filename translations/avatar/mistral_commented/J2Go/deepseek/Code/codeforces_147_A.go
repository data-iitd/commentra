package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

// Function to check if a character is a Latin letter
func isLatinLetter(c byte) bool {
	// Check if the character falls within the ASCII range of Latin letters
	return c >= 'a' && c <= 'z'
}

// Function to check if a character is a punctuation mark
func isPunctuation(c byte) bool {
	// Check if the character is a dot, comma, exclamation mark, or question mark
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
	// If none of the above conditions are met, return false
	return false
}

func main() {
	// Creating a new reader to read input from the console
	reader := bufio.NewReader(os.Stdin)

	// Reading a line of input from the console
	input, _ := reader.ReadString('\n')

	// Removing the newline character from the input
	input = strings.TrimSuffix(input, "\n")

	// Creating a new StringBuilder to store the output
	var sb strings.Builder

	// Finding the length of the input string
	n := len(input)

	// Appending the first character of the input string to the StringBuilder
	sb.WriteByte(input[0])

	// Iterating through the rest of the characters in the input string
	for i := 1; i < n; i++ {
		// Getting the current character from the input string
		c := input[i]

		// If the current character is a Latin letter, append it to the StringBuilder with a space before it if the previous character was not a Latin letter
		if isLatinLetter(c) {
			if !isLatinLetter(input[i-1]) {
				sb.WriteByte(' ')
			}
			sb.WriteByte(c)
		}
		// If the current character is a punctuation mark, append it directly to the StringBuilder without a space
		else if isPunctuation(c) {
			sb.WriteByte(c)
		}
	}

	// Writing the output to the console
	fmt.Println(sb.String())
}

