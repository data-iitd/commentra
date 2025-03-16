package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// FastReader struct to read input
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
	num, _ := strconv.Atoi(fr.Next())
	return num
}

func main() {
	// Creating FastReader object to read input
	fr := NewFastReader()

	// Reading the first integer input
	x := fr.NextInt()

	// Initializing count variable to 0
	count := 0

	// Initializing temporary variable tmp with the value of x
	tmp := x

	// Setting x to 0
	x = 0

	// Starting a loop that runs until x is equal to 360
	for x != 360 {
		// Adding the value of tmp to x
		x += tmp

		// If x is greater than 360, then subtract 360 from it
		if x > 360 {
			x -= 360
		}

		// Incrementing the count variable
		count++
	}

	// Printing the value of count to the console
	fmt.Println(count)
}

// <END-OF-CODE>
