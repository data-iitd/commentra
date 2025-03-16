package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"sort"
)

func main() {
	// Initialize a new scanner to read input
	sc := NewScanner()

	// Read the number of elements
	n := sc.NextInt()
	// Create a slice to hold the float64 values
	arr := make([]float64, n)
	
	// Read n integers from input and convert them to float64
	for i := 0; i < n; i++ {
		arr[i] = float64(sc.NextInt())
	}
	
	// Sort the array of float64 values
	sort.Float64s(arr)

	// Initialize 'prev' with the first element of the sorted array
	prev := arr[0]
	
	// Calculate the average of the elements iteratively
	for i := 1; i < len(arr); i++ {
		prev = (prev + arr[i]) / 2
	}

	// Print the final computed average
	fmt.Printf("%v\n", prev)
}

// Scanner struct to handle input reading
type Scanner struct {
	r   *bufio.Reader // Buffered reader for input
	buf []byte        // Buffer to hold the input line
	p   int           // Current position in the buffer
}

// NewScanner initializes a new Scanner instance
func NewScanner() *Scanner {
	rdr := bufio.NewReaderSize(os.Stdin, 1000) // Create a new buffered reader with a size of 1000 bytes
	return &Scanner{r: rdr} // Return a new Scanner with the reader
}

// Next reads the next token from the input
func (s *Scanner) Next() string {
	s.pre() // Ensure the buffer is filled
	start := s.p // Mark the start of the token
	// Iterate through the buffer to find the next space
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
func (s *Scanner) NextLine() string {
	s.pre() // Ensure the buffer is filled
	start := s.p // Mark the start of the line
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
	s.pre() // Ensure the buffer is filled
	start := s.p // Mark the start of the first integer
	result := []int{} // Initialize an empty slice for the integers
	// Iterate through the buffer to find space-separated integers
	for ; s.p < len(s.buf); s.p++ {
		if s.buf[s.p] == ' ' {
			v, _ := strconv.Atoi(string(s.buf[start:s.p])) // Convert the token to an integer
			result = append(result, v) // Append the integer to the result slice
			start = s.p + 1 // Update the start position for the next integer
		}
	}
	v, _ := strconv.Atoi(string(s.buf[start:s.p])) // Convert the last token to an integer
	result = append(result, v) // Append the last integer to the result slice

	return result // Return the slice of integers
}

// NextMap reads a space-separated map of integers to booleans from the input
func (s *Scanner) NextMap() map[int]bool {
	s.pre() // Ensure the buffer is filled
	start := s.p // Mark the start of the first integer
	mp := map[int]bool{} // Initialize an empty map
	// Iterate through the buffer to find space-separated integers
	for ; s.p < len(s.buf); s.p++ {
		if s.buf[s.p] == ' ' {
			v, _ := strconv.Atoi(string(s.buf[start:s.p])) // Convert the token to an integer
			mp[v] = true // Set the integer as a key in the map with a value of true
			start = s.p + 1 // Update the start position for the next integer
		}
	}
	v, _ := strconv.Atoi(string(s.buf[start:s.p])) // Convert the last token to an integer
	mp[v] = true // Set the last integer as a key in the map

	return mp // Return the map of integers
}

// pre checks if the buffer needs to be filled
func (s *Scanner) pre() {
	if s.p >= len(s.buf) { // If the current position is at or beyond the buffer length
		s.readLine() // Read a new line into the buffer
		s.p = 0 // Reset the position to the start of the buffer
	}
}

// readLine reads a full line from the input into the buffer
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
