package main

import (
	"fmt"
	"strings"
)

// Global debug flag
var debug bool

// Function to log messages when debug mode is enabled
func log(text string) {
	if debug {
		fmt.Println(text)
	}
}

// Function to parse input lines
func parseInput(linesAsString string) (string, []string) {
	// Set the global debug flag
	debug = true

	// Initialize an empty list to store the lines
	lines := []string{}

	// Split the input string by newline and trim spaces
	lines = strings.Split(linesAsString, "\n")
	lines = lines[1 : len(lines)-1]

	// Extract the first character from the first line as the command
	command := strings.Split(lines[0], " ")[0]

	// Return the command and the lines
	return command, lines
}

// Function to solve the problem based on the command
func solve(c string) string {
	// Define the alphabet string
	alphabet := "abcdefghijklmnopqrstuvwxyz"

	// Find the index of the command character in the alphabet string
	index := strings.Index(alphabet, c)

	// Return the next character in the alphabet string
	return string(alphabet[index+1])
}

// Main function to execute the code
func main() {
	// Read input from stdin
	var input string
	fmt.Scanln(&input)

	// Call the parseInput function to get the command
	command, _ := parseInput(input)

	// Call the solve function to get the result
	result := solve(command)

	// Print the result
	fmt.Println(result)
}

