package main

import (
	"bufio" // Buffered reader for reading input
	"fmt"   // Package for formatted I/O
	"os"    // Package for OS functions
	"strings" // Package for string manipulation
)

// Function to check if a given string represents a valid solution
func isSolution(columnsCount int, x string) bool {
	allXs := make([]bool, columnsCount) // Initialize a slice to keep track of the presence of 'X' in each column
	for i := range allXs {
		allXs[i] = true // Set all columns to have 'X' initially
	}

	// Iterate through the given string and mark the corresponding columns as not having 'X'
	for i := 0; i < 12; i++ {
		if x[i] != 'X' {
			allXs[i%columnsCount] = false // Update the corresponding column
		}
	}

	// Check if there is any column having 'X'
	for i := 0; i < columnsCount; i++ {
		if allXs[i] { // If 'X' is present in this column
			return true // Return true as this is a valid solution
		}
	}

	return false // If no column has 'X', then this is not a valid solution
}

func main() {
	reader := bufio.NewReader(os.Stdin) // Read input from console
	var t int
	fmt.Fscanln(reader, &t) // Read the number of test cases

	for i := 0; i < t; i++ { // Iterate through each test case
		possibleSolutions := 0 // Initialize the counter for the number of valid solutions
		solutions := strings.Builder{} // Initialize a string builder to store the valid solutions

		var s string
		fmt.Fscanln(reader, &s) // Read the given string

		// Check if the given string represents a valid solution
		if isSolution(12, s) {
			solutions.WriteString(" 1x12") // Add the solution to the string builder
			possibleSolutions++ // Increment the counter
		}

		if isSolution(6, s) {
			solutions.WriteString(" 2x6")
			possibleSolutions++
		}

		if isSolution(4, s) {
			solutions.WriteString(" 3x4")
			possibleSolutions++
		}

		if isSolution(3, s) {
			solutions.WriteString(" 4x3")
			possibleSolutions++
		}

		if isSolution(2, s) {
			solutions.WriteString(" 6x2")
			possibleSolutions++
		}

		if isSolution(1, s) {
			solutions.WriteString(" 12x1")
			possibleSolutions++
		}

		// Write the output
		fmt.Print(possibleSolutions) // Write the number of valid solutions
		fmt.Println(solutions.String()) // Write the valid solutions
	}
}

// <END-OF-CODE>
