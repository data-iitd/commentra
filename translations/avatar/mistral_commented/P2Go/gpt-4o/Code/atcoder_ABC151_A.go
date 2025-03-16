package main

import (
	"fmt"
	"os"
	"strings"
)

// Global debug flag
var debug bool

// Log function to print messages when debug mode is enabled
func log(text string) {
	if debug {
		fmt.Println(text)
	}
}

// Function to parse input lines
func parseInput(linesAsString string) (string, error) {
	// Set debug mode to true if input is provided
	if linesAsString != "" {
		debug = true
		lines := strings.Split(linesAsString, "\n")[1 : len(strings.Split(linesAsString, "\n"))-1]

		// Extract the first character from the first line as the command
		c := strings.Fields(lines[0])[0]
		return c, nil
	}
	return "", fmt.Errorf("no input provided")
}

// Function to solve the problem based on the command
func solve(c string) string {
	// Define the alphabet string
	a := "abcdefghijklmnopqrstuvwxyz"

	// Find the index of the command character in the alphabet string
	i := strings.Index(a, c)

	// Return the next character in the alphabet string
	return string(a[i+1])
}

// Main function to execute the code
func main() {
	// Example input for testing
	input := "command\nb\n" // Replace with actual input as needed

	// Call the parseInput function to get the command
	command, err := parseInput(input)
	if err != nil {
		fmt.Println(err)
		os.Exit(1)
	}

	// Solve the command and get the result
	result := solve(command)

	// Print the result
	fmt.Println(result)
}

// <END-OF-CODE>
