// Package main is the entry point of the program
package main

import (
	"bufio" // Import bufio package for reading input
	"fmt"   // Import fmt package for printing output
	"log"   // Import log package for error handling
	"math"  // Import math package for mathematical operations
	"math/rand" // Import math/rand package for random number generation
	"os"    // Import os package for interacting with the operating system
	"strconv" // Import strconv package for converting strings to numbers
	"time"   // Import time package for time-related functions
)

// Constants and variables declaration
const inf = math.MaxInt64 // Constants for maximum signed integer value

// var mod = 1000000007 // Unused constant, can be removed

var dx = [...]int{0, 1, 1, 1, 0, -1, -1, -1, 0} // 8 directions for movement
var dy = [...]int{1, 1, 0, -1, -1, -1, 0, 1, 0}

// Global variables declaration
var next Scanner // Global scanner for reading input

// ---------------------------------------------------------

// init function initializes the program
func init() {
	log.SetFlags(log.Lshortfile) // Set log flags for short file names
	rand.Seed(time.Now().UnixNano()) // Seed random number generator with current time
}

// main function is the entry point of the program
func main() {
	// Read input N as a string
	N := next.String()
	// Convert N to an integer
	b := []byte(N)
	n := 0
	// Iterate through each digit in the number N
	for i := 0; i < len(b); i++ {
		n += int(b[i] - '0') // Convert each digit to an integer and add to the sum
	}
	// Read input m as an integer
	m, _ := strconv.Atoi(N)
	// Check if m is divisible by n
	if m%n == 0 {
		fmt.Println("Yes") // Print "Yes" if m is divisible by n
	} else {
		fmt.Println("No") // Print "No" if m is not divisible by n
	}
}

// ---------------------------------------------------------

// Pair type definition for storing two integers
type Pair struct {
	a, b int
}

// Pairs type definition for storing a slice of Pair
type Pairs []Pair

// Implement Len, Swap, and Less methods for sorting Pairs based on the second element
func (p Pairs) Len() int {
	return len(p)
}
func (p Pairs) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}
func (p Pairs) Less(i, j int) bool {
	return p[i].b < p[i].b // Sort based on the second element
}

// ------int methods-------------------------
func in(c, a, z int) bool {
	return c >= a && c < z // Check if c is within the range [a, z)
}
func out(c, a, z int) bool {
	return !in(c, a, z) // Check if c is outside the range [a, z)
}
func btoi(b bool) int {
	if b {
		return 1 // Convert boolean to integer: 1 for true, 0 for false
	}
	return 0
}
func itob(a int) bool {
	return a != 0 // Convert integer to boolean: true for non-zero, false for zero
}
func max(a ...int) int {
	r := a[0]
	for i := 0; i < len(a); i++ {
		if r < a[i] {
			r = a[i] // Find the maximum integer among the given integers
		}
	}
	return r
}
func min(a ...int) int {
	r := a[0]
	for i := 0; i < len(a); i++ {
		if r > a[i] {
			r = a[i] // Find the minimum integer among the given integers
		}
	}
	return r
}
func sum(a []int) (r int) {
	for i := range a {
		r += a[i] // Calculate the sum of all integers in the given slice
	}
	return r
}
func pro(a []int) int {
	r := a[0]
	for i := 1; i < len(a); i++ {
		r *= a[i] // Calculate the product of all integers in the given slice
	}
	return r
}

func fill(a []int, n int) []int {
	for i := range a {
		a[i] = n // Fill the given slice with the given integer value
	}
	return a
}
func minmax(a, b int) (int, int) {
	if a > b {
		return b, a // Return the minimum and maximum integers among the given integers
	}
	return a, b
}

func abs(a int) int {
	if a < 0 {
		return -a // Calculate the absolute value of an integer
	}
	return a
}

// ---------- buffered scanner -----------------------------------------
type scanner struct {
	r   *bufio.Reader // bufio.Reader for reading input
	buf []byte        // Buffer for storing the input line
	p   int           // Position in the buffer
}

func newScanner() *scanner {
	rdr := bufio.NewReaderSize(os.Stdin, 10000) // Initialize a new bufio.Reader with a buffer size of 10000
	return &scanner{r: rdr}                       // Return a new scanner instance
}
func (s *scanner) next() string {
	s.pre()
	start := s.p
	for ; s.p < len(s.buf); s.p++ {
		if s.buf[s.p] == ' ' {
			break // Find the position of the next whitespace character
		}
	}
	result := string(s.buf[start:s.p]) // Extract the substring from the buffer
	s.p++                              // Increment the position in the buffer
	return result
}
func (s *scanner) Line() string {
	s.pre()
	start := s.p
	s.p = len(s.buf)
	result := string(s.buf[start:]) // Extract the rest of the line as a string
	return result
}
func (s *scanner) String() string {
	return s.next() // Call next() method to read the next token as a string
}
func (s *scanner) Int() int {
	v, err := strconv.Atoi(s.next()) // Convert the next token to an integer
	if err != nil {
		log.Fatal(err) // Log an error and exit the program if the conversion fails
	}
	return v
}
func (s *scanner) Ints(n int) []int {
	r := make([]int, n) // Initialize an empty slice of integers with the given size
	for i := 0; i < n; i++ {
		r[i] = s.Int() // Read and store n integers in the slice
	}
	return r
}
func (s *scanner) Int64() int64 {
	v, err := strconv.ParseInt(s.next(), 10, 64)
	if err != nil {
		log.Fatal(err)
	}
	return v
}
func (s *scanner) Uint64() uint64 {
	v, err := strconv.ParseUint(s.next(), 10, 64)
	if err != nil {
		log.Fatal(err)
	}
	return v
}
func (s *scanner) Float64() float64 {
	v, err := strconv.ParseFloat(s.next(), 64)
	if err != nil {
		log.Fatal(err)
	}
	return v
}
func (s *scanner) pre() {
	if s.p >= len(s.buf) {
		s.readLine() // Read a new line if the buffer is empty
		s.p = 0
	}
}
func (s *scanner) readLine() {
	s.buf = make([]byte, 0) // Clear the buffer
	for {
		l, p, err := s.r.ReadLine()
		if err != nil {
			log.Fatal(err) // Log an error and exit the program if an error occurs during reading
		}
		s.buf = append(s.buf, l...) // Append the read line to the buffer
		if !p {
			break // Exit the loop if the end of the input is reached
		}
	}
}