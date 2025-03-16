package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

// Flag to enable or disable debugging
var debug = false

// Function to log debug messages
func log(text string) {
	if debug {
		fmt.Println(text)
	}
}

// Function to parse input from the user or from a string
func parseInput(linesAsString string) (string, error) {
	var lines []string

	// Check if input is provided as a string
	if linesAsString == "" {
		debug = false // Disable debug mode for standard input
		reader := bufio.NewReader(os.Stdin)
		input, _ := reader.ReadString('\n')
		lines = []string{input}
	} else {
		debug = true // Enable debug mode for string input
		// Split the input string into lines and ignore the first and last lines
		lines = strings.Split(linesAsString, "\n")[1 : len(strings.Split(linesAsString, "\n"))-1]
	}

	// Extract the first element from the first line as the character to process
	c := strings.Fields(lines[0])[0]
	return c, nil
}

// Function to solve the problem by finding the next character in the alphabet
func solve(c string) string {
	a := "abcdefghijklmnopqrstuvwxyz" // String containing all lowercase letters
	i := strings.Index(a, c)               // Find the index of the given character
	return string(a[i+1])                  // Return the next character in the alphabet
}

// Main function to execute the program logic
func main() {
	// Parse input and solve the problem
	c, err := parseInput("")
	if err != nil {
		fmt.Println("Error parsing input:", err)
		return
	}
	result := solve(c)

	// Print the single result
	fmt.Println(result)
}

// Entry point of the program
// <END-OF-CODE>
