package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// bufReader struct to handle buffered reading from standard input
type bufReader struct {
	r   *bufio.Reader // Buffered reader
	buf []byte        // Buffer to hold the read data
	i   int           // Current index in the buffer
}

// Initialize a global bufReader instance for reading input
var reader = &bufReader{
	bufio.NewReader(os.Stdin), // Create a new buffered reader from standard input
	make([]byte, 0),           // Initialize an empty buffer
	0,                          // Start index at 0
}

// readLine reads a line from the buffered reader into the buffer
func (r *bufReader) readLine() {
	// If the current index is less than the buffer length, return (buffer already filled)
	if r.i < len(r.buf) {
		return
	}
	r.buf = make([]byte, 0) // Reset the buffer
	r.i = 0                 // Reset the index
	for {
		// Read a line from the reader
		line, isPrefix, err := r.r.ReadLine()
		if err != nil {
			panic(err) // Panic if there is an error
		}
		r.buf = append(r.buf, line...) // Append the line to the buffer
		if !isPrefix { // If the line is not a prefix, break the loop
			break
		}
	}
}

// next retrieves the next token from the buffer
func (r *bufReader) next() string {
	r.readLine() // Ensure the buffer is filled
	from := r.i  // Store the starting index of the token
	// Iterate through the buffer until a space is found
	for ; r.i < len(r.buf); r.i++ {
		if r.buf[r.i] == ' ' {
			break // Break on space
		}
	}
	s := string(r.buf[from:r.i]) // Extract the token from the buffer
	r.i++                          // Move the index forward
	return s                       // Return the token
}

// nextLine retrieves the next line from the buffer
func (r *bufReader) nextLine() string {
	r.readLine() // Ensure the buffer is filled
	s := string(r.buf[r.i:]) // Get the remaining part of the buffer as a string
	r.i = len(r.buf)         // Set index to the end of the buffer
	return s                 // Return the line
}

// Initialize a global buffered writer for output
var writer = bufio.NewWriter(os.Stdout)

// next is a wrapper to get the next token as a string
func next() string {
	return reader.next() // Call the next method of bufReader
}

// nextInt retrieves the next token and converts it to an int64
func nextInt() int64 {
	i, err := strconv.ParseInt(reader.next(), 10, 64) // Parse the next token as int64
	if err != nil {
		panic(err) // Panic if there is an error in parsing
	}
	return i // Return the parsed integer
}

// nextLine is a wrapper to get the next line as a string
func nextLine() string {
	return reader.nextLine() // Call the nextLine method of bufReader
}

// out prints the output to the buffered writer
func out(a ...interface{}) {
	fmt.Fprintln(writer, a...) // Print the arguments to the writer
}

// max returns the maximum of two int64 values
func max(x, y int64) int64 {
	if x > y {
		return x // Return x if it is greater
	}
	return y // Otherwise return y
}

// min returns the minimum of two int64 values
func min(x, y int64) int64 {
	if x < y {
		return x // Return x if it is lesser
	}
	return y // Otherwise return y
}

// joinInts converts a slice of int64 to a string with a separator
func joinInts(a []int64, sep string) string {
	b := make([]string, len(a)) // Create a string slice to hold the converted integers
	for i, v := range a {
		b[i] = strconv.FormatInt(v, 10) // Convert each int64 to string
	}
	return strings.Join(b, sep) // Join the strings with the specified separator
}

// divUp performs ceiling division of x by y
func divUp(x, y int64) int64 {
	return (x + y - 1) / y // Return the result of ceiling division
}

// main function where the program execution starts
func main() {
	solve() // Call the solve function to execute the main logic
	writer.Flush() // Flush the buffered writer to output
}

// solve contains the main logic for processing input and producing output
func solve() {
	N := nextInt() // Read the number of pairs
	T, A := make([]int64, N), make([]int64, N) // Initialize slices for T and A
	// Read pairs of integers into T and A
	for i := 0; i < int(N); i++ {
		T[i], A[i] = nextInt(), nextInt() // Read each pair
	}
	t, a := T[0], A[0] // Initialize t and a with the first pair
	// Iterate through the remaining pairs to compute the required values
	for i := 1; i < int(N); i++ {
		r := max(divUp(t, T[i]), divUp(a, A[i])) // Calculate the required multiplier
		t, a = T[i]*r, A[i]*r // Update t and a based on the multiplier
	}
	out(t + a) // Output the final result
}
