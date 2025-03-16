package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

// Define a constant for the buffer size used in input and output operations
const BUFFERSIZE = 512000

// Initialize a Scanner for reading input with a buffered reader for efficiency
var sc = bufio.NewScanner(os.Stdin)

// Initialize a PrintWriter for output with a buffered output stream for efficiency
var out = bufio.NewWriter(os.Stdout)

// Method to solve the main problem
func solve() {
	// Read the position from input
	position, _ := strconv.ParseInt(sc.Text(), 10, 64)

	// Initialize the nearest sequence start index
	nrstSeqStartIndx := int64(1)

	// Find the nearest sequence start index such that its value is less than the position
	for getValueAtIndex(nrstSeqStartIndx*2) < position {
		nrstSeqStartIndx *= 2
	}

	// Increment the nearest sequence start index until its value exceeds the position
	for getValueAtIndex(nrstSeqStartIndx+1) <= position {
		nrstSeqStartIndx++
	}

	// Get the starting index value for the nearest sequence
	startIndex := getValueAtIndex(nrstSeqStartIndx)

	// Output the result, which is the difference between the position and the start index plus one
	fmt.Fprintln(out, (position-startIndex)+1)
}

// Method to calculate the value at a given index based on a specific formula
func getValueAtIndex(index int64) int64 {
	return 1 + ((index-1)*index)/2
}

// Main method to execute the program
func main() {
	// Initialize the input reader
	in.Init(os.Stdin)

	// Call the solve method to process the input and produce output
	solve()

	// Close the output stream
	out.Flush()
}

// Static inner class for handling input operations
type in struct {
	reader *bufio.Reader
	tokenizer *strings.Reader
}

// Method to initialize the input reader
func (in *in) Init(input io.Reader) {
	in.reader = bufio.NewReader(input)
	in.tokenizer = strings.NewReader("")
}

// Method to get the next token from input
func (in *in) Next() string {
	// Ensure there are tokens available to read
	for !in.tokenizer.Scan() {
		in.tokenizer = strings.NewReader(in.reader.Text())
	}
	return in.tokenizer.Text()
}

// Method to get the next integer from input
func (in *in) NextInt() int {
	return int(in.NextInt64())
}

// Method to get the next integer from input
func (in *in) NextInt64() int64 {
	return int64(in.NextInt64())
}

// Method to get the next double from input
func (in *in) NextDouble() float64 {
	return float64(in.NextInt64())
}

// Method to get the next long from input
func (in *in) NextLong() int64 {
	return int64(in.NextInt64())
}

