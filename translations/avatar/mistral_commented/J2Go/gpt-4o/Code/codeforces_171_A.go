package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// FastReader struct for reading input
type FastReader struct {
	scanner *bufio.Scanner
}

// NewFastReader constructor for FastReader
func NewFastReader() *FastReader {
	return &FastReader{scanner: bufio.NewScanner(os.Stdin)}
}

// Next method for reading the next token
func (fr *FastReader) Next() string {
	fr.scanner.Scan()
	return fr.scanner.Text()
}

// NextInt method for reading an integer
func (fr *FastReader) NextInt() int {
	num, _ := strconv.Atoi(fr.Next())
	return num
}

// Reverse function for reversing a number
func reverse(n int) int {
	if n < 10 {
		return n * 10
	}

	r := 0
	for t := n; t > 0; t /= 10 {
		r = (r * 10) + (t % 10)
	}
	return r
}

// Main function
func main() {
	fr := NewFastReader()

	// Reading input for number of test cases
	n := fr.NextInt()

	// Reading input for number of operations
	m := fr.NextInt()

	// Calling reverse function for m and adding it to n
	t := reverse(m)
	fmt.Println(t + n)
}

// <END-OF-CODE>
