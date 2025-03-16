package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Create a new scanner to read input from standard input
var sc = bufio.NewScanner(os.Stdin)

// scanInt reads an integer from input and returns it
func scanInt() int {
	num, _ := strconv.Atoi(scanString()) // Convert the scanned string to an integer
	return num
}

// scanString reads a single string from input and returns it
func scanString() string {
	sc.Scan() // Scan the next word from input
	return sc.Text() // Return the scanned text
}

// scanInts reads 'n' integers from input and returns them as a slice
func scanInts(n int) []int {
	sl := make([]int, n) // Create a slice of integers with length 'n'
	for i := range sl {
		sl[i] = scanInt() // Fill the slice with integers read from input
	}
	return sl // Return the slice of integers
}

// scanStrings reads 'n' strings from input and returns them as a slice
func scanStrings(n int) []string {
	sl := make([]string, n) // Create a slice of strings with length 'n'
	for i := range sl {
		sl[i] = scanString() // Fill the slice with strings read from input
	}
	return sl // Return the slice of strings
}

// init function sets up the scanner to split input by words
func init() {
	sc.Split(bufio.ScanWords) // Configure the scanner to split input into words
}

// main function is the entry point of the program
func main() {
	// Read three integers from input: r, D, and x
	r, D, x := scanInt(), scanInt(), scanInt()
	
	// Perform calculations and print the result for 10 iterations
	for i := 1; i <= 10; i++ {
		x = r*x - D // Update x based on the formula
		fmt.Println(x) // Print the current value of x
	}
}
