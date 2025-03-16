package main

import (
	"bufio"
	"fmt"
	"os"
)

// Define constants for buffer sizes
const (
	initialBufSize = 1e4 // Initial buffer size for the scanner
	maxBufSize     = 1e8 // Maximum buffer size for the scanner
)

// Create a new scanner to read from standard input
var sc = bufio.NewScanner(os.Stdin)

// Initialize the scanner with a buffer and set the split function
func init() {
	buf := make([]byte, initialBufSize) // Create a byte slice for the buffer
	sc.Buffer(buf, maxBufSize)           // Set the buffer size for the scanner
	sc.Split(bufio.ScanWords)            // Split the input by words
}

// Function to read the next word from input
func next() string {
	sc.Scan() // Scan the next word
	return sc.Text() // Return the scanned word as a string
}

// Function to return the minimum of two integers
func min(x, y int) int {
	if x > y {
		return y // Return y if x is greater
	} else {
		return x // Return x otherwise
	}
}

// Main function where the program execution begins
func main() {
	S := next() // Read the input string

	l0, l1 := 0, 0 // Initialize counters for '0's and '1's
	// Loop through each character in the input string
	for i := 0; i < len(S); i++ {
		if S[i] == '0' {
			l0++ // Increment the counter for '0'
		} else {
			l1++ // Increment the counter for '1'
		}
	}
	// Print the result, which is twice the minimum count of '0's or '1's
	fmt.Println(2 * min(l0, l1))
}
