
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

func main() {
	// Create a SimpleScanner instance to read input from the standard input stream
	scanner := NewSimpleScanner(os.Stdin)

	// Create a PrintWriter instance to output results to the standard output stream
	writer := bufio.NewWriter(os.Stdout)

	// Read integer values for r and d, and a long value for x from the input
	r, _ := strconv.Atoi(scanner.Next())
	d, _ := strconv.Atoi(scanner.Next())
	x, _ := strconv.ParseInt(scanner.Next(), 10, 64)

	// Perform the calculation and output the result 10 times
	for i := 0; i < 10; i++ {
		// Update x according to the formula x = r * x - d
		x = int64(r) * x - int64(d)
		// Print the updated value of x
		fmt.Fprintln(writer, x)
	}

	// Close the PrintWriter to release resources
	writer.Flush()
}

// A custom scanner class to read input efficiently
type SimpleScanner struct {
	// Define a buffer size for reading input
	BUFFER_SIZE int

	// Declare variables for input stream, character buffer, and end-of-file flag
	in  io.Reader
	buf *bufio.Reader
	eof bool
}

// Constructor to initialize the scanner with an InputStream
func NewSimpleScanner(in io.Reader) *SimpleScanner {
	// Wrap the input stream in a BufferedReader for efficient reading
	buf := bufio.NewReader(in)
	return &SimpleScanner{
		BUFFER_SIZE: 10240,
		in:          in,
		buf:         buf,
		eof:         false,
	}
}

// Method to read a single character from the input
func (scanner *SimpleScanner) read() byte {
	// If the buffer is empty, refill it
	if !scanner.buf.Buffered() {
		scanner.buf.Reset(scanner.in)
		scanner.buf.Fill(scanner.BUFFER_SIZE)
		if scanner.buf.Buffered() == 0 {
			scanner.eof = true
			return 0
		}
	}
	// Return the next character from the buffer
	return scanner.buf.ReadByte()
}

// Method to check if the end of the input has been reached
func (scanner *SimpleScanner) checkEof() {
	if scanner.eof {
		panic("NoSuchElementException")
	}
}

// Method to read the next character, ensuring EOF is checked
func (scanner *SimpleScanner) nextChar() byte {
	scanner.checkEof()
	b := scanner.read()
	scanner.checkEof()
	return b
}

// Method to read the next token as a String
func (scanner *SimpleScanner) Next() string {
	b := scanner.nextChar()
	// Skip any whitespace characters
	for b != 0 && b <= ' ' {
		b = scanner.nextChar()
	}

	sb := make([]byte, 0, 1024)
	// Append characters until a whitespace or EOF is encountered
	for b != 0 && b > ' ' {
		sb = append(sb, b)
		b = scanner.nextChar()
	}

	return string(sb)
}

// Method to read the next integer from the input
func (scanner *SimpleScanner) NextInt() int {
	i, _ := strconv.Atoi(scanner.Next())
	return i
}

// Method to read the next long value from the input
func (scanner *SimpleScanner) NextLong() int64 {
	i, _ := strconv.ParseInt(scanner.Next(), 10, 64)
	return i
}

// Method to read the next double value from the input
func (scanner *SimpleScanner) NextDouble() float64 {
	f, _ := strconv.ParseFloat(scanner.Next(), 64)
	return f
}

// 