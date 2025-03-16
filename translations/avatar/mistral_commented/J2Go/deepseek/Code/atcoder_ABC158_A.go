package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Initialize input and output streams
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read the input string
	input, _ := reader.ReadString('\n')
	input = input[:len(input)-1] // Remove the newline character

	// Check if the string contains both 'A' and 'B'
	if containsA(input) && containsB(input) {
		fmt.Fprintln(writer, "Yes")
	} else {
		fmt.Fprintln(writer, "No")
	}
}

// Function to check if the string contains 'A'
func containsA(s string) bool {
	for _, char := range s {
		if char == 'A' {
			return true
		}
	}
	return false
}

// Function to check if the string contains 'B'
func containsB(s string) bool {
	for _, char := range s {
		if char == 'B' {
			return true
		}
	}
	return false
}

