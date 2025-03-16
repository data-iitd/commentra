package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

// Method to check if a given string can form a solution for a specific column count
func isSolution(columnsCount int, x string) bool {
	// Create a slice to track if all positions for each column are 'X'
	allXs := make([]bool, columnsCount)
	for i := 0; i < columnsCount; i++ {
		allXs[i] = true
	} // Initialize all positions as true (all 'X's)

	// Check each character in the string
	for i := 0; i < 12; i++ {
		// If the character is not 'X', mark the corresponding column as false
		if x[i] != 'X' {
			allXs[i%columnsCount] = false
		}
	}

	// Check if any column has all 'X's
	for i := 0; i < columnsCount; i++ {
		if allXs[i] {
			return true // Return true if a valid solution is found
		}
	}

	return false // Return false if no valid solution is found
}

func main() {
	// Initialize bufio.Scanner to read input from the console
	scanner := bufio.NewScanner(os.Stdin)
	// Initialize PrintWriter to output results to the console
	writer := bufio.NewWriter(os.Stdout)

	// Read the number of test cases
	scanner.Scan()
	t := 0
	fmt.Sscanf(scanner.Text(), "%d", &t)

	// Process each test case
	for i := 0; i < t; i++ {
		possibleSolutions := 0 // Counter for possible solutions
		var solutions strings.Builder // To store the solutions
		scanner.Scan()
		s := scanner.Text() // Read the input string

		// Check for various column configurations and append valid solutions
		if isSolution(12, s) {
			solutions.WriteString(" 1x12")
			possibleSolutions++
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

		// Output the number of possible solutions and the solutions themselves
		writer.WriteString(fmt.Sprintf("%d%s\n", possibleSolutions, solutions.String()))
	}

	// Flush and close the writer
	writer.Flush()
}
