package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a new scanner to read input
	sc := NewScanner()
	
	// Read three integers from input: H, W, and N
	H, W, N := sc.NextInt(), sc.NextInt(), sc.NextInt()

	// Calculate the maximum of H and W
	A := max(H, W)

	// Calculate and print the number of full groups needed to accommodate N items
	fmt.Println((N + A - 1) / A)
}

// Function to return the maximum of two integers
func max(a int, b int) int {
	if a < b {
		return b
	}
	return a
}

// Scanner struct to facilitate reading input
type Scanner struct {
	r   *bufio.Reader // Buffered reader for input
	buf []byte        // Buffer to hold the input data
	p   int           // Current position in the buffer
}

// NewScanner initializes a new Scanner instance
func NewScanner() *Scanner {
	rdr := bufio.NewReaderSize(os.Stdin, 1000) // Create a new buffered reader with a size of 1000 bytes
	return &Scanner{r: rdr}                      // Return a new Scanner with the reader
}

// Next reads the next token from the input
func (s *Scanner) Next() string {
	s.pre() // Ensure there is data to read
	start := s.p // Mark the start of the token
	for ; s.p < len(s.buf); s.p++ {
		if s.buf[s.p] == ' ' { // Stop at space character
			break
		}
	}
	result := string(s.buf[start:s.p]) // Extract the token
	s.p++ // Move past the space
	return result // Return the token
}

// NextLine reads the next line from the input
func (s *Scanner) NextLine() string {
	s.pre() // Ensure there is data to read
	start := s.p // Mark the start of the line
	s.p = len(s.buf) // Move to the end of the buffer
	return string(s.buf[start:]) // Return the line
}

// NextInt reads the next integer from the input
func (s *Scanner) NextInt() int {
	v, _ := strconv.Atoi(s.Next()) // Convert the next token to an integer
	return v // Return the integer
}

// NextInt64 reads the next int64 from the input
func (s *Scanner) NextInt64() int64 {
	v, _ := strconv.ParseInt(s.Next(), 10, 64) // Convert the next token to int64
	return v // Return the int64
}

// NextFloat reads the next float64 from the input
func (s *Scanner) NextFloat() float64 {
	v, _ := strconv.ParseFloat(s.Next(), 64) // Convert the next token to float64
	return v // Return the float64
}

// NextIntArray reads a slice of integers from the input
func (s *Scanner) NextIntArray() []int {
	s.pre() // Ensure there is data to read
	start := s.p // Mark the start of the array
	result := []int{} // Initialize an empty slice to hold the integers
	for ; s.p < len(s.buf)+1; s.p++ {
		if s.p == len(s.buf) || s.buf[s.p] == ' ' { // Check for end of buffer or space
			v, _ := strconv.ParseInt(string(s.buf[start:s.p]), 10, 0) // Parse the integer
			result = append(result, int(v)) // Append to the result slice
			start = s.p + 1 // Update start for the next integer
		}
	}
	return result // Return the slice of integers
}

// NextInt64Array reads a slice of int64 from the input
func (s *Scanner) NextInt64Array() []int64 {
	s.pre() // Ensure there is data to read
	start := s.p // Mark the start of the array
	result := []int64{} // Initialize an empty slice to hold the int64 values
	for ; s.p < len(s.buf)+1; s.p++ {
		if s.p == len(s.buf) || s.buf[s.p] == ' ' { // Check for end of buffer or space
			v, _ := strconv.ParseInt(string(s.buf[start:s.p]), 10, 64) // Parse the int64
			result = append(result, v) // Append to the result slice
			start = s.p + 1 // Update start for the next int64
		}
	}
	return result // Return the slice of int64
}

// NextMap reads a map of integers from the input
func (s *Scanner) NextMap() map[int]bool {
	s.pre() // Ensure there is data to read
	start := s.p // Mark the start of the map
	mp := map[int]bool{} // Initialize an empty map
	for ; s.p < len(s.buf); s.p++ {
		if s.buf[s.p] == ' ' { // Check for space
			v, _ := strconv.Atoi(string(s.buf[start:s.p])) // Parse the integer
			mp[v] = true // Add to the map
			start = s.p + 1 // Update start for the next integer
		}
	}
	v, _ := strconv.Atoi(string(s.buf[start:s.p])) // Parse the last integer
	mp[v] = true // Add the last integer to the map

	return mp // Return the map
}

// pre checks if there is data to read and reads a new line if necessary
func (s *Scanner) pre() {
	if s.p >= len(s.buf) { // If current position is at the end of the buffer
		s.readLine() // Read a new line
		s.p = 0 // Reset position to the start of the new line
	}
}

// readLine reads a full line from the input and stores it in the buffer
func (s *Scanner) readLine() {
	s.buf = make([]byte, 0) // Reset the buffer
	for {
		l, p, e := s.r.ReadLine() // Read a line from the buffered reader
		if e != nil {
			panic(e) // Panic if there is an error
		}
		s.buf = append(s.buf, l...) // Append the line to the buffer
		if !p { // If this is the last part of the line
			break // Exit the loop
		}
	}
}
