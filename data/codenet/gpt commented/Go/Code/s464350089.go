package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Define a constant for the modulo value
const mod = 1000000007

// Define a constant for the input/output buffer size (1MB)
const ioBufferSize = 1 * 1024 * 1024

// Initialize a buffered scanner for reading input
var sc = func() *bufio.Scanner {
	sc := bufio.NewScanner(os.Stdin)
	// Set the buffer size for the scanner
	sc.Buffer(make([]byte, ioBufferSize), ioBufferSize)
	// Split the input by whitespace
	sc.Split(bufio.ScanWords)
	return sc
}()

// Function to read the next string from input
func next() string {
	sc.Scan()
	return sc.Text()
}

// Function to read the next integer from input
func nextInt() int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		// Panic if there is an error converting to integer
		panic(e)
	}
	return i
}

func main() {
	// Read the values of h and n from input
	h, n := nextInt(), nextInt()
	a := 0 // Initialize a variable to accumulate the sum of integers

	// Loop to read n integers and accumulate their sum
	for i := 0; i < n; i++ {
		a += nextInt()
	}

	// Check if the accumulated sum is less than h
	if h > a {
		// If h is greater than the sum, print "No"
		fmt.Println("No")
	} else {
		// Otherwise, print "Yes"
		fmt.Println("Yes")
	}
}
