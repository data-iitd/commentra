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
	// Create a SimpleScanner instance to read input from the standard input stream
	scanner := NewSimpleScanner(os.Stdin)

	// Create a PrintWriter instance to output results to the standard output stream
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read integer values for r and d, and a long value for x from the input
	r := scanner.nextInt()
	d := scanner.nextInt()
	x := scanner.nextLong()

	// Perform the calculation and output the result 10 times
	for i := 0; i < 10; i++ {
		// Update x according to the formula x = r * x - d
		x = int64(r)*x - int64(d)
		// Print the updated value of x
		writer.WriteString(fmt.Sprintf("%d\n", x))
	}
}

// A custom scanner class to read input efficiently
type SimpleScanner struct {
	// Define a buffer size for reading input
	BUFFER_SIZE int

	// Declare variables for input stream, character buffer, and end-of-file flag
	in          io.Reader
	buffer      *strings.Builder
	eof         bool
	reader      *bufio.Reader
}

// Constructor to initialize the scanner with an InputStream
func NewSimpleScanner(in io.Reader) *SimpleScanner {
	return &SimpleScanner{
		BUFFER_SIZE: 10240,
		in:          in,
		buffer:      &strings.Builder{},
		eof:         false,
		reader:      bufio.NewReader(in),
	}
}

// Method to read a single character from the input
func (s *SimpleScanner) read() byte {
	// If the buffer is empty, refill it
	if s.buffer.Len() == 0 {
		bytes, err := s.reader.ReadBytes('\n')
		if err != nil {
			if err == io.EOF {
				s.eof = true
				return 0
			}
			// Handle other I/O errors
			panic(err)
		}
		s.buffer.Write(bytes)
	}
	// Return the next character from the buffer
	return s.buffer.String()[0]
}

// Method to check if the end of the input has been reached
func (s *SimpleScanner) checkEof() {
	if s.eof {
		panic(io.EOF)
	}
}

// Method to read the next character, ensuring EOF is checked
func (s *SimpleScanner) nextChar() byte {
	s.checkEof()
	b := s.read()
	s.checkEof()
	return b
}

// Method to read the next token as a String
func (s *SimpleScanner) next() string {
	var b byte
	// Skip any whitespace characters
	for {
		b = s.read()
		s.checkEof()
		if !isWhitespace(b) {
			break
		}
	}

	var sb strings.Builder
	// Append characters until a whitespace or EOF is encountered
	for {
		sb.WriteByte(b)
		b = s.read()
		s.checkEof()
		if isWhitespace(b) {
			break
		}
	}

	return sb.String()
}

// Method to read the next integer from the input
func (s *SimpleScanner) nextInt() int {
	numStr := s.next()
	num, err := strconv.Atoi(numStr)
	if err != nil {
		panic(err)
	}
	return num
}

// Method to read the next long value from the input
func (s *SimpleScanner) nextLong() int64 {
	numStr := s.next()
	num, err := strconv.ParseInt(numStr, 10, 64)
	if err != nil {
		panic(err)
	}
	return num
}

// Helper function to check if a character is a whitespace
func isWhitespace(b byte) bool {
	return b == ' ' || b == '\n' || b == '\r' || b == '\t' || b == '\v'
}
