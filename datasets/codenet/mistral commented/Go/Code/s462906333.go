// Importing necessary packages
package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
)

// Constants and variables declaration
const inf int = 1e14

// var mod = 1000000007

// Function to read input from standard input using buffered scanner
type scanner struct {
	r   *bufio.Reader
	buf []byte
	p   int
}

// Creating a new scanner object
func newScanner() *scanner {
	rdr := bufio.NewReaderSize(os.Stdin, 10000)
	return &scanner{r: rdr}
}

// Function to read next token from input
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

// Function to read a complete line from input
func (s *scanner) Line() string {
	s.pre()
	start := s.p
	s.p = len(s.buf)
	return string(s.buf[start:])
}

// Function to read an integer from input
func (s *scanner) Int() int {
	v, _ := strconv.Atoi(s.next())
	return v
}

// Function to read an integer64 from input
func (s *scanner) Int64() int64 {
	v, _ := strconv.ParseInt(s.next(), 10, 64)
	return v
}

// Function to set the position of the reader to the beginning of the buffer
func (s *scanner) pre() {
	if s.p >= len(s.buf) {
		s.readLine()
		s.p = 0
	}
}

// Function to read a complete line from input and store it in the buffer
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

// Main function
func main() {
	// Setting up logging
	log.SetFlags(log.Lshortfile)

	// Creating a new scanner object
	next := newScanner()

	// Reading input
	n := next.Int()
	x := next.Int()

	// Initializing arrays
	a := make([]int, n)
	v := make([]int, n)
	copy(v, a)

	// Initializing answer variable
	ans := inf

	// Iterating through all possible subarrays
	for k := 0; k < n; k++ {
		// Initializing variable to store sum of subarray elements
		kans := 0

		// Iterating through all elements of the subarray
		for i := 0; i < n; i++ {
			// Checking if current index is out of bounds for subarray
			if i-k < 0 {
				// Updating current element in subarray with minimum of itself and corresponding element from the main array
				v[i] = min(v[i], a[n+i-k])
			} else {
				// Updating current element in subarray with minimum of itself and previous element in subarray
				v[i] = min(v[i], a[i-k])
			}

			// Adding current element to the sum of subarray
			kans += v[i]
		}

		// Updating answer with minimum of current answer and sum of subarray and multiplication of its size and x
		ans = min(ans, kans+k*x)
	}

	// Printing the answer
	fmt.Println(ans)
}

// Helper functions
func min(a ...int) int {
	r := a[0]
	for i := 0; i < len(a); i++ {
		if r > a[i] {
			r = a[i]
		}
	}
	return r
}

// -------------------------------
// Function to check if a given number is inside a given range
func in(c, a, z int) bool {
	return c >= a && c < z
}

// Function to convert boolean value to integer
func btoi(b bool) int {
	if b {
		return 1
	}
	return 0
}

// Function to convert integer value to boolean
func itob(a int) bool {
	if a == 0 {
		return false
	}
	return true
}
