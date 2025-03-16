package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Set up input and output streams
	inputStream := os.Stdin
	outputStream := os.Stdout

	// Initialize the LightScanner for reading input
	in := NewLightScanner(inputStream)

	// Initialize PrintWriter for output
	out := bufio.NewWriter(outputStream)
	defer out.Flush()

	// Create an instance of the problem solver
	solver := BUnhappyHackingABCEdit{}

	// Solve the problem for the first test case
	solver.solve(1, in, out)
}

// Class to solve the B Unhappy Hacking problem
type BUnhappyHackingABCEdit struct{}

func (solver BUnhappyHackingABCEdit) solve(testNumber int, in *LightScanner, out io.Writer) {
	// Read the input string
	s := in.string()
	// StringBuilder to construct the output string
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
				d.Truncate(d.Len() - 1)
			}
		}
	}
	// Output the final result
	out.Write([]byte(d.String()))
}

// Class for reading input efficiently
type LightScanner struct {
	scanner *bufio.Scanner
}

func NewLightScanner(in io.Reader) *LightScanner {
	scanner := bufio.NewScanner(in)
	scanner.Split(bufio.ScanLines)
	return &LightScanner{scanner: scanner}
}

func (in *LightScanner) string() string {
	// Check if there are more tokens to read
	if !in.scanner.Scan() {
		return ""
	}
	// Return the next token
	return in.scanner.Text()
}

