package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new scanner to read input
	sc := newScanner()
	
	// Read a string from the input
	S := sc.next()
	
	// Check if the string starts with "YAKI" and print the corresponding response
	if strings.HasPrefix(S, "YAKI") {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// min returns the smaller of two integers
func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

// max returns the larger of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// scanner struct to handle buffered input reading
type scanner struct {
	r   *bufio.Reader // Buffered reader
	buf []byte        // Buffer to hold the input data
	p   int           // Current position in the buffer
}

// newScanner initializes a new scanner with a specified buffer size
func newScanner() *scanner {
	rdr := bufio.NewReaderSize(os.Stdin, 1000) // Create a new buffered reader
	return &scanner{r: rdr}                     // Return a new scanner instance
}

// next reads the next word from the input
func (s *scanner) next() string {
	s.pre() // Ensure the buffer is filled
	start := s.p // Mark the start of the word
	// Iterate through the buffer until a space is found
	for ; s.p < len(s.buf); s.p++ {
		if s.buf[s.p] == ' ' {
			break
		}
	}
	result := string(s.buf[start:s.p]) // Extract the word
	s.p++ // Move past the space
	return result // Return the word
}

// nextLine reads the next line from the input
func (s *scanner) nextLine() string {
	s.pre() // Ensure the buffer is filled
	start := s.p // Mark the start of the line
	s.p = len(s.buf) // Move to the end of the buffer
	return string(s.buf[start:]) // Return the line
}

// nextInt reads the next integer from the input
func (s *scanner) nextInt() int {
	v, _ := strconv.Atoi(s.next()) // Convert the next word to an integer
	return v // Return the integer
}

// nextIntArray reads a space-separated array of integers from the input
func (s *scanner) nextIntArray() []int {
	s.pre() // Ensure the buffer is filled
	start := s.p // Mark the start of the array
	result := []int{} // Initialize an empty slice for the results
	// Iterate through the buffer to extract integers
	for ; s.p < len(s.buf)+1; s.p++ {
		if s.p == len(s.buf) || s.buf[s.p] == ' ' {
			v, _ := strconv.ParseInt(string(s.buf[start:s.p]), 10, 0) // Parse the integer
			result = append(result, int(v)) // Append the integer to the result slice
			start = s.p + 1 // Update the start position for the next integer
		}
	}
	return result // Return the slice of integers
}

// pre checks if the buffer needs to be filled
func (s *scanner) pre() {
	if s.p >= len(s.buf) { // If the current position is at or beyond the buffer length
		s.readLine() // Read a new line into the buffer
		s.p = 0 // Reset the position to the start of the buffer
	}
}

// readLine reads a line from the input and fills the buffer
func (s *scanner) readLine() {
	s.buf = make([]byte, 0) // Reset the buffer
	for {
		l, p, e := s.r.ReadLine() // Read a line from the buffered reader
		if e != nil {
			panic(e) // Handle any read errors
		}
		s.buf = append(s.buf, l...) // Append the line to the buffer
		if !p { // If the line is complete
			break // Exit the loop
		}
	}
}
