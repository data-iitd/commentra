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
	out := NewPrintWriter(outputStream)

	// Create an instance of TaskD to solve the problem
	solver := NewTaskD()

	// Call the solve method with test number, input reader, and output writer
	solver.Solve(1, in, out)

	// Close the PrintWriter to flush the output
	out.Close()
}

type TaskD struct{}

func NewTaskD() *TaskD {
	return &TaskD{}
}

func (this *TaskD) Solve(testNumber int, in *InputReader, out *PrintWriter) {
	// Read the input string S
	S := in.Next()
	score := 0 // Initialize score to zero

	// Iterate through each character in the string S
	for i := 0; i < len(S); i++ {
		// Determine the character for 'my' based on the index (even or odd)
		my := 'g'
		if i%2 == 0 {
			my = 'p'
		}

		// Get the character from the input string at the current index
		his := S[i]

		// Compare 'my' and 'his' characters to update the score
		if my != his {
			// Increment score if 'my' is 'p', otherwise decrement
			if my == 'p' {
				score++
			} else {
				score--
			}
		}
	}

	// Output the final score
	out.Println(score)
}

type InputReader struct {
	reader *bufio.Reader
	tokenizer *strings.Tokenizer
}

func NewInputReader(stream io.Reader) *InputReader {
	return &InputReader{
		reader: bufio.NewReader(stream),
		tokenizer: nil,
	}
}

func (this *InputReader) Next() string {
	// Keep reading until we have a token available
	for this.tokenizer == nil || !this.tokenizer.Scan() {
		line, err := this.reader.ReadString('\n')
		if err != nil {
			panic(err)
		}
		this.tokenizer = strings.NewTokenizer(line)
	}
	// Return the next token
	return this.tokenizer.Token().String()
}

type PrintWriter struct {
	writer *bufio.Writer
}

func NewPrintWriter(stream io.Writer) *PrintWriter {
	return &PrintWriter{
		writer: bufio.NewWriter(stream),
	}
}

func (this *PrintWriter) Println(a ...interface{}) {
	fmt.Fprintln(this.writer, a...)
}

func (this *PrintWriter) Close() {
	this.writer.Flush()
}

// 