// Import necessary packages
package main

import (
	"fmt"
	"strings"
)

// Define a function to log messages when debug mode is enabled
func log(text string) {
	// Check if debug mode is enabled
	if debug {
		// Print the log message
		fmt.Println(text)
	}
}

// Function to parse input lines
func parse_input(lines_as_string string) (string,) {
	// Set the global debug flag
	debug = true

	// Initialize an empty list to store the lines
	lines := []string{}

	// If lines_as_string is provided, set debug mode to True and parse lines
	if lines_as_string != "" {
		lines = strings.Split(lines_as_string, "\n")
	}

	// Extract the first character from the first line as the command
	c := strings.Split(lines[0], " ")[0]

	// Return the command as a tuple
	return c,
}

// Function to solve the problem based on the command
func solve(c string) string {
	// Define the alphabet string
	a := "abcdefghijklmnopqrstuvwxyz"

	// Find the index of the command character in the alphabet string
	i := strings.Index(a, c)

	// Return the next character in the alphabet string
	return a[i+1:]
}

// Main function to execute the code
func main() {
	// Call the parse_input function to get the command
	result := solve(parse_input(""))

	// Check if the result is a list or a single string
	if isinstance(result, list) {
		// If it's a list, print each element separately
		for _, r := range result {
			fmt.Println(r)
		}
	} else {
		// If it's a single string, print it directly
		fmt.Println(result)
	}
}

// Run the main function if the script is executed directly
func init() {
	main()
}

// 