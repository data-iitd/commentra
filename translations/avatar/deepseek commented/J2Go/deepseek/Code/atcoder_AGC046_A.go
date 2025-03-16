package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a FastReader object to read input
	sc := NewFastReader()
	// Create a PrintWriter object to write output
	pw := bufio.NewWriter(os.Stdout)
	defer pw.Flush()

	// Read an integer input
	x := sc.nextInt()
	// Initialize a counter to keep track of the number of iterations
	count := 0
	// Store the initial value of x in a temporary variable
	tmp := x

	// Initialize x to 0 to start the loop
	x = 0

	// Loop until x becomes 360
	for x != 360 {
		// Increment x by tmp
		x += tmp
		// If x exceeds 360, adjust it by subtracting 360
		if x > 360 {
			x -= 360
		}
		// Increment the counter
		count++
	}

	// Print the final count
	fmt.Fprintln(pw, count)
}

type FastReader struct {
	sc *bufio.Scanner
}

func NewFastReader() *FastReader {
	return &FastReader{sc: bufio.NewScanner(os.Stdin)}
}

func (r *FastReader) next() string {
	r.sc.Scan()
	return r.sc.Text()
}

func (r *FastReader) nextInt() int {
	num, _ := strconv.Atoi(r.next())
	return num
}

func (r *FastReader) nextLong() int64 {
	num, _ := strconv.ParseInt(r.next(), 10, 64)
	return num
}

func (r *FastReader) nextDouble() float64 {
	num, _ := strconv.ParseFloat(r.next(), 64)
	return num
}

func (r *FastReader) nextLine() string {
	return r.next()
}

