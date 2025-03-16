
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

// isSolution checks if the given string represents a valid solution
func isSolution(columnsCount int, x string) bool {
	allXs := make([]bool, columnsCount) // Initialize an array to keep track of the presence of 'X' in each column
	for i := 0; i < columnsCount; i++ {
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
	reader := bufio.NewReaderSize(os.Stdin, 1024*1024)

	var t int
	_, err := fmt.Fscan(reader, &t)
	checkError(err)

	for i := 0; i < t; i++ {
		var possibleSolutions int
		var solutions strings.Builder

		var s string
		_, err = fmt.Fscan(reader, &s)
		checkError(err)

		// Check if the given string represents a valid solution
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

		// Write the output
		fmt.Printf("%dx%d ", possibleSolutions, 12)
		fmt.Println(solutions.String())
	}
}

func checkError(err error) {
	if err != nil {
		panic(err)
	}
}

