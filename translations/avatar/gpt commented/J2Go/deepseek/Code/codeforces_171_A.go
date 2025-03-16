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
	sc *bufio.Scanner
}

// NewFastReader creates a new FastReader instance
func NewFastReader() *FastReader {
	return &FastReader{sc: bufio.NewScanner(os.Stdin)}
}

// ReadString reads the next token from input
func (r *FastReader) ReadString() string {
	r.sc.Scan()
	return r.sc.Text()
}

// ReadInt reads the next integer from input
func (r *FastReader) ReadInt() int {
	num, _ := strconv.Atoi(r.ReadString())
	return num
}

// ReadLong reads the next long from input
func (r *FastReader) ReadLong() int64 {
	num, _ := strconv.ParseInt(r.ReadString(), 10, 64)
	return num
}

// ReadDouble reads the next double from input
func (r *FastReader) ReadDouble() float64 {
	num, _ := strconv.ParseFloat(r.ReadString(), 64)
	return num
}

func main() {
	// Create an instance of FastReader for input
	r := NewFastReader()

	// Read two integers n and m from input
	n := r.ReadInt()
	m := r.ReadInt()

	// Reverse the integer m and store the result in t
	t := reverse(m)

	// Print the sum of t and n
	fmt.Println(t + n)
}

// reverse function to reverse the digits of an integer n
func reverse(n int) int {
	// If n is a single digit, return n multiplied by 10
	if n < 10 {
		return n * 10
	}

	var t, r int

	// Loop to reverse the digits of n
	for t = n; t > 0; t /= 10 {
		r = (r * 10) + (t % 10) // Add the last digit of t to r
	}

	// Return the reversed integer
	return r
}

