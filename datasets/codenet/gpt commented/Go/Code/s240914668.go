package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Set the scanner to split input by whitespace
	sc.Split(bufio.ScanWords)

	// Read the number of integers
	n := nextInt()
	// Read the integers into a slice
	a := nextInts(n)

	// Initialize the answer counter
	ans := 0

	// Iterate through the slice of integers
	for i := 0; i < n; i++ {
		// Set the left and right pointers for the current segment
		l, r := i, i+1

		// Expand the right pointer while the conditions are met
		for r+1 < n && (a[r]-a[l])*(a[r+1]-a[r]) >= 0 {
			r++
		}

		// Increment the answer for each segment found
		ans++
		// Move the left pointer to the end of the current segment
		i = r
	}

	// Output the final count of segments
	puts(ans)
	// Flush the buffered writer to ensure all output is written
	wt.Flush()
}

var (
	// Initialize a new scanner for reading input
	sc  = bufio.NewScanner(os.Stdin)
	// Create a buffered reader with a large buffer size
	rdr = bufio.NewReaderSize(os.Stdin, 1000000)
	// Create a buffered writer for output
	wt  = bufio.NewWriter(os.Stdout)
)

// Function to read the next string from input
func next() string {
	sc.Scan()
	return sc.Text()
}

// Function to read the next integer from input
func nextInt() int {
	i, _ := strconv.Atoi(next())
	return i
}

// Function to read the next float64 from input
func nextFloat64() float64 {
	f, _ := strconv.ParseFloat(next(), 64)
	return f
}

// Function to read a slice of integers from input
func nextInts(n int) []int {
	slice := make([]int, n)
	for i := 0; i < n; i++ {
		slice[i] = nextInt()
	}
	return slice
}

// Function to read a slice of float64 from input
func nextFloat64s(n int) []float64 {
	slice := make([]float64, n)
	for i := 0; i < n; i++ {
		slice[i] = nextFloat64()
	}
	return slice
}

// Function to read a large block of text from input
func nextMega() string {
	buf := make([]byte, 0, 1000000)
	for {
		l, p, _ := rdr.ReadLine()
		buf = append(buf, l...)
		if !p {
			break
		}
	}
	return string(buf)
}

// Function to format and write output to the buffered writer
func putf(format string, a ...interface{}) {
	fmt.Fprintf(wt, format, a...)
}

// Function to write a line of output to the buffered writer
func puts(a ...interface{}) {
	fmt.Fprintln(wt, a...)
}
