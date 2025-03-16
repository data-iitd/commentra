

package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Step 1: Define the input reader and output writer
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Step 2: Create a LightScanner instance for reading input efficiently
	in := LightScanner{reader}

	// Step 3: Create an instance of the problem solver
	solver := BUnhappyHackingABCEdit{}

	// Step 4: Solve the problem
	solver.Solve(1, &in, writer)
}

// Helper class for solving the problem
type BUnhappyHackingABCEdit struct{}

func (solver *BUnhappyHackingABCEdit) Solve(testNumber int, in *LightScanner, writer *bufio.Writer) {
	// Read the input string
	s := in.String()

	// StringBuilder to build the result
	d := &strings.Builder{}

	// Iterate over each character in the input string
	for _, c := range s {
		switch c {
		case '0':
			// Append '0' to the result
			d.WriteRune('0')
		case '1':
			// Append '1' to the result
			d.WriteRune('1')
		case 'B':
			// Remove the last character if the result is not empty
			if d.Len() > 0 {
				d.Truncate(d.Len() - 1)
			}
		}
	}

	// Print the result
	fmt.Fprintln(writer, d.String())
}

// LightScanner class for reading input efficiently
type LightScanner struct {
	reader *bufio.Reader
}

func (in *LightScanner) String() string {
	if in.tokenizer == nil ||!in.tokenizer.More() {
		in.read()
	}
	return in.tokenizer.Token()
}

func (in *LightScanner) read() {
	in.tokenizer = nil
	line, err := in.reader.ReadString('\n')
	if err!= nil {
		panic(err)
	}
	in.tokenizer = strings.NewTokenizer(line)
}