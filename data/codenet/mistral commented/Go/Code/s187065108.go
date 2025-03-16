package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Initialize a new scanner for reading input from stdin
var sc = bufio.NewScanner(os.Stdin)

// Function to read an integer as input
func scanInt() int {
	num, _ := strconv.Atoi(scanString()) // Convert the string to integer
	return num                          // Return the integer
}

// Function to read a string as input
func scanString() string {
	sc.Scan()                            // Read the next token as a string
	return sc.Text()                     // Return the string
}

// Function to read an array of integers as input
func scanInts(n int) []int {
	sl := make([]int, n) // Allocate memory for an array of n integers
	for i := range sl { // Iterate through each index of the array
		sl[i] = scanInt() // Read and store an integer at the current index
	}
	return sl // Return the array
}

// Function to read an array of strings as input
func scanStrings(n int) []string {
	sl := make([]string, n) // Allocate memory for an array of n strings
	for i := range sl { // Iterate through each index of the array
		sl[i] = scanString() // Read and store a string at the current index
	}
	return sl // Return the array
}

// Initialize the scanner for reading input
func init() {
	sc.Split(bufio.ScanWords) // Set the scanner to split input on words
}

// Main function to execute the program
func main() {
	// Read the first three integers as input
	r, D, x := scanInt(), scanInt(), scanInt()

	// Iterate through a loop 10 times
	for i := 1; i <= 10; i++ {
		// Calculate the new value of x using the given formula
		x = r*x - D

		// Print the value of x to the console
		fmt.Println(x)
	}
}

// The end of the code
