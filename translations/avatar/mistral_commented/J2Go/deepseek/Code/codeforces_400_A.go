package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

// Method to check if a given string represents a valid solution
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
	writer := bufio.NewWriter(os.Stdout) // Write output to console
	defer writer.Flush() // Flush the writer buffer

	t, _ := reader.ReadString('\n') // Read the number of test cases
	t = strings.TrimSpace(t)
	tInt := 0
	fmt.Sscanf(t, "%d", &tInt)

	for i := 0; i < tInt; i++ { // Iterate through each test case
		possibleSolutions := 0 // Initialize the counter for the number of valid solutions
		var solutions []string // Initialize a slice to store the valid solutions

		s, _ := reader.ReadString('\n') // Read the given string
		s = strings.TrimSpace(s)

		// Check if the given string represents a valid solution
		if isSolution(12, s) {
			solutions = append(solutions, " 1x12") // Add the solution to the slice
			possibleSolutions++ // Increment the counter
		}

		if isSolution(6, s) {
			solutions = append(solutions, " 2x6")
			possibleSolutions++
		}

		if isSolution(4, s) {
			solutions = append(solutions, " 3x4")
			possibleSolutions++
		}

		if isSolution(3, s) {
			solutions = append(solutions, " 4x3")
			possibleSolutions++
		}

		if isSolution(2, s) {
			solutions = append(solutions, " 6x2")
			possibleSolutions++
		}

		if isSolution(1, s) {
			solutions = append(solutions, " 12x1")
			possibleSolutions++
		}

		// Write the output
		fmt.Fprint(writer, possibleSolutions, " ") // Write the number of valid solutions
		fmt.Fprintln(writer, strings.Join(solutions, "")) // Write the valid solutions
	}
}
