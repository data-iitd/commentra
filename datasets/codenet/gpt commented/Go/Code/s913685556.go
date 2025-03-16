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
	// Read two integers from input
	A, B := sc.NextInt(), sc.NextInt()

	// Calculate the maximum of A+B, A-B, and A*B
	mx := max(A+B, A-B)
	mx = max(mx, A*B)
	// Print the maximum value
	fmt.Println(mx)
}

// Function to return the maximum of two integers
func max(a int, b int) int {
	if a < b {
		return b
	}
	return a
}

// Scanner struct to handle input reading
type Scanner struct {
	r   *bufio.Reader // Buffered reader for input
	buf []byte        // Buffer to hold the input data
	p   int           // Current position in the buffer
}

// NewScanner initializes and returns a new Scanner
func NewScanner() *Scanner {
	rdr := bufio.NewReaderSize(os.Stdin, 1000) // Create a new buffered reader with a size of 1000 bytes
	return &Scanner{r: rdr} // Return a new Scanner instance
}

// Next reads the next token from the input
func (s *Scanner) Next() string {
	s.pre() // Ensure there is data to read
	start := s.p // Mark the start of the token
	// Iterate through the buffer to find the next space
	for ; s.p < len(s.buf); s.p++ {
		if s.buf[s.p] == ' ' {
			break
		}
	}
	result := string(s.buf[start:s.p]) // Extract the token from the buffer
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
	return v // Return the int64 value
}

// NextFloat reads the next float64 from the input
func (s *Scanner) NextFloat() float64 {
	v, _ := strconv.ParseFloat(s.Next(), 64) // Convert the next token to float64
	return v // Return the float64 value
}

// NextIntArray reads a space-separated array of integers from the input
func (s *Scanner) NextIntArray() []int {
	s.pre() // Ensure there is data to read
	start := s.p // Mark the start of the array
	result := []int{} // Initialize an empty slice to hold the integers
	// Iterate through the buffer to read integers
	for ; s.p < len(s.buf)+1; s.p++ {
		if s.p == len(s.buf) || s.buf[s.p] == ' ' {
			v, _ := strconv.ParseInt(string(s.buf[start:s.p]), 10, 0) // Parse the integer
			result = append(result, int(v)) // Append the integer to the result slice
			start = s.p + 1 // Update the start position for the next integer
		}
	}
	return result // Return the slice of integers
}

// NextInt64Array reads a space-separated array of int64 from the input
func (s *Scanner) NextInt64Array() []int64 {
	s.pre() // Ensure there is data to read
	start := s.p // Mark the start of the array
	result := []int64{} // Initialize an empty slice to hold the int64 values
	// Iterate through the buffer to read int64 values
	for ; s.p < len(s.buf)+1; s.p++ {
		if s.p == len(s.buf) || s.buf[s.p] == ' ' {
			v, _ := strconv.ParseInt(string(s.buf[start:s.p]), 10, 64) // Parse the int64
			result = append(result, v) // Append the int64 to the result slice
			start = s.p + 1 // Update the start position for the next int64
		}
	}
	return result // Return the slice of int64 values
}

// NextMap reads a space-separated map of integers to booleans from the input
func (s *Scanner) NextMap() map[int]bool {
	s.pre() // Ensure there is data to read
	start := s.p // Mark the start of the map
	mp := map[int]bool{} // Initialize an empty map
	// Iterate through the buffer to read integers
	for ; s.p < len(s.buf); s.p++ {
		if s.buf[s.p] == ' ' {
			v, _ := strconv.Atoi(string(s.buf[start:s.p])) // Parse the integer
			mp[v] = true // Set the map entry to true
			start = s.p + 1 // Update the start position for the next integer
		}
	}
	v, _ := strconv.Atoi(string(s.buf[start:s.p])) // Parse the last integer
	mp[v] = true // Set the last map entry to true

	return mp // Return the map
}

// pre checks if more data needs to be read into the buffer
func (s *Scanner) pre() {
	if s.p >= len(s.buf) {
		s.readLine() // Read a new line if the current position is at the end of the buffer
		s.p = 0 // Reset the position to the start of the new buffer
	}
}

// readLine reads a full line from the input and stores it in the buffer
func (s *Scanner) readLine() {
	s.buf = make([]byte, 0) // Initialize the buffer
	for {
		l, p, e := s.r.ReadLine() // Read a line from the buffered reader
		if e != nil {
			panic(e) // Panic if there is an error
		}
		s.buf = append(s.buf, l...) // Append the line to the buffer
		if !p {
			break // Break if the line is complete
		}
	}
}
