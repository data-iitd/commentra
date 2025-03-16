package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Main function where the execution starts
func main() {
	// Create a new scanner to read input
	sc := NewScanner()

	// Read the number of integers to process
	n := sc.NextInt()
	ans := 0.0

	// Loop through each integer, calculate the reciprocal, and accumulate the sum
	for i := 0; i < n; i++ {
		tmp := 1 / float64(sc.NextInt())
		ans += tmp
	}

	// Print the harmonic mean of the input integers
	fmt.Printf("%v\n", 1/ans)
}

// Scanner struct to handle input reading efficiently
type Scanner struct {
	r   *bufio.Reader // Buffered reader for input
	buf []byte        // Buffer to hold the input line
	p   int           // Current position in the buffer
}

// NewScanner initializes a new Scanner instance
func NewScanner() *Scanner {
	rdr := bufio.NewReaderSize(os.Stdin, 1000) // Create a buffered reader with a specified size
	return &Scanner{r: rdr} // Return a new Scanner with the reader
}

// Next reads the next token from the input
func (s *Scanner) Next() string {
	s.pre() // Ensure there is data to read
	start := s.p // Mark the start position
	// Iterate through the buffer to find the next space
	for ; s.p < len(s.buf); s.p++ {
		if s.buf[s.p] == ' ' {
			break // Stop at the first space
		}
	}
	result := string(s.buf[start:s.p]) // Extract the token
	s.p++ // Move past the space
	return result // Return the token
}

// NextLine reads the next full line from the input
func (s *Scanner) NextLine() string {
	s.pre() // Ensure there is data to read
	start := s.p // Mark the start position
	s.p = len(s.buf) // Move to the end of the buffer
	return string(s.buf[start:]) // Return the line
}

// NextInt reads the next integer from the input
func (s *Scanner) NextInt() int {
	v, _ := strconv.Atoi(s.Next()) // Convert the next token to an integer
	return v // Return the integer
}

// NextIntArray reads a space-separated array of integers from the input
func (s *Scanner) NextIntArray() []int {
	s.pre() // Ensure there is data to read
	start := s.p // Mark the start position
	result := []int{} // Initialize an empty slice for the results
	// Iterate through the buffer to find integers separated by spaces
	for ; s.p < len(s.buf); s.p++ {
		if s.buf[s.p] == ' ' {
			v, _ := strconv.Atoi(string(s.buf[start:s.p])) // Convert the token to an integer
			result = append(result, v) // Append the integer to the result slice
			start = s.p + 1 // Update the start position
		}
	}
	v, _ := strconv.Atoi(string(s.buf[start:s.p])) // Convert the last token to an integer
	result = append(result, v) // Append the last integer to the result slice

	return result // Return the slice of integers
}

// NextMap reads a space-separated list of integers into a map
func (s *Scanner) NextMap() map[int]bool {
	s.pre() // Ensure there is data to read
	start := s.p // Mark the start position
	mp := map[int]bool{} // Initialize an empty map
	// Iterate through the buffer to find integers separated by spaces
	for ; s.p < len(s.buf); s.p++ {
		if s.buf[s.p] == ' ' {
			v, _ := strconv.Atoi(string(s.buf[start:s.p])) // Convert the token to an integer
			mp[v] = true // Add the integer to the map
			start = s.p + 1 // Update the start position
		}
	}
	v, _ := strconv.Atoi(string(s.buf[start:s.p])) // Convert the last token to an integer
	mp[v] = true // Add the last integer to the map

	return mp // Return the map of integers
}

// pre checks if there is data to read and reads a new line if necessary
func (s *Scanner) pre() {
	if s.p >= len(s.buf) { // If the current position is at the end of the buffer
		s.readLine() // Read a new line
		s.p = 0 // Reset the position to the start of the new line
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
		if !p { // If the line is not a continuation
			break // Exit the loop
		}
	}
}
