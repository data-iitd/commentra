package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

// bufReader struct to handle buffered reading from standard input
type bufReader struct {
	r   *bufio.Reader // Buffered reader
	buf []byte        // Buffer to hold read bytes
	i   int           // Current index in the buffer
}

// Initialize a global bufReader instance for reading input
var reader = &bufReader{
	bufio.NewReader(os.Stdin),
	make([]byte, 0),
	0,
}

// readLine reads a line from the buffered reader into the buffer
func (r *bufReader) readLine() {
	if r.i < len(r.buf) {
		return // Return if there are still bytes to read
	}
	r.buf = make([]byte, 0) // Reset buffer
	r.i = 0                 // Reset index
	for {
		line, isPrefix, err := r.r.ReadLine() // Read a line
		if err != nil {
			panic(err) // Panic on error
		}
		r.buf = append(r.buf, line...) // Append line to buffer
		if !isPrefix {
			break // Break if the line is not a prefix
		}
	}
}

// next reads the next token from the buffer
func (r *bufReader) next() string {
	r.readLine() // Ensure the buffer is filled
	from := r.i  // Store the starting index
	for ; r.i < len(r.buf); r.i++ {
		if r.buf[r.i] == ' ' { // Stop at space
			break
		}
	}
	s := string(r.buf[from:r.i]) // Extract the token
	r.i++                          // Move index forward
	return s
}

// nextLine reads the next full line from the buffer
func (r *bufReader) nextLine() string {
	r.readLine() // Ensure the buffer is filled
	s := string(r.buf[r.i:]) // Get the remaining line
	r.i = len(r.buf)          // Move index to the end of buffer
	return s
}

// Initialize a global writer for output
var writer = bufio.NewWriter(os.Stdout)

// next is a helper function to read the next token
func next() string {
	return reader.next()
}

// nextInt64 reads the next token as an int64
func nextInt64() int64 {
	i, err := strconv.ParseInt(reader.next(), 10, 64) // Parse token to int64
	if err != nil {
		panic(err) // Panic on error
	}
	return i
}

// nextInt reads the next token as an int
func nextInt() int {
	return int(nextInt64()) // Convert int64 to int
}

// nextLine is a helper function to read the next full line
func nextLine() string {
	return reader.nextLine()
}

// out writes the output to the writer
func out(a ...interface{}) {
	fmt.Fprintln(writer, a...) // Print to the writer
}

// max64 returns the maximum of two int64 values
func max64(x, y int64) int64 {
	if x > y {
		return x // Return x if it's greater
	}
	return y // Otherwise return y
}

// max returns the maximum of two int values
func max(x, y int) int {
	return int(max64(int64(x), int64(y))) // Convert int to int64 and find max
}

// min64 returns the minimum of two int64 values
func min64(x, y int64) int64 {
	if x < y {
		return x // Return x if it's lesser
	}
	return y // Otherwise return y
}

// min returns the minimum of two int values
func min(x, y int) int {
	return int(min64(int64(x), int64(y))) // Convert int to int64 and find min
}

// abs64 returns the absolute value of an int64
func abs64(x int64) int64 {
	if x < 0 {
		return -x // Return negation if x is negative
	}
	return x // Otherwise return x
}

// abs returns the absolute value of an int
func abs(x int) int {
	return int(abs64(int64(x))) // Convert int to int64 and find absolute
}

// joinInt64s joins a slice of int64s into a string with a separator
func joinInt64s(a []int64, sep string) string {
	b := make([]string, len(a)) // Create a string slice
	for i, v := range a {
		b[i] = strconv.FormatInt(v, 10) // Convert each int64 to string
	}
	return strings.Join(b, sep) // Join with separator
}

// joinInts joins a slice of ints into a string with a separator
func joinInts(a []int, sep string) string {
	b := make([]string, len(a)) // Create a string slice
	for i, v := range a {
		b[i] = strconv.Itoa(v) // Convert each int to string
	}
	return strings.Join(b, sep) // Join with separator
}

// divUp64 performs ceiling division on two int64 values
func divUp64(x, y int64) int64 {
	return (x + y - 1) / y // Ceiling division
}

// divUp performs ceiling division on two int values
func divUp(x, y int) int {
	return int(divUp64(int64(x), int64(y))) // Convert to int64 and perform division
}

// gcd64 computes the greatest common divisor of two int64 values
func gcd64(x, y int64) int64 {
	if x < y {
		x, y = y, x // Ensure x is the larger value
	}
	for y != 0 {
		x, y = y, x%y // Euclidean algorithm
	}
	return x // Return GCD
}

// gcd computes the greatest common divisor of two int values
func gcd(x, y int) int {
	return int(gcd64(int64(x), int64(y))) // Convert to int64 and find GCD
}

// lcm64 computes the least common multiple of two int64 values
func lcm64(x, y int64) int64 {
	return x * y / gcd64(x, y) // LCM using GCD
}

// lcm computes the least common multiple of two int values
func lcm(x, y int) int {
	return int(lcm64(int64(x), int64(y))) // Convert to int64 and find LCM
}

// pow64 computes x raised to the power of y for int64 values
func pow64(x, y int64) int64 {
	return int64(math.Pow(float64(x), float64(y))) // Use math.Pow for exponentiation
}

// pow computes x raised to the power of y for int values
func pow(x, y int) int {
	return int(pow64(int64(x), int64(y))) // Convert to int64 and find power
}

// main function to execute the program
func main() {
	solve() // Call the solve function
	writer.Flush() // Flush the writer to output results
}

// solve function to compute the maximum profit and count
func solve() {
	N, _ := nextInt(), nextInt() // Read number of elements and ignore the second value
	A := make([]int, N)           // Create a slice to hold the elements
	for i := 0; i < N; i++ {
		A[i] = nextInt() // Read each element into the slice
	}
	maxProfit := 0 // Initialize maximum profit
	maxCnt := 0    // Initialize count of maximum profit occurrences
	maxA := A[N-1] // Start with the last element as the maximum
	for i := N - 2; i >= 0; i-- { // Iterate backwards through the slice
		profit := max(0, maxA-A[i]) // Calculate profit based on the current element
		if maxProfit < profit { // If we found a new maximum profit
			maxProfit = profit // Update maximum profit
			maxCnt = 1         // Reset count to 1
		} else if maxProfit == profit { // If we found another occurrence of the maximum profit
			maxCnt++ // Increment the count
		}
		maxA = max(maxA, A[i]) // Update the maximum element seen so far
	}
	out(maxCnt) // Output the count of maximum profit occurrences
}
