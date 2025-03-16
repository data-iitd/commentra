
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
	// Create a bufio.Scanner to read input from the console
	scanner := bufio.NewScanner(os.Stdin)
	// Create a bufio.Writer to output results to the console
	writer := bufio.NewWriter(os.Stdout)

	// Read a line of input from the user
	scanner.Scan()
	s := scanner.Text()
	// Initialize a strings.Builder to construct the output string
	var sb strings.Builder
	n := len(s) // Get the length of the input string

	// Append the first character of the input string to the strings.Builder
	sb.WriteByte(s[0])

	// Loop through the input string starting from the second character
	for i := 1; i < n; i++ {
		c := s[i] // Get the current character

		// Check if the current character is a Latin letter
		if isLatinLetter(c) {
			// If the previous character is not a Latin letter, append a space
			if !isLatinLetter(s[i-1]) {
				sb.WriteByte(' ')
			}
			// Append the current Latin letter to the strings.Builder
			sb.WriteByte(c)
		}
		// Check if the current character is a punctuation mark
		if isPunctuation(c) {
			sb.WriteByte(c) // Append the punctuation mark to the strings.Builder
		}
	}

	// Print the constructed output string
	fmt.Fprintln(writer, sb.String())
	writer.Flush() // Ensure all output is written to the console
	writer.Close() // Close the bufio.Writer
}

