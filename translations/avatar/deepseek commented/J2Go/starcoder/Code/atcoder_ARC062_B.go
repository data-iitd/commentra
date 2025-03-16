package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// The TaskD struct contains the solve method which calculates a score based on the input string
type TaskD struct {
}

// The solve method takes a test number, an InputReader instance, and a PrintWriter instance
func (t *TaskD) solve(testNumber int, in *InputReader, out *bufio.Writer) {
	S := in.next() // Read the next string from the input
	score := 0     // Initialize the score to 0
	// Iterate through each character in the string S
	for i := 0; i < len(S); i++ {
		my := 'g'
		if i%2 == 1 {
			my = 'p'
		}
		his := S[i]
		// Compare the expected character with the actual character and update the score
		if my!= his {
			score += my == 'p' {
			1 : -1
		}
	}
	out.WriteString(strconv.Itoa(score) + "\n") // Print the final score
}

// The InputReader struct is used to read input efficiently
type InputReader struct {
	reader *bufio.Reader
	tokenizer *strings.Tokenizer
}

// Constructor for InputReader
func NewInputReader(stream *os.File) *InputReader {
	return &InputReader{
		reader: bufio.NewReader(stream),
		tokenizer: nil,
	}
}

// Method to read the next token from the input stream
func (in *InputReader) next() string {
	for in.tokenizer == nil ||!in.tokenizer.Scan() {
		in.tokenizer = nil
		var err error
		in.tokenizer, err = in.reader.ReadString('\n')
		if err!= nil {
			panic(err)
		}
	}
	return in.tokenizer.Text()
}

func main() {
	in := NewInputReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	t := new(TaskD)
	t.solve(1, in, out)
	out.Flush()
}

