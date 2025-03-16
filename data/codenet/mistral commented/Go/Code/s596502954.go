
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Initialize a new scanner for reading input from stdin
var sc = bufio.NewScanner(os.Stdin)

// Function to read a single word as a string from the input
func next() string {
	sc.Scan()
	// Comment: Scans the next token, storing it as a single word
	return sc.Text()
}

// Function to read an integer from the input
func nextInt() int {
	sc.Scan()
	// Comment: Scans the next token as a single word and converts it to an integer
	i, _ := strconv.Atoi(sc.Text())
	return i
}

// Function to read a float64 from the input
func nextFloat64() float64 {
	f, _ := strconv.ParseFloat(next(), 64)
	// Comment: Parses the next token as a float64 value
	return f
}

// Function to read n integers from the input and return as a slice
func nextInts(n int) []int {
	slice := make([]int, n)
	// Comment: Creates a slice of size n and initializes it with zero values
	for i := 0; i < n; i++ {
		slice[i] = nextInt()
		// Comment: Reads the next integer from the input and assigns it to the current index of the slice
	}
	return slice
}

// Main function
func main() {
	// Comment: Sets the scanner to scan words instead of lines
	sc.Split(bufio.ScanWords)

	// Read the first three integers from the input
	a := nextInt()
	b := nextInt()
	c := nextInt()

	// Check if the condition is true
	if a+b >= c {
		// If true, print "Yes" to the output
		fmt.Println("Yes")
	} else {
		// If false, print "No" to the output
		fmt.Println("No")
	}

	// End of code
	