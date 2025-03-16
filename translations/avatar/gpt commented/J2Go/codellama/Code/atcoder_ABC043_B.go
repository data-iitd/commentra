package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strings"
)

func main() {
	// Set up input and output streams
	inputStream := os.Stdin
	outputStream := os.Stdout

	// Initialize the LightScanner for reading input
	in := LightScanner{inputStream}

	// Initialize PrintWriter for output
	out := bufio.NewWriter(outputStream)

	// Create an instance of the problem solver
	solver := BUnhappyHackingABCEdit{}

	// Solve the problem for the first test case
	solver.solve(1, in, out)

	// Close the output stream
	out.Flush()
}

// Class to solve the B Unhappy Hacking problem
type BUnhappyHackingABCEdit struct{}

// Solve the problem for the given test case
func (solver *BUnhappyHackingABCEdit) solve(testNumber int, in LightScanner, out *bufio.Writer) {
	// Read the input string
	s := in.string()
	// StringBuilder to construct the output string
	d := strings.Builder{}

	// Process each character in the input string
	for _, c := range s {
		switch c {
		case '0':
			// Append '0' to the output
			d.WriteString("0")
		case '1':
			// Append '1' to the output
			d.WriteString("1")
		case 'B':
			// Handle the 'B' character by removing the last character if possible
			if d.Len() > 0 {
				d.Truncate(d.Len() - 1) // Remove the last character
			}
		}
	}
	// Output the final result
	fmt.Fprintln(out, d.String())
}

// Class for reading input efficiently
type LightScanner struct {
	reader *bufio.Reader
}

// Method to read the next string token from input
func (in *LightScanner) string() string {
	// Check if there are more tokens to read
	if in.reader == nil || !in.reader.Scan() {
		// Handle EOF by returning an empty string
		return ""
	}
	// Return the next token
	return in.reader.Text()
}

// END-OF-CODE
