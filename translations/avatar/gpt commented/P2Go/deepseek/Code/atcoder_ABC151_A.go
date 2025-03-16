package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

// Flag to enable or disable debugging
var debug bool

// Function to log debug messages
func log(text string) {
	if debug {
		fmt.Println(text)
	}
}

// Function to parse input from the user or from a string
func parseInput(linesAsString string) (string, []string) {
	var lines []string

	// Check if input is provided as a string
	if linesAsString == "" {
		debug = false  // Disable debug mode for standard input
		reader := bufio.NewReader(os.Stdin)
		line, _ := reader.ReadString('\n')
		lines = append(lines, line)
	} else {
		debug = true  // Enable debug mode for string input
		// Split the input string into lines and ignore the first and last lines
		lines = strings.Split(linesAsString, "\n")[1:len(strings.Split(linesAsString, "\n"))-1]
	}

	// Extract the first element from the first line as the character to process
	parts := strings.Split(lines[0], " ")
	char := parts[0]
	return char, lines
}

// Function to solve the problem by finding the next character in the alphabet
func solve(c string) string {
	alphabet := "abcdefghijklmnopqrstuvwxyz"  // String containing all lowercase letters
	index := strings.Index(alphabet, c)  // Find the index of the given character
	return string(alphabet[index + 1])  // Return the next character in the alphabet
}

// Main function to execute the program logic
func main() {
	// Parse input and solve the problem
	char, _ := parseInput("")
	result := solve(char)
	
	// Print the single result
	fmt.Println(result)
}
