package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Creating FastReader object to read input
	sc := NewFastReader()

	// Creating PrintWriter object to write output
	pw := bufio.NewWriter(os.Stdout)
	defer pw.Flush()

	// Reading the first integer input
	x := sc.nextInt()

	// Initializing count variable to 0
	count := 0

	// Initializing temporary variable tmp with the value of x
	tmp := x

	// Setting x to 0
	x = 0

	// Starting a while loop that runs until x is equal to 360
	for x != 360 {
		// Adding the value of tmp to x
		x = x + tmp

		// If x is greater than 360, then subtract 360 from it
		if x > 360 {
			x = x - 360
		}

		// Incrementing the count variable
		count++
	}

	// Printing the value of count to the console using PrintWriter
	fmt.Fprintln(pw, count)
}

// FastReader class starts here
type FastReader struct {
	sc *bufio.Scanner
}

// Constructor method initializes BufferedReader object
func NewFastReader() *FastReader {
	return &FastReader{sc: bufio.NewScanner(os.Stdin)}
}

// Method to read a string token
func (r *FastReader) next() string {
	r.sc.Scan()
	return r.sc.Text()
}

// Method to read an integer input
func (r *FastReader) nextInt() int {
	num, _ := strconv.Atoi(r.next())
	return num
}

// Method to read a long integer input
func (r *FastReader) nextLong() int64 {
	num, _ := strconv.ParseInt(r.next(), 10, 64)
	return num
}

// Method to read a double input
func (r *FastReader) nextDouble() float64 {
	num, _ := strconv.ParseFloat(r.next(), 64)
	return num
}

// Method to read a full line of input
func (r *FastReader) nextLine() string {
	return r.next()
}
