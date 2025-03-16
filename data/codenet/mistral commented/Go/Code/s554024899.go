
package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
)

func main() {
	log.SetFlags(log.Lshortfile) // Set the logging flags to display the short file name and line number
	sc := newScanner()           // Initialize a new scanner object

	// Read the first two integers from the standard input using the scanner
	x := sc.nextInt()
	y := sc.nextInt()

	// Initialize two variables xt and yt to store the indices of the arrays a where x and y are present
	var xt, yt int

	// Define a 3x3 2D array a
	a := [3][]int{{1, 3, 5, 7, 8, 10, 12}, {4, 6, 9, 11}, {2}}

	// Iterate through each inner loop of the outer loop
	for i, t := range a {
		// Iterate through each element of the current inner loop
		for _, n := range t {
			// Check if the current element is equal to x, if yes, store its index in xt
			if x == n {
				xt = i
			}
			// Check if the current element is equal to y, if yes, store its index in yt
			if y == n {
				yt = i
			}
		}
	}

	// Check if the indices xt and yt are equal, if yes, print "Yes"
	if xt == yt {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// Helper function to find the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Define a scanner structure
type scanner struct {
	r   *bufio.Reader
	buf []byte
	p   int
}

// Initialize a new scanner object
func newScanner() *scanner {
	rdr := bufio.NewReaderSize(os.Stdin, 1000) // Initialize a new reader with a buffer size of 1000
	return &scanner{r: rdr}                       // Return a new scanner object
}

// Function to read a single word from the input
func (s *scanner) next() string {
	s.pre()
	start := s.p
	for ; s.p < len(s.buf); s.p++ {
		if s.buf[s.p] == ' ' {
			break
		}
	}
	result := string(s.buf[start:s.p])
	s.p++
	return result
}

// Function to read a line from the input
func (s *scanner) nextLine() string {
	s.pre()
	start := s.p
	s.p = len(s.buf)
	return string(s.buf[start:])
}

// Function to read an integer from the input
func (s *scanner) nextInt() int {
	v, _ := strconv.Atoi(s.next())
	return v
}

// Function to prepare the scanner for the next input
func (s *scanner) pre() {
	if s.p >= len(s.buf) {
		s.readLine()
		s.p = 0
	}
}

// Function to read a line from the input
func (s *scanner) readLine() {
	s.buf = make([]byte, 0)
	for {
		l, p, e := s.r.ReadLine()
		if e != nil {
			panic(e)
		}
		s.buf = append(s.buf, l...)
		if !p {
			break
		}
	}
}

