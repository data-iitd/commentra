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

// Reverse reverses the digits of an integer n
func reverse(n int) int {
	if n < 10 {
		return n * 10
	}

	r := 0
	for n > 0 {
		r = r*10 + n%10
		n = n / 10
	}
	return r
}

func main() {
	// Create an instance of FastReader for input
	fr := NewFastReader()

	// Read two integers n and m from input
	n := fr.NextInt()
	m := fr.NextInt()

	// Reverse the integer m and store the result in t
	t := reverse(m)

	// Print the sum of t and n
	fmt.Println(t + n)
}

// <END-OF-CODE>
