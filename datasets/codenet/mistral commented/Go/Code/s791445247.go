
// by syu
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

// Initialize a new scanner for reading input
var in Scanner

func main() {
	// Read the first two integers from the standard input
	n, k := in.Int(), in.Int()

	// Check if n is divisible by k
	if n%k == 0 {
		// If it is, print 0
		Pln(0)
	} else {
		// If not, print 1
		Pln(1)
	}
}

// Define a new Scanner type
type Scanner struct {
	*bufio.Scanner
}

// Create a new Scanner instance
func NewScanner(r io.Reader, max int) *Scanner {
	// Initialize a new bufio.Scanner instance
	s := bufio.NewScanner(r)
	// Set the split function to split on words instead of whitespace
	s.Split(scanWords)
	// Set the buffer size if it's provided
	if max <= 0 {
		max = 1048576
	}
	// Set the buffer and return the new Scanner instance
	s.Buffer([]byte{}, max)
	return &Scanner{s}
}

// Parse an integer from a string
func (s *Scanner) Int() int {
	// Read the next token as a string
	s.Scan()
	// Parse the string to an integer and return it
	i, _ := strconv.ParseInt(s.Text(), 10, 64)
	// Return the integer value
	return int(i)
}

// Check if a byte is a whitespace character
func isSpace(b byte) bool {
	// Return true if the byte is a space, newline, carriage return, or tab character
	return b == ' ' || b == '\n' || b == '\r' || b == '\t'
}

// Split function for bufio.Scanner to split on words instead of whitespace
func scanWords(data []byte, atEOF bool) (advance int, token []byte, err error) {
	// Initialize the start index
	start := 0
	// Find the first non-whitespace character
	for start < len(data) && isSpace(data[start]) {
		start++
	}
	// Iterate through the data and find the next whitespace character or end of data
	for i := start; i < len(data); i++ {
		// If the current character is a whitespace character, return the token and advance the index
		if isSpace(data[i]) {
			return i + 1, data[start:i], nil
		}
	}
	// If we've reached the end of data and there's still data to read, return the remaining data as the token
	if atEOF && len(data) > start {
		return len(data), data[start:], nil
	}
	// Return the start index as the token and the length of the token as the advance value
	return start, nil, nil
}

// Print a line with the given arguments
func Pln(s ...interface{}) {
	// Print the line with the given arguments
	fmt.Println(s...)
}

