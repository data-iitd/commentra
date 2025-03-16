package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Method to check if a given string can form a solution for a specific column count
func isSolution(columnsCount int, x string) bool {
	// Create an array to track if all positions for each column are 'X'
	allXs := make([]bool, columnsCount)
	for i := 0; i < columnsCount; i++ {
		allXs[i] = true
	}

	// Check each character in the string
	for i := 0; i < 12; i++ {
		// If the character is not 'X', mark the corresponding column as false
		if x[i]!= 'X' {
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
	t, _ := strconv.Atoi(br.ReadString())

	// Process each test case
	for i := 0; i < t; i++ {
		possibleSolutions := 0
		solutions := ""
		s, _ := br.ReadString()

		// Check for various column configurations and append valid solutions
		if isSolution(12, s) {
			solutions += " 1x12"
			possibleSolutions++
		}
		if isSolution(6, s) {
			solutions += " 2x6"
			possibleSolutions++
		}
		if isSolution(4, s) {
			solutions += " 3x4"
			possibleSolutions++
		}
		if isSolution(3, s) {
			solutions += " 4x3"
			possibleSolutions++
		}
		if isSolution(2, s) {
			solutions += " 6x2"
			possibleSolutions++
		}
		if isSolution(1, s) {
			solutions += " 12x1"
			possibleSolutions++
		}

		// Output the number of possible solutions and the solutions themselves
		pw.WriteString(fmt.Sprintf("%d\n%s\n", possibleSolutions, solutions))
	}

	// Flush and close the PrintWriter
	pw.Flush()
	pw.Close()
}

