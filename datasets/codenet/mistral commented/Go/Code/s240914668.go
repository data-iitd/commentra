// Package main is the entry point of the program
package main

import (
	// Importing required packages
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Initialize scanner, reader, and writer
	sc.Split(bufio.ScanWords)
	n := nextInt()
	a := nextInts(n)

	// Initialize answer variable
	ans := 0

	// Iterate through the array 'a'
	for i := 0; i < n; i++ {
		// Initialize left and right indices
		l, r := i, i+1

		// Use a while loop to find the next index 'r' such that the difference between 'a[r]' and 'a[l]' is negative
		for r+1 < n && (a[r]-a[l])*(a[r+1]-a[r]) >= 0 {
			r++
		}

		// Increment the answer variable
		ans++

		// Update the index 'i' to 'r' for the next iteration
		i = r
	}

	// Print the answer
	puts(ans)
	wt.Flush()
}

// Initialize scanner, reader, and writer
var (
	sc  = bufio.NewScanner(os.Stdin)
	rdr = bufio.NewReaderSize(os.Stdin, 1000000)
	wt  = bufio.NewWriter(os.Stdout)
)

// Helper function to read a single word from the standard input
func next() string {
	sc.Scan()
	return sc.Text()
}

// Helper function to read an integer from the standard input
func nextInt() int {
	i, _ := strconv.Atoi(next())
	return i
}

// Helper function to read float64 from the standard input
func nextFloat64() float64 {
	f, _ := strconv.ParseFloat(next(), 64)
	return f
}

// Helper function to read n integers from the standard input
func nextInts(n int) []int {
	slice := make([]int, n)
	for i := 0; i < n; i++ {
		slice[i] = nextInt()
	}
	return slice
}

// Helper function to read n float64 from the standard input
func nextFloat64s(n int) []float64 {
	slice := make([]float64, n)
	for i := 0; i < n; i++ {
		slice[i] = nextFloat64()
	}
	return slice
}

// Helper function to read a megabyte-sized string from the standard input
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

// Helper function to print a formatted string to the standard output
func putf(format string, a ...interface{}) {
	fmt.Fprintf(wt, format, a...)
}

// Helper function to print a single line to the standard output
func puts(a ...interface{}) {
	fmt.Fprintln(wt, a...)
}
