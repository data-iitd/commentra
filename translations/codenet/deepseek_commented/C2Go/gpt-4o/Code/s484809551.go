package main

import (
	"fmt"
	"strings"
)

// Function to find the last occurrence of a substring within a string
func strrstr(s, pattern string) string {
	lastIndex := -1
	for i := 0; i <= len(s)-len(pattern); i++ {
		if s[i:i+len(pattern)] == pattern {
			lastIndex = i
		}
	}
	if lastIndex == -1 {
		return ""
	}
	return s[lastIndex:]
}

// Function to check if the pattern can be formed from the input string
func canFormPattern(S string) string {
	patternBase := "keyence"
	found := false

	// Loop through each possible split point in the pattern
	for offset := 0; offset <= len(patternBase); offset++ {
		top := patternBase[:offset]
		bottom := patternBase[offset:]

		// Search for the top part in the input string
		topIndex := strings.Index(S, top)
		if topIndex != -1 {
			// Search for the bottom part after the found top part
			bottomIndex := strings.LastIndex(S[topIndex+offset:], bottom)
			if bottomIndex != -1 {
				bottomIndex += topIndex + offset

				sepCount := 0 // Counter for separators

				// Count the number of separators between top and bottom parts
				if topIndex > 0 {
					sepCount++ // Increment if there's text before the top part
				}
				if bottomIndex > topIndex+offset {
					sepCount++ // Increment if there's text between top and bottom parts
				}
				if bottomIndex+len(bottom) < len(S) {
					sepCount++ // Increment if there's text after the bottom part
				}

				// Check if the number of separators is less than or equal to 1
				if sepCount <= 1 {
					found = true // Set found flag to true
					break       // Exit the loop as the pattern is found
				}
			}
		}
	}

	// Output the result based on whether the pattern was found
	if found {
		return "YES"
	}
	return "NO"
}

// Main function to execute the program
func main() {
	var S string
	// Read the input string
	fmt.Scan(&S)

	// Check if the pattern can be formed and print the result
	result := canFormPattern(S)
	fmt.Println(result)
}

// <END-OF-CODE>
