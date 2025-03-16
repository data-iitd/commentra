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

	// Create an InputReader to read input from the input stream
	in := NewInputReader(inputStream)

	// Create a PrintWriter to write output to the output stream
	out := bufio.NewWriter(outputStream)

	// Instantiate the solver class for the problem
	solver := NewCColoringColorfully()

	// Solve the problem for the first test case
	solver.Solve(1, in, out)

	// Close the output stream
	out.Flush()
}

type CColoringColorfully struct{}

func NewCColoringColorfully() *CColoringColorfully {
	return &CColoringColorfully{}
}

func (this *CColoringColorfully) Solve(testNumber int, in *InputReader, out *bufio.Writer) {
	// Read the input string
	x := in.Next()

	// Create two StringBuilders to manipulate the string
	a := strings.Builder{}
	b := strings.Builder{}

	// Initialize counters for the number of changes made
	a1 := 0
	a2 := 0

	// First pass: modify 'a' from left to right
	for i := 1; i < len(x); i++ {
		// Check if the current character is the same as the previous one
		if x[i] == x[i-1] {
			// Change the character to the opposite value
			if x[i] == '1' {
				a.WriteByte('0')
			} else {
				a.WriteByte('1')
			}

			// Increment the change counter
			a1++
		} else {
			a.WriteByte(x[i])
		}
	}

	// Second pass: modify 'b' from right to left
	for i := len(x) - 1; i > 0; i-- {
		// Check if the current character is the same as the previous one
		if x[i] == x[i-1] {
			// Change the previous character to the opposite value
			if x[i-1] == '1' {
				b.WriteByte('0')
			} else {
				b.WriteByte('1')
			}

			// Increment the change counter
			a2++
		} else {
			b.WriteByte(x[i])
		}
	}

	// Output the minimum number of changes made in either pass
	out.WriteString(strconv.Itoa(min(a1, a2)))
	out.WriteString("\n")
}

type InputReader struct {
	reader *bufio.Reader
	tokenizer *strings.Reader
}

func NewInputReader(stream io.Reader) *InputReader {
	return &InputReader{
		reader: bufio.NewReader(stream),
		tokenizer: nil,
	}
}

func (this *InputReader) Next() string {
	// Ensure there are tokens available to read
	for this.tokenizer == nil || !this.tokenizer.Scan() {
		var err error
		this.tokenizer, err = this.reader.ReadString('\n')
		if err != nil {
			panic(err)
		}
	}

	// Return the next token
	return this.tokenizer.Text()
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

