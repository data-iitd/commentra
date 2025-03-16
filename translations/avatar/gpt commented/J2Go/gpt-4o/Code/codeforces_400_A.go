package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func isSolution(columnsCount int, x string) bool {
	allXs := make([]bool, columnsCount)
	for i := range allXs {
		allXs[i] = true // Initialize all positions as true (all 'X's)
	}

	// Check each character in the string
	for i := 0; i < 12; i++ {
		if x[i] != 'X' {
			allXs[i%columnsCount] = false // Mark the corresponding column as false
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
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	// Read the number of test cases
	var t int
	fmt.Fscan(reader, &t)

	// Process each test case
	for i := 0; i < t; i++ {
		var possibleSolutions int // Counter for possible solutions
		solutions := strings.Builder{} // To store the solutions
		var s string
		fmt.Fscan(reader, &s) // Read the input string

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
		fmt.Fprintf(writer, "%d%s\n", possibleSolutions, solutions.String())
	}

	writer.Flush()
}

// <END-OF-CODE>
