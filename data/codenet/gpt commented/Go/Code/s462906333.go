package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
)

// Define a large constant for infinity
var inf int = 1e14

// ---------------------------------------------------------
func main() {
	// Set log flags to show the file name and line number
	log.SetFlags(log.Lshortfile)

	// Initialize a new scanner for input
	next := newScanner()

	// Read the number of elements and the value of x
	n := next.Int()
	x := next.Int()

	// Create a slice to hold the input integers
	a := make([]int, n)

	// Read n integers into the slice a
	for i := 0; i < n; i++ {
		a[i] = next.Int()
	}

	// Create a copy of the slice a for manipulation
	v := make([]int, n)
	copy(v, a)

	// Initialize the answer to infinity
	ans := inf

	// Iterate over each possible k value
	for k := 0; k < n; k++ {
		kans := 0 // Initialize the current answer for this k

		// Calculate the minimum values for the current k
		for i := 0; i < n; i++ {
			if i-k < 0 {
				// If i-k is out of bounds, use the wrapped index
				v[i] = min(v[i], a[n+i-k])
			} else {
				// Otherwise, use the normal index
				v[i] = min(v[i], a[i-k])
			}
			// Accumulate the current answer
			kans += v[i]
		}

		// Update the overall answer with the minimum found so far
		ans = min(ans, kans+k*x)
	}

	// Print the final answer
	fmt.Println(ans)
}

// ---------------------------------------------------------

// Pair represents a pair of integers
type Pair struct {
	a, b int
}

// Pairs is a slice of Pair structs that can be sorted
type Pairs []Pair

// Implement the sort.Interface for Pairs
func (p Pairs) Len() int {
	return len(p)
}
func (p Pairs) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}
func (p Pairs) Less(i, j int) bool {
	// Define sorting criteria based on the first and second elements of the pairs
	if p[i].a < p[j].a {
		return true
	} else if p[i].a == p[j].a {
		return p[i].b < p[j].b
	}
	return false
}

// -------------------------------

// in checks if c is within the range [a, z)
func in(c, a, z int) bool {
	return c >= a && c < z
}

// btoi converts a boolean to an integer (1 for true, 0 for false)
func btoi(b bool) int {
	if b {
		return 1
	}
	return 0
}

// itob converts an integer to a boolean (false for 0, true for non-zero)
func itob(a int) bool {
	if a == 0 {
		return false
	}
	return true
}

// max returns the maximum value from a list of integers
func max(a ...int) int {
	r := a[0]
	for i := 0; i < len(a); i++ {
		if r < a[i] {
			r = a[i]
		}
	}
	return r
}

// min returns the minimum value from a list of integers
func min(a ...int) int {
	r := a[0]
	for i := 0; i < len(a); i++ {
		if r > a[i] {
			r = a[i]
		}
	}
	return r
}

// minmax returns the minimum and maximum of two integers
func minmax(a, b int) (int, int) {
	if a > b {
		return b, a
	}
	return a, b
}

// abs returns the absolute value of an integer
func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

// sum returns the sum of a list of integers
func sum(a ...int) int {
	r := a[0]
	if len(a) > 1 {
		for i := 1; i < len(a); i++ {
			r += a[i]
		}
	}
	return r
}

// ---------- buffered scanner -----------------------------------------

// scanner is a custom buffered scanner for reading input
type scanner struct {
	r   *bufio.Reader // Buffered reader
	buf []byte        // Buffer to hold read data
	p   int           // Current position in the buffer
}

// newScanner initializes a new scanner with a specified buffer size
func newScanner() *scanner {
	rdr := bufio.NewReaderSize(os.Stdin, 10000)
	return &scanner{r: rdr}
}

// next reads the next token from the input
func (s *scanner) next() string {
	s.pre() // Ensure the buffer is filled
	start := s.p
	for ; s.p < len(s.buf); s.p++ {
		if s.buf[s.p] == ' ' {
			break
		}
	}
	result := string(s.buf[start:s.p])
	s.p++ // Move past the space
	return result
}

// Line reads the remainder of the current line
func (s *scanner) Line() string {
	s.pre() // Ensure the buffer is filled
	start := s.p
	s.p = len(s.buf) // Move to the end of the buffer
	return string(s.buf[start:])
}

// Int reads the next integer from the input
func (s *scanner) Int() int {
	v, _ := strconv.Atoi(s.next())
	return v
}

// Int64 reads the next int64 from the input
func (s *scanner) Int64() int64 {
	v, _ := strconv.ParseInt(s.next(), 10, 64)
	return v
}

// pre fills the buffer if the current position is at the end
func (s *scanner) pre() {
	if s.p >= len(s.buf) {
		s.readLine() // Read a new line into the buffer
		s.p = 0     // Reset the position to the start of the buffer
	}
}

// readLine reads a line from the input into the buffer
func (s *scanner) readLine() {
	s.buf = make([]byte, 0) // Clear the buffer
	for {
		l, p, e := s.r.ReadLine() // Read a line
		if e != nil {
			panic(e) // Handle any read errors
		}
		s.buf = append(s.buf, l...) // Append the line to the buffer
		if !p {
			break // Exit if the line is complete
		}
	}
}
