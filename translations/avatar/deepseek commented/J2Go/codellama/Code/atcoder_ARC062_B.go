package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

// The main function initializes input and output streams, creates an instance of TaskD, and calls its solve method
func main() {
	inputStream := os.Stdin // Get the input stream from the system
	outputStream := os.Stdout // Get the output stream from the system
	in := NewInputReader(inputStream) // Create an InputReader instance to read input
	out := bufio.NewWriter(outputStream) // Create a bufio.Writer instance to write output
	solver := NewTaskD() // Create an instance of TaskD
	solver.Solve(1, in, out) // Call the Solve method of TaskD
	out.Flush() // Flush the output stream
}

// The TaskD struct contains the Solve method which calculates a score based on the input string
type TaskD struct{}

// The Solve method takes a test number, an InputReader instance, and a bufio.Writer instance
func (solver *TaskD) Solve(testNumber int, in *InputReader, out *bufio.Writer) {
	S := in.Next() // Read the next string from the input
	score := 0 // Initialize the score to 0
	// Iterate through each character in the string S
	for i := 0; i < len(S); i++ {
		my := 'g' // Determine the expected character based on the index
		if i % 2 == 0 {
			my = 'g'
		} else {
			my = 'p'
		}
		his := S[i] // Get the character at the current index in S
		// Compare the expected character with the actual character and update the score
		if my != his {
			if my == 'p' {
				score += 1
			} else {
				score -= 1
			}
		}
	}
	out.WriteString(strconv.Itoa(score) + "\n") // Print the final score
}

// The InputReader struct is used to read input efficiently
type InputReader struct {
	reader *bufio.Reader
	tokenizer *strings.Reader
}

// Constructor for InputReader
func NewInputReader(stream io.Reader) *InputReader {
	return &InputReader{
		reader: bufio.NewReader(stream),
		tokenizer: nil,
	}
}

// Method to read the next token from the input stream
func (in *InputReader) Next() string {
	for in.tokenizer == nil || !in.tokenizer.Scan() { // Check if there are more tokens
		line, err := in.reader.ReadString('\n') // Read the next line and tokenize it
		if err != nil {
			panic(err) // Throw a panic if an error occurs
		}
		in.tokenizer = strings.NewReader(line)
	}
	return in.tokenizer.Text() // Return the next token
}

