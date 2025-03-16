package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Initialize a new FastScanner to read input
	fsc := NewFastScanner()
	// Read three integers A, B, and C from input
	A, B, C := fsc.NextInt(), fsc.NextInt(), fsc.NextInt()
	// Check if the difference between B and A is equal to the difference between C and B
	if B-A == C-B {
		// If the differences are equal, print "YES"
		fmt.Println("YES")
	} else {
		// Otherwise, print "NO"
		fmt.Println("NO")
	}
}

// FastScanner is a structure for efficient input reading
type FastScanner struct {
	r   *bufio.Reader // Buffered reader for input
	buf []byte        // Buffer to hold the input data
	p   int           // Current position in the buffer
}

// NewFastScanner initializes and returns a new FastScanner
func NewFastScanner() *FastScanner {
	// Create a new buffered reader with a specified size
	rdr := bufio.NewReaderSize(os.Stdin, 1024)
	return &FastScanner{r: rdr}
}

// Next reads the next token from the input
func (s *FastScanner) Next() string {
	s.pre() // Ensure there is data to read
	start := s.p // Mark the start position
	// Iterate through the buffer until a space is found
	for ; s.p < len(s.buf); s.p++ {
		if s.buf[s.p] == ' ' {
			break
		}
	}
	result := string(s.buf[start:s.p]) // Extract the token
	s.p++ // Move past the space
	return result // Return the token
}

// NextLine reads the next line from the input
func (s *FastScanner) NextLine() string {
	s.pre() // Ensure there is data to read
	start := s.p // Mark the start position
	s.p = len(s.buf) // Move to the end of the buffer
	return string(s.buf[start:]) // Return the line
}

// NextInt reads the next integer from the input
func (s *FastScanner) NextInt() int {
	v, _ := strconv.Atoi(s.Next()) // Convert the next token to an integer
	return v // Return the integer
}

// NextInt64 reads the next int64 from the input
func (s *FastScanner) NextInt64() int64 {
	v, _ := strconv.ParseInt(s.Next(), 10, 64) // Convert the next token to int64
	return v // Return the int64
}

// pre checks if the buffer needs to be filled with new data
func (s *FastScanner) pre() {
	if s.p >= len(s.buf) { // If the current position is at or beyond the buffer length
		s.readLine() // Read a new line into the buffer
		s.p = 0 // Reset the position to the start of the buffer
	}
}

// readLine reads a line from the input and fills the buffer
func (s *FastScanner) readLine() {
	s.buf = make([]byte, 0) // Reset the buffer
	for {
		l, p, e := s.r.ReadLine() // Read a line from the buffered reader
		if e != nil {
			panic(e) // Panic if there is an error
		}
		s.buf = append(s.buf, l...) // Append the line to the buffer
		if !p { // If the line is not partial
			break // Exit the loop
		}
	}
}

// IntMax returns the maximum of two integers
func IntMax(a, b int) int {
	if a < b {
		return b // Return b if it is greater
	}
	return a // Otherwise, return a
}

// Int64Max returns the maximum of two int64 values
func Int64Max(a, b int64) int64 {
	if a < b {
		return b // Return b if it is greater
	}
	return a // Otherwise, return a
}

// Float64Max returns the maximum of two float64 values
func Float64Max(a, b float64) float64 {
	if a < b {
		return b // Return b if it is greater
	}
	return a // Otherwise, return a
}

// IntMin returns the minimum of two integers
func IntMin(a, b int) int {
	if a > b {
		return b // Return b if it is smaller
	}
	return a // Otherwise, return a
}

// Int64Min returns the minimum of two int64 values
func Int64Min(a, b int64) int64 {
	if a > b {
		return b // Return b if it is smaller
	}
	return a // Otherwise, return a
}

// Float64Min returns the minimum of two float64 values
func Float64Min(a, b float64) float64 {
	if a > b {
		return b // Return b if it is smaller
	}
	return a // Otherwise, return a
}

// IntGcd computes the greatest common divisor of two integers
func IntGcd(a, b int) int {
	if a < b {
		b, a = a, b // Ensure a is the larger number
	}
	if b == 0 {
		return a // If b is zero, return a
	}
	return IntGcd(b, a%b) // Recursive call to find GCD
}

// Int64Gcd computes the greatest common divisor of two int64 values
func Int64Gcd(a, b int64) int64 {
	if a < b {
		b, a = a, b // Ensure a is the larger number
	}
	if b == 0 {
		return a // If b is zero, return a
	}
	return Int64Gcd(b, a%b) // Recursive call to find GCD
}

// IntAbs returns the absolute value of an integer
func IntAbs(a int) int {
	if a < 0 {
		a *= -1 // Negate if a is negative
	}
	return a // Return the absolute value
}

// Int64Abs returns the absolute value of an int64
func Int64Abs(a int64) int64 {
	if a < 0 {
		a *= -1 // Negate if a is negative
	}
	return a // Return the absolute value
}
