
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Step 1: Define the input stream and output stream
	in := bufio.NewReader(os.Stdin)
	out := os.Stdout

	// Step 2: Create a LightScanner instance for reading input efficiently
	scanner := LightScanner{in}

	// Step 3: Create a PrintWriter instance for writing output
	writer := bufio.NewWriter(out)

	// Step 4: Create an instance of the problem solver
	solver := BUnhappyHackingABCEdit{}

	// Step 5: Solve the problem
	solver.solve(1, scanner, writer)

	// Close the output writer
	writer.Flush()
}

// Helper class for solving the problem
type BUnhappyHackingABCEdit struct {
}

func (solver *BUnhappyHackingABCEdit) solve(testNumber int, in LightScanner, out *bufio.Writer) {
	// Read the input string
	s := in.string()

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
				d.Truncate(d.Len() - 1)
			}
		}
	}

	// Print the result
	fmt.Fprintln(out, d.String())
}

// LightScanner class for reading input efficiently
type LightScanner struct {
	reader *bufio.Reader
}

func (scanner *LightScanner) string() string {
	s, _ := strconv.Unquote(scanner.reader.ReadString())
	return s
}

