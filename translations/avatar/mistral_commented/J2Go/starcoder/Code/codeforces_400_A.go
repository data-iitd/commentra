
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Method to check if a given string represents a valid solution
func isSolution(columnsCount int, x string) bool {
	allXs := make([]bool, columnsCount) // Initialize an array to keep track of the presence of 'X' in each column
	for i := 0; i < columnsCount; i++ {
		allXs[i] = true // Set all columns to have 'X' initially
	}

	// Iterate through the given string and mark the corresponding columns as not having 'X'
	for i := 0; i < 12; i++ {
		if x[i]!= 'X' {
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
	reader := bufio.NewReader(os.Stdin)
	t, _ := strconv.Atoi(readLine(reader))

	for i := 0; i < t; i++ {
		possibleSolutions := 0 // Initialize the counter for the number of valid solutions
		solutions := ""         // Initialize a string builder to store the valid solutions

		s := readLine(reader) // Read the given string

		// Check if the given string represents a valid solution
		if isSolution(12, s) {
			solutions += " 1x12" // Add the solution to the string builder
			possibleSolutions++  // Increment the counter
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

		// Write the output
		fmt.Printf("%d %s\n", possibleSolutions, solutions)
	}
}

// ReadLine reads a line from the given reader
func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

