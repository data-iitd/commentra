
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strings"
)

func main() {
	// Step 1: Define the input stream and output stream
	inputStream := os.Stdin
	outputStream := os.Stdout

	// Step 2: Create a LightScanner instance for reading input efficiently
	in := NewLightScanner(inputStream)

	// Step 3: Create a PrintWriter instance for writing output
	out := bufio.NewWriter(outputStream)

	// Step 4: Create an instance of the problem solver
	solver := NewBUnhappyHackingABCEdit()

	// Step 5: Solve the problem
	solver.Solve(1, in, out)

	// Close the output writer
	out.Flush()
}

// Helper class for solving the problem
type BUnhappyHackingABCEdit struct{}

// Solve the problem
func (solver *BUnhappyHackingABCEdit) Solve(testNumber int, in *LightScanner, out *bufio.Writer) {
	// Read the input string
	s := in.String()

	// StringBuilder to build the result
	d := strings.Builder{}

	// Iterate over each character in the input string
	for _, c := range s {
		switch c {
		case '0':
			// Append '0' to the result
			d.WriteString("0")
		case '1':
			// Append '1' to the result
			d.WriteString("1")
		case 'B':
			// Remove the last character if the result is not empty
			if d.Len() > 0 {
				d.Reset()
			}
		}
	}

	// Print the result
	fmt.Fprintln(out, d.String())
}

// LightScanner class for reading input efficiently
type LightScanner struct {
	reader *bufio.Reader
	tokenizer *strings.Reader
}

// Create a new instance of the LightScanner class
func NewLightScanner(in io.Reader) *LightScanner {
	return &LightScanner{
		reader: bufio.NewReader(in),
	}
}

// Read the input string
func (in *LightScanner) String() string {
	if in.tokenizer == nil || !in.tokenizer.Scan() {
		in.tokenizer = strings.NewReader(in.reader.ReadString('\n'))
	}
	return in.tokenizer.Text()
}

