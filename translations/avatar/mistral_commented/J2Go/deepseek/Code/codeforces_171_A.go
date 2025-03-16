package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Defining a struct for FastReader
type FastReader struct {
	sc *bufio.Scanner
}

// Constructor for FastReader
func NewFastReader() *FastReader {
	return &FastReader{sc: bufio.NewScanner(os.Stdin)}
}

// Method for reading next token
func (r *FastReader) next() string {
	r.sc.Scan()
	return r.sc.Text()
}

// Methods for reading specific types of input
func (r *FastReader) nextInt() int {
	n, _ := strconv.Atoi(r.next())
	return n
}

func (r *FastReader) nextLong() int64 {
	n, _ := strconv.ParseInt(r.next(), 10, 64)
	return n
}

func (r *FastReader) nextDouble() float64 {
	n, _ := strconv.ParseFloat(r.next(), 64)
	return n
}

func (r *FastReader) nextLine() string {
	r.sc.Scan()
	return r.sc.Text()
}

// Main function
func main() {
	// Creating an instance of FastReader
	sc := NewFastReader()

	// Reading input for number of test cases
	n := sc.nextInt()

	// Reading input for number of operations
	m := sc.nextInt()

	// Calling reverse function for m and adding it to n
	t := reverse(m)
	fmt.Println(t + n)
}

// Function for reversing a number
func reverse(n int) int {
	// Base case for numbers less than 10
	if n < 10 {
		return n * 10
	}

	// Initializing variables
	t := n
	r := 0

	// Reversing the number
	for t > 0 {
		// Adding the digit to the reversed number
		r = (r * 10) + t % 10

		// Moving to the next digit
		t = t / 10
	}

	// Returning the reversed number
	return r
}

