package main

import (
	"bufio"
	"fmt"
	"os"
)

// Initialize constants
const BUFFER_SIZE = 512000

// Initialize scanner and writer
var sc = bufio.NewScanner(bufio.NewReaderSize(os.Stdin, BUFFER_SIZE))
var out = bufio.NewWriterSize(os.Stdout, BUFFER_SIZE)

// Main function
func main() {
	defer out.Flush() // Ensure the output buffer is flushed at the end
	solve()          // Solve the problem
}

// Solve the problem
func solve() {
	var position int64
	fmt.Scan(&position) // Read the position from input
	solveHelper(position) // Solve the problem using helper method
}

// Helper method to solve the problem
func solveHelper(position int64) {
	nrstSeqStartIndx := int64(1) // Initialize index for the start of the next sequence

	// Binary search for the start index of the sequence containing the position
	for getValueAtIndex(nrstSeqStartIndx*2) < position {
		nrstSeqStartIndx *= 2 // Multiply index by 2
	}

	// Linear search for the end index of the sequence containing the position
	for getValueAtIndex(nrstSeqStartIndx+1) <= position {
		nrstSeqStartIndx++ // Increment index
	}

	// Print the answer
	startIndex := getValueAtIndex(nrstSeqStartIndx) // Get the start index of the sequence
	fmt.Fprintln(out, (position-startIndex)+1) // Print the length of the sequence
}

// Get the value at a given index
func getValueAtIndex(index int64) int64 {
	return 1 + ((index - 1) * index / 2) // Calculate the value at the given index
}
