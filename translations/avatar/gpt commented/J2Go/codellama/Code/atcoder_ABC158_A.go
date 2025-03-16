package main

import (
	"fmt"
	"io"
	"os"
	"strings"
)

func main() {
	// Initialize input and output streams
	inputStream := os.Stdin
	outputStream := os.Stdout

	// Create a Scanner object for reading input and a PrintWriter for output
	in := bufio.NewScanner(inputStream)
	out := bufio.NewWriter(outputStream)

	// Create an instance of the AStationAndBus class to solve the problem
	solver := AStationAndBus{}

	// Call the solve method with test number 1, passing the input and output objects
	solver.solve(1, in, out)

	// Close the PrintWriter to flush the output
	out.Flush()
}

// Static inner class to handle the logic of the problem
type AStationAndBus struct{}

func (solver *AStationAndBus) solve(testNumber int, in *bufio.Scanner, out *bufio.Writer) {
	// Read the input string
	var s string
	in.Scan()
	s = in.Text()

	// Check if the string contains both 'A' and 'B'
	if strings.Contains(s, "A") && strings.Contains(s, "B") {
		// If both characters are present, print "Yes"
		fmt.Fprintln(out, "Yes")
	} else {
		// If either character is missing, print "No"
		fmt.Fprintln(out, "No")
	}
}

