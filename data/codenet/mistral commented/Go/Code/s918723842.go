// Package main contains the entry point of the program.
package main

import (
	// bufio package provides methods for reading and writing text from I/O streams.
	"bufio"
	// fmt package provides functions for formatting and printing data.
	"fmt"
	// os package provides access to the operating system.
	"os"
	// strconv package provides functions for converting between strings and other types.
	"strconv"
)

// main function is the entry point of the program.
func main() {
	// Initialize a new Scanner object named sc.
	sc := NewScanner()
	// Read the height H, width W, and number of obstacles N from the standard input.
	H, W, N := sc.NextInt(), sc.NextInt(), sc.NextInt()
	// Calculate the maximum dimension A between H and W.
	A := max(H, W)
	// Print the result, which is the number of rows or columns needed to place all obstacles without overlapping.
	fmt.Println((N + A - 1) / A)
}

// max function returns the maximum value between two integers a and b.
func max(a int, b int) int {
	// If a is smaller than b, return b.
	if a < b {
		return b
	}
	// Otherwise, return a.
	return a
}

// Scanner struct represents the input reader.
type Scanner struct {
	// bufio.Reader field r is used for reading from the standard input.
	r   *bufio.Reader
	// buf byte slice buffer is used for storing the input line.
	buf []byte
	// p integer p keeps track of the current position in the buffer.
	p   int
}

// NewScanner function initializes a new Scanner object with the standard input os.Stdin as the reader.
func NewScanner() *Scanner {
	// Initialize a new bufio.Reader object named rdr with the standard input as the I/O source.
	rdr := bufio.NewReaderSize(os.Stdin, 1000)
	// Initialize a new Scanner object named s with the rdr as the reader field.
	s := &Scanner{r: rdr}
	// Return the initialized Scanner object.
	return s
}

// Next method reads the next token from the input, which can be a single word, number, or symbol.
// It skips leading whitespaces and returns the result as a string.
func (s *Scanner) Next() string {
	// Set the current position p to the beginning of the buffer if it's at the end.
	s.pre()
	// Start index of the token in the buffer.
	start := s.p
	// Read the input until a non-whitespace character is found.
	for ; s.p < len(s.buf); s.p++ {
		// If the current character is a whitespace, break the loop.
		if s.buf[s.p] == ' ' {
			break
		}
	}
	// Read the token, including the whitespace character if any.
	result := string(s.buf[start:s.p])
	// Increment the current position p.
	s.p++
	// Return the result.
	return result
}

// NextLine method reads the next line from the input and returns it as a string.
func (s *Scanner) NextLine() string {
	// Set the current position p to the beginning of the buffer if it's at the end.
	s.pre()
	// Start index of the line in the buffer.
	start := s.p
	// Read the input until the end of the line is reached.
	for ; s.p < len(s.buf); s.p++ {
		// If the current character is a newline character, break the loop.
		if s.buf[s.p] == '\n' {
			break
		}
	}
	// Read the line, including the newline character if any.
	result := string(s.buf[start:s.p])
	// Increment the current position p.
	s.p++
	// Return the result.
	return result
}

// NextInt method reads an integer from the input and returns it.
func (s *Scanner) NextInt() int {
	// Read the next token as a string.
	token := s.Next()
	// Parse the token as an integer and return the result.
	v, _ := strconv.Atoi(token)
	// Return the result.
	return v
}

// NextInt64 method reads a 64-bit integer from the input and returns it.
func (s *Scanner) NextInt64() int64 {
	// Read the next token as a string.
	token := s.Next()
	// Parse the token as a 64-bit integer and return the result.
	v, _ := strconv.ParseInt(token, 10, 64)
	// Return the result.
	return v
}

// NextFloat method reads a floating-point number from the input and returns it.
func (s *Scanner) NextFloat() float64 {
	// Read the next token as a string.
	token := s.Next()
	// Parse the token as a floating-point number and return the result.
	v, _ := strconv.ParseFloat(token, 64)
	// Return the result.
	return v
}

// NextIntArray method reads an array of integers from the input and returns it.
func (s *Scanner) NextIntArray() []int {
	// Read the next line as a string.
	line := s.NextLine()
	// Split the line into tokens using spaces as delimiters.
	tokens := strings.Split(line, " ")
	// Parse each token as an integer and append it to the result slice.
	result := make([]int, len(tokens))
	for i, token := range tokens {
		v, _ := strconv.Atoi(token)
		result[i] = v
	}
	// Return the result.
	return result
}

// NextInt64Array method reads an array of 64-bit integers from the input and returns it.
func (s *Scanner) NextInt64Array() []int64 {
	// Read the next line as a string.
	line := s.NextLine()
	// Split the line into tokens using spaces as delimiters.
	tokens := strings.Split(line, " ")
	// Parse each token as a 64-bit integer and append it to the result slice.
	result := make([]int64, len(tokens))
	for i, token := range tokens {
		v, _ := strconv.ParseInt(token, 10, 64)
		result[i] = v
	}
	// Return the result.
	return result
}

// NextMap method reads a map from the input and returns it.
func (s *Scanner) NextMap() map[int]bool {
	// Read the next line as a string.
	line := s.NextLine()
	// Split the line into tokens using spaces as delimiters.
	tokens := strings.Split(line, " ")
	// Parse each token as an integer and create a key-value pair.
	mp := make(map[int]bool)
	for _, token := range tokens {
		key, _ := strconv.Atoi(strings.Split(token, ":")[0])
		mp[key] = true
	}
	// Return the result.
	return mp
}

// pre method sets the current position p to the beginning of the buffer if it's at the end.
func (s *Scanner) pre() {
	// If the current position p is at the end of the buffer, read the next line.
	if s.p >= len(s.buf) {
		s.readLine()
		s.p = 0
	}
}

// readLine method reads a line from the input and appends it to the buffer.
func (s *Scanner) readLine() {
	// Read a line from the input using the bufio.Reader.
	line, _ := s.r.ReadString('\n')
	// Remove the newline character from the line.
	line = strings.TrimRight(line, "\n")
	// Append the line to the buffer.
	s.buf = append(s.buf, line...)
}