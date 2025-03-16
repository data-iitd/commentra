package main

import (
	"bufio"
	"fmt"
	"os"
)

const BUFFERSIZE = 512000

// Initialize the scanner and writer for input and output operations.
var sc = bufio.NewScanner(bufio.NewReaderSize(os.Stdin, BUFFERSIZE))
var out = bufio.NewWriterSize(os.Stdout, BUFFERSIZE)

// Function to find the position of a given value in a sequence.
func solve() {
	var position int64
	fmt.Scan(&position)
	nrstSeqStartIndx := int64(1)

	// Find the starting index of the sequence where the position might be located.
	for getValueAtIndex(nrstSeqStartIndx*2) < position {
		nrstSeqStartIndx *= 2
	}

	// Find the exact position within the sequence.
	for getValueAtIndex(nrstSeqStartIndx+1) <= position {
		nrstSeqStartIndx++
	}

	startIndex := getValueAtIndex(nrstSeqStartIndx)
	fmt.Fprintln(out, (position-startIndex)+1)
}

// Function to calculate the value at a specific index in the sequence.
func getValueAtIndex(index int64) int64 {
	return 1 + ((index - 1) * index / 2)
}

// Main function to initialize the input and call the solve function.
func main() {
	solve()
	out.Flush()
}

// <END-OF-CODE>
