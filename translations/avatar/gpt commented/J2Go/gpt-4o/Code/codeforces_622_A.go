package main

import (
	"bufio"
	"fmt"
	"os"
)

const BUFFERSIZE = 512000

// Function to calculate the value at a given index based on a specific formula
func getValueAtIndex(index int64) int64 {
	return 1 + ((index - 1) * index / 2)
}

// Function to solve the main problem
func solve() {
	var position int64
	fmt.Scan(&position)

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
	fmt.Println((position - startIndex) + 1)
}

// Main function to execute the program
func main() {
	// Initialize the input reader
	reader := bufio.NewReaderSize(os.Stdin, BUFFERSIZE)

	// Call the solve method to process the input and produce output
	solve()

	// Close the output stream (handled automatically in Go)
}

// <END-OF-CODE>
