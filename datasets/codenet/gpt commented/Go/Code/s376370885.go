// by syu
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

// Initialize a new Scanner for reading input from standard input (os.Stdin)
var in = NewScanner(os.Stdin, 0)

func main() {
	// Read two integers n and k from the input
	n, k := in.Int(), in.Int()
	
	// Check if n is divisible by k
	if n%k == 0 {
		// If n is divisible by k, print 0
		Pln(0)
	} else {
		// If n is not divisible by k, print 1
		Pln(1)
	}
}

// Scanner struct wraps bufio.Scanner for custom input handling
type Scanner struct {
	*bufio.Scanner
}

// NewScanner initializes a new Scanner with a specified buffer size
func NewScanner(r io.Reader, max int) *Scanner {
	s := bufio.NewScanner(r) // Create a new Scanner
	s.Split(scanWords)       // Set the split function to scan words
	if max <= 0 {
		max = 1048576 // Default buffer size if max is not specified
	}
	s.Buffer([]byte{}, max) // Set the buffer size for the scanner
	return &Scanner{s}      // Return the new Scanner instance
}

// Int reads the next token from the input and converts it to an integer
func (s *Scanner) Int() int {
	s.Scan() // Scan the next token
	i, e := strconv.ParseInt(s.Text(), 10, 64) // Parse the token as an integer
	if e != nil {
		panic(e) // Panic if there is an error during parsing
	}
	return int(i) // Return the parsed integer
}

// isSpace checks if a byte is a whitespace character
func isSpace(b byte) bool {
	return b == ' ' || b == '\n' || b == '\r' || b == '\t'
}

// scanWords is a custom split function for the Scanner to tokenize input
func scanWords(data []byte, atEOF bool) (advance int, token []byte, err error) {
	start := 0
	// Skip leading whitespace
	for start < len(data) && isSpace(data[start]) {
		start++
	}
	// Find the end of the next word
	for i := start; i < len(data); i++ {
		if isSpace(data[i]) {
			return i + 1, data[start:i], nil // Return the word found
		}
	}
	// If at EOF and there is data left, return the last word
	if atEOF && len(data) > start {
		return len(data), data[start:], nil
	}
	return start, nil, nil // Return the current position if no word is found
}

// Pln is a convenience function to print a line to standard output
func Pln(s ...interface{}) {
	fmt.Println(s...) // Print the provided arguments
}
