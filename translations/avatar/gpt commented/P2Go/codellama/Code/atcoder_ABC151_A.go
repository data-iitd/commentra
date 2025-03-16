
package main

import (
	"fmt"
	"strings"
)

// Function to log debug messages
func log(text string) {
	fmt.Println(text)
}

// Function to parse input from the user or from a string
func parseInput(linesAsString string) (string,) {
	// Split the input string into lines and ignore the first and last lines
	lines := strings.Split(linesAsString, "\n")[1 : len(linesAsString)-1]
	
	// Extract the first element from the first line as the character to process
	c := strings.Split(lines[0], " ")[0]
	return (c,)
}

// Function to solve the problem by finding the next character in the alphabet
func solve(c string) string {
	a := "abcdefghijklmnopqrstuvwxyz"  // String containing all lowercase letters
	i := strings.Index(a, c)  // Find the index of the given character
	return a[i+1]  // Return the next character in the alphabet
}

// Main function to execute the program logic
func main() {
	// Parse input and solve the problem
	result := solve(parseInput(""))
	
	// Check if the result is a list and print each result
	if result != nil {
		for _, r := range result {
			fmt.Println(r)
		}
	} else {
		// Print the single result
		fmt.Println(result)
	}
}

// Entry point of the program
func init() {
	main()
}

