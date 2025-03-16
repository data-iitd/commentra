// by syu
package main

import (
	"bufio" // Import bufio package for reading and writing streams
	"fmt"   // Import fmt package for formatted I/O
	"io"    // Import io package for working with I/O interfaces
	"os"    // Import os package for working with operating system interfaces
	"strconv" // Import strconv package for converting between string and numeric types
)

// Define a custom scanner type that wraps bufio.Scanner
type Scanner struct {
	*bufio.Scanner
}

// Initialize a new Scanner instance with the given reader and maximum buffer size
func NewScanner(r io.Reader, max int) *Scanner {
	s := bufio.NewScanner(r) // Create a new bufio.Scanner instance
	s.Split(scanWords)       // Set the split function to scanWords
	if max <= 0 {
		max = 1048576 // Set a default maximum buffer size if none is provided
	}
	s.Buffer([]byte{}, max) // Set the buffer size
	return &Scanner{s} // Return the Scanner instance
}

// Parse an integer from the current scanner data
func (s *Scanner) Int() int {
	s.Scan() // Scan the next token from the input
	i, e := strconv.ParseInt(s.Text(), 10, 64) // Parse the token as an integer
	if e != nil {
		panic(e) // Panic if there was an error parsing the token
	}
	return int(i) // Return the parsed integer
}

// Check if a byte is a whitespace character
func isSpace(b byte) bool {
	return b == ' ' || b == '\n' || b == '\r' || b == '\t'
}

// Split input data into tokens using scanWords function
func scanWords(data []byte, atEOF bool) (advance int, token []byte, err error) {
	start := 0 // Initialize start index of the token
	for start < len(data) && isSpace(data[start]) {
		start++ // Increment start index while reading whitespace characters
	}
	for i := start; i < len(data); i++ {
		if isSpace(data[i]) {
			return i + 1, data[start:i], nil // Return the token and advance index if a whitespace character is found
		}
	}
	if atEOF && len(data) > start { // If we've reached the end of the input and there are still characters left in the buffer
		return len(data), data[start:], nil // Return the remaining characters as the token
	}
	return start, nil, nil // Return an empty token and advance index if no token was found
}

// Print a line to the console with the given arguments
func Pln(s ...interface{}) {
	fmt.Println(s...) // Call fmt.Println with the given arguments
}

// Entry point of the program
func main() {
	// Read two integers n and k from standard input
	n, k := in.Int(), in.Int()
	// Check if n is divisible by k
	if n%k == 0 {
		// If n is divisible by k, print 0 to the console
		Pln(0)
	} else {
		// If n is not divisible by k, print 1 to the console
		Pln(1)
	}
}
