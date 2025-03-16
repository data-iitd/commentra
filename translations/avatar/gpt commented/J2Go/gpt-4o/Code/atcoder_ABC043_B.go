package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Set up input and output streams
	input := bufio.NewReader(os.Stdin)
	output := bufio.NewWriter(os.Stdout)
	defer output.Flush()

	// Create an instance of the problem solver
	solver := BUnhappyHackingABCEdit{}

	// Solve the problem for the first test case
	solver.Solve(input, output)
}

// Struct to solve the B Unhappy Hacking problem
type BUnhappyHackingABCEdit struct{}

// Method to solve the problem
func (solver *BUnhappyHackingABCEdit) Solve(input *bufio.Reader, output *bufio.Writer) {
	// Read the input string
	s, _ := input.ReadString('\n')
	s = strings.TrimSpace(s)

	// StringBuilder equivalent in Go
	var d strings.Builder

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
				// Remove the last character
				d.Truncate(d.Len() - 1)
			}
		}
	}
	// Output the final result
	output.WriteString(d.String() + "\n")
}

// Note: The LightScanner class is not needed in Go as we can use bufio directly.
