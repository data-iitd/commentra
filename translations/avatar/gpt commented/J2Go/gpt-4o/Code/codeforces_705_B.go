package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// FastReader struct to handle fast input
type FastReader struct {
	scanner *bufio.Scanner
}

// NewFastReader initializes a new FastReader
func NewFastReader() *FastReader {
	return &FastReader{scanner: bufio.NewScanner(os.Stdin)}
}

// Next reads the next token from input
func (fr *FastReader) Next() string {
	fr.scanner.Scan()
	return fr.scanner.Text()
}

// NextInt reads the next integer from input
func (fr *FastReader) NextInt() int {
	val, _ := strconv.Atoi(fr.Next())
	return val
}

// Solve function to process the input and determine the winners
func Solve() {
	fr := NewFastReader()
	t := fr.NextInt() // Read the number of elements in the array
	arr := make([]int, t)

	// Populate the array with input values
	for i := 0; i < t; i++ {
		arr[i] = fr.NextInt()
	}

	prevWinner := 0 // Variable to track the previous winner

	// Iterate through the array to determine the winner for each element
	for i := 0; i < len(arr); i++ {
		// Check if the current element is 1
		if arr[i] == 1 {
			// If the previous winner is 0, set the previous winner to 2
			if prevWinner == 0 {
				prevWinner = 2
			}
		}

		// Determine the winner based on the previous winner and the current element
		if prevWinner == 2 || prevWinner == 0 {
			// If the previous winner is 2 or 0, check the parity of (arr[i] - 1)
			if (arr[i]-1)%2 == 0 {
				fmt.Println(2) // Print winner 2
				prevWinner = 2 // Update previous winner
			} else {
				fmt.Println(1) // Print winner 1
				prevWinner = 1 // Update previous winner
			}
		} else {
			// If the previous winner is 1, check the parity of (arr[i] - 1)
			if (arr[i]-1)%2 == 0 {
				fmt.Println(1) // Print winner 1
				prevWinner = 1 // Update previous winner
			} else {
				fmt.Println(2) // Print winner 2
				prevWinner = 2 // Update previous winner
			}
		}
	}
}

func main() {
	Solve() // Call the solve function for processing
}

// <END-OF-CODE>
