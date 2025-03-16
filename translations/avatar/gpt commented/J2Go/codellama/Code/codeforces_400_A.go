package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func isSolution(columnsCount int, x string) bool {
	// Create an array to track if all positions for each column are 'X'
	allXs := make([]bool, columnsCount)
	for i := 0; i < columnsCount; i++ {
		allXs[i] = true
	}

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
			return true
		}
	}

	return false
}

func main() {
	// Initialize BufferedReader to read input from the console
	br := bufio.NewReader(os.Stdin)
	// Initialize PrintWriter to output results to the console
	pw := bufio.NewWriter(os.Stdout)

	// Read the number of test cases
	var t int
	fmt.Fscan(br, &t)

	// Process each test case
	for i := 0; i < t; i++ {
		possibleSolutions := 0
		var solutions strings.Builder
		var s string
		fmt.Fscan(br, &s)

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
		fmt.Fprint(pw, possibleSolutions)
		fmt.Fprintln(pw, solutions)
	}

	// Flush and close the PrintWriter
	pw.Flush()
	pw.Close()
}

