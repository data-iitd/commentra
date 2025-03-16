package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
)

func main() {
	// Set log flags to show the file name and line number for log messages
	log.SetFlags(log.Lshortfile)

	// Initialize a new scanner to read input
	sc := newScanner()

	// Read two integers from input
	x := sc.nextInt()
	y := sc.nextInt()

	// Initialize variables to store the category indices of x and y
	var xt, yt int

	// Define a 2D array where each sub-array represents a category of numbers
	a := [3][]int{{1, 3, 5, 7, 8, 10, 12}, {4, 6, 9, 11}, {2}}

	// Iterate through the categories to find the indices of x and y
	for i, t := range a {
		for _, n := range t {
			// Check if the current number matches x
			if x == n {
				xt = i // Store the category index for x
			}
			// Check if the current number matches y
			if y == n {
				yt = i // Store the category index for y
			}
		}
	}

	// Compare the category indices of x and y and print the result
	if xt == yt {
		fmt.Println("Yes") // x and y belong to the same category
	} else {
		fmt.Println("No")  // x and y belong to different categories
	}
}

// max returns the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// scanner struct to handle buffered input reading
type scanner struct {
	r   *bufio.Reader // Buffered reader
	buf []byte        // Buffer to hold read data
	p   int           // Current position in the buffer
}

// newScanner initializes a new scanner with a specified buffer size
func newScanner() *scanner {
	rdr := bufio.NewReaderSize(os.Stdin, 1000) // Create a new buffered reader
	return &scanner{r: rdr}                     // Return a new scanner instance
}

// next reads the next token from the input
func (s *scanner) next() string {
	s.pre() // Ensure there's data to read
	start := s.p // Mark the start position
	for ; s.p < len(s.buf); s.p++ {
		if s.buf[s.p] == ' ' { // Stop at space
			break
		}
	}
	result := string(s.buf[start:s.p]) // Extract the token
	s.p++ // Move past the space
	return result // Return the token
}

// nextLine reads the next line from the input
func (s *scanner) nextLine() string {
	s.pre() // Ensure there's data to read
	start := s.p // Mark the start position
	s.p = len(s.buf) // Move to the end of the buffer
	return string(s.buf[start:]) // Return the line
}

// nextInt reads the next integer from the input
func (s *scanner) nextInt() int {
	v, _ := strconv.Atoi(s.next()) // Convert the next token to an integer
	return v // Return the integer
}

// pre checks if more data needs to be read into the buffer
func (s *scanner) pre() {
	if s.p >= len(s.buf) { // If the current position is at or beyond the buffer length
		s.readLine() // Read a new line into the buffer
		s.p = 0 // Reset the position to the start of the buffer
	}
}

// readLine reads a full line from the input into the buffer
func (s *scanner) readLine() {
	s.buf = make([]byte, 0) // Clear the buffer
	for {
		l, p, e := s.r.ReadLine() // Read a line
		if e != nil {
			panic(e) // Panic on error
		}
		s.buf = append(s.buf, l...) // Append the line to the buffer
		if !p { // If the line is not continued
			break // Exit the loop
		}
	}
}
