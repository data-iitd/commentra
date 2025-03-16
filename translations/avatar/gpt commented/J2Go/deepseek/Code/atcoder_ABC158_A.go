package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Initialize input and output streams
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Create a Scanner object for reading input and a PrintWriter for output
	// (In Go, we use bufio.Scanner for input and writer.Writer for output)
	scanner := bufio.NewScanner(reader)
	scanner.Split(bufio.ScanWords)

	// Create an instance of the AStationAndBus struct to solve the problem
	solver := AStationAndBus{}

	// Call the solve method with test number 1, passing the input and output objects
	solver.solve(1, scanner, writer)
}

// Static inner class to handle the logic of the problem
type AStationAndBus struct{}

func (solver AStationAndBus) solve(testNumber int, scanner *bufio.Scanner, writer *bufio.Writer) {
	// Read the input string
	scanner.Scan()
	s := scanner.Text()

	// Check if the string contains both 'A' and 'B'
	if containsA, containsB := containsAB(s); containsA && containsB {
		// If both characters are present, print "Yes"
		writer.WriteString("Yes\n")
	} else {
		// If either character is missing, print "No"
		writer.WriteString("No\n")
	}
}

// Helper function to check if the string contains 'A' and 'B'
func containsAB(s string) (bool, bool) {
	return containsChar(s, 'A'), containsChar(s, 'B')
}

// Helper function to check if the string contains a specific character
func containsChar(s string, char byte) bool {
	for i := 0; i < len(s); i++ {
		if s[i] == char {
			return true
		}
	}
	return false
}

