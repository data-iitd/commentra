package main

import (
	"bufio"
	"fmt"
	"log"
	"math"
	"math/rand"
	"os"
	"strconv"
	"time"
)

// Direction vectors for 8 possible movements (up, down, left, right, and diagonals)
var dx = [...]int{0, 1, 1, 1, 0, -1, -1, -1, 0}
var dy = [...]int{1, 1, 0, -1, -1, -1, 0, 1, 0}

// Define an infinite value for comparison
var inf = math.MaxInt64

// Initialize a new scanner for input
var next = newScanner()

// ---------------------------------------------------------
// init function to set up logging and random seed
func init() {
	log.SetFlags(log.Lshortfile) // Set log flags to show file name and line number
	rand.Seed(time.Now().UnixNano()) // Seed the random number generator
}

// main function where the program execution starts
func main() {
	// Read input as a string
	N := next.String()
	b := []byte(N) // Convert string to byte slice
	n := 0 // Initialize sum of digits

	// Calculate the sum of digits in the input number
	for i := 0; i < len(b); i++ {
		n += int(b[i] - '0') // Convert byte to int and accumulate
	}

	// Convert the string input to an integer
	m, _ := strconv.Atoi(N)
	// Check if the number is divisible by the sum of its digits
	if m%n == 0 {
		fmt.Println("Yes") // Print "Yes" if divisible
	} else {
		fmt.Println("No") // Print "No" if not divisible
	}
}

// ---------------------------------------------------------

// Pair struct to hold a pair of integers
type Pair struct {
	a, b int
}

// Pairs is a slice of Pair structs
type Pairs []Pair

// Implement Len method for sorting
func (p Pairs) Len() int {
	return len(p)
}

// Implement Swap method for sorting
func (p Pairs) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}

// Implement Less method for sorting based on the second element of the Pair
func (p Pairs) Less(i, j int) bool {
	return p[i].b < p[j].b
}

// Utility functions for various operations

// Check if a value is within a range
func in(c, a, z int) bool {
	return c >= a && c < z
}

// Check if a value is outside a range
func out(c, a, z int) bool {
	return !in(c, a, z)
}

// Convert boolean to integer (1 for true, 0 for false)
func btoi(b bool) int {
	if b {
		return 1
	}
	return 0
}

// Convert integer to boolean (non-zero to true, zero to false)
func itob(a int) bool {
	return a != 0
}

// Return the maximum value from a list of integers
func max(a ...int) int {
	r := a[0]
	for i := 0; i < len(a); i++ {
		if r < a[i] {
			r = a[i]
		}
	}
	return r
}

// Return the minimum value from a list of integers
func min(a ...int) int {
	r := a[0]
	for i := 0; i < len(a); i++ {
		if r > a[i] {
			r = a[i]
		}
	}
	return r
}

// Calculate the sum of a slice of integers
func sum(a []int) (r int) {
	for i := range a {
		r += a[i]
	}
	return r
}

// Calculate the product of a slice of integers
func pro(a []int) int {
	r := a[0]
	for i := 1; i < len(a); i++ {
		r *= a[i]
	}
	return r
}

// Fill a slice with a specified value
func fill(a []int, n int) []int {
	for i := range a {
		a[i] = n
	}
	return a
}

// Return the minimum and maximum of two integers
func minmax(a, b int) (int, int) {
	if a > b {
		return b, a
	}
	return a, b
}

// Return the absolute value of an integer
func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

// Calculate the ceiling of a division of two integers
func ceil(a, b int) int {
	if a%b != 0 {
		return 1
	}
	return 0
}

// Print a slice of strings with space separation
func printStrings(out []string) {
	for i := range out {
		fmt.Print(out[i])
		if i != len(out)-1 {
			fmt.Print(" ")
		}
	}
	fmt.Print("\n")
}

// Print a slice of integers with space separation
func printInts(out []int) {
	for i := range out {
		fmt.Print(out[i])
		if i != len(out)-1 {
			fmt.Print(" ")
		}
	}
	fmt.Print("\n")
}

// ---------- buffered scanner -----------------------------------------

// scanner struct for buffered input reading
type scanner struct {
	r   *bufio.Reader // Buffered reader
	buf []byte        // Buffer to hold input
	p   int           // Current position in the buffer
}

// Create a new scanner instance
func newScanner() *scanner {
	rdr := bufio.NewReaderSize(os.Stdin, 10000) // Initialize with a buffer size
	return &scanner{r: rdr}
}

// Read the next token from the input
func (s *scanner) next() string {
	s.pre() // Ensure the buffer is filled
	start := s.p // Mark the start of the token
	for ; s.p < len(s.buf); s.p++ {
		if s.buf[s.p] == ' ' { // Stop at space
			break
		}
	}
	result := string(s.buf[start:s.p]) // Extract the token
	s.p++ // Move past the space
	return result
}

// Read the entire line from the input
func (s *scanner) Line() string {
	s.pre() // Ensure the buffer is filled
	start := s.p // Mark the start of the line
	s.p = len(s.buf) // Move to the end of the buffer
	return string(s.buf[start:]) // Return the line
}

// Read the next string from the input
func (s *scanner) String() string {
	return s.next() // Call next to get the next token
}

// Read the next integer from the input
func (s *scanner) Int() int {
	v, err := strconv.Atoi(s.next()) // Convert the next token to an integer
	if err != nil {
		log.Fatal(err) // Log error if conversion fails
	}
	return v // Return the integer
}

// Read multiple integers from the input
func (s *scanner) Ints(n int) []int {
	r := make([]int, n) // Create a slice to hold the integers
	for i := 0; i < n; i++ {
		r[i] = s.Int() // Read each integer
	}
	return r // Return the slice of integers
}

// Read the next int64 from the input
func (s *scanner) Int64() int64 {
	v, err := strconv.ParseInt(s.next(), 10, 64) // Convert the next token to int64
	if err != nil {
		log.Fatal(err) // Log error if conversion fails
	}
	return v // Return the int64
}

// Read the next uint64 from the input
func (s *scanner) Uint64() uint64 {
	v, err := strconv.ParseUint(s.next(), 10, 64) // Convert the next token to uint64
	if err != nil {
		log.Fatal(err) // Log error if conversion fails
	}
	return v // Return the uint64
}

// Read the next float64 from the input
func (s *scanner) Float64() float64 {
	v, err := strconv.ParseFloat(s.next(), 64) // Convert the next token to float64
	if err != nil {
		log.Fatal(err) // Log error if conversion fails
	}
	return v // Return the float64
}

// Pre-read to ensure there is data in the buffer
func (s *scanner) pre() {
	if s.p >= len(s.buf) { // If current position is at the end of the buffer
		s.readLine() // Read a new line
		s.p = 0 // Reset position to the start of the new buffer
	}
}

// Read a line from the input and fill the buffer
func (s *scanner) readLine() {
	s.buf = make([]byte, 0) // Reset the buffer
	for {
		l, p, err := s.r.ReadLine() // Read a line
		if err != nil {
			log.Fatal(err) // Log error if reading fails
		}
		s.buf = append(s.buf, l...) // Append line to buffer
		if !p { // If the line is complete
			break
		}
	}
}
