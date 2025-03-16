package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

// SimpleScanner is a simple scanner for reading input
type SimpleScanner struct {
	in     *bufio.Reader
	buffer []byte
	eof    bool
}

// NewSimpleScanner creates a new SimpleScanner instance
func NewSimpleScanner(in io.Reader) *SimpleScanner {
	return &SimpleScanner{
		in:     bufio.NewReader(in),
		buffer: make([]byte, 10240),
		eof:    false,
	}
}

// Read reads a character from the buffer or input stream
func (scanner *SimpleScanner) Read() byte {
	if len(scanner.buffer) == 0 {
		n, err := scanner.in.Read(scanner.buffer)
		if err != nil || n == 0 {
			scanner.eof = true
			return 0
		}
	}
	b := scanner.buffer[0]
	scanner.buffer = scanner.buffer[1:]
	return b
}

// CheckEOF checks if the end of file has been reached
func (scanner *SimpleScanner) CheckEOF() {
	if scanner.eof {
		panic("NoSuchElementException")
	}
}

// NextChar reads the next character
func (scanner *SimpleScanner) NextChar() byte {
	scanner.CheckEOF()
	b := scanner.Read()
	scanner.CheckEOF()
	return b
}

// Next reads the next string
func (scanner *SimpleScanner) Next() string {
	var b byte
	for {
		b = scanner.NextChar()
		if b == 0 {
			break
		}
		if !isWhitespace(b) {
			break
		}
	}
	sb := make([]byte, 0, 1024)
	sb = append(sb, b)
	for {
		b = scanner.NextChar()
		if b == 0 {
			break
		}
		if isWhitespace(b) {
			break
		}
		sb = append(sb, b)
	}
	return string(sb)
}

// NextInt reads the next integer
func (scanner *SimpleScanner) NextInt() int {
	return strconv.Atoi(scanner.Next())
}

// NextLong reads the next long integer
func (scanner *SimpleScanner) NextLong() int64 {
	return strconv.ParseInt(scanner.Next(), 10, 64)
}

// NextDouble reads the next double
func (scanner *SimpleScanner) NextDouble() float64 {
	return strconv.ParseFloat(scanner.Next(), 64)
}

// isWhitespace checks if the given character is a whitespace
func isWhitespace(b byte) bool {
	return b == ' ' || b == '\n' || b == '\r' || b == '\t' || b == '\f' || b == '\v'
}

func main() {
	// Create a SimpleScanner instance to read from standard input
	scanner := NewSimpleScanner(os.Stdin)
	// Create a PrintWriter instance to write to standard output
	writer := bufio.NewWriter(os.Stdout)

	// Read three integers from the input
	r := scanner.NextInt()
	d := scanner.NextInt()
	x := scanner.NextLong()

	// Perform the calculation in a loop and print the result 10 times
	for i := 0; i < 10; i++ {
		x = int64(r) * x - d
		fmt.Fprintln(writer, x)
	}

	// Close the PrintWriter to ensure all data is flushed to the output
	writer.Flush()
}

// 