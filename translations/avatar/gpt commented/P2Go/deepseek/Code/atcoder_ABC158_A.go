package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	input = input[:len(input)-1] // Remove the newline character

	// Check if both 'A' and 'B' are present in the input string
	// If both are found, set result to "Yes", otherwise set it to "No"
	result := "No"
	if contains(input, 'A') && contains(input, 'B') {
		result = "Yes"
	}

	// Print the result indicating whether both 'A' and 'B' were found
	fmt.Println(result)
}

// Helper function to check if a character is present in a string
func contains(s string, r rune) bool {
	for _, char := range s {
		if char == r {
			return true
		}
	}
	return false
}

