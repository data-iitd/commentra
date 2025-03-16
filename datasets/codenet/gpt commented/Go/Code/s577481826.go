package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Initialize a new scanner to read input from standard input
var sc = bufio.NewScanner(os.Stdin)

// Function to read a line of input and return it as a string
func read() string {
	sc.Scan() // Read the next line of input
	return sc.Text() // Return the text of the line
}

func main() {
	// Set the scanner to split input by whitespace (words)
	sc.Split(bufio.ScanWords)

	// Read two integers from input and convert them from string to int
	a, _ := strconv.Atoi(read()) // Read first integer
	b, _ := strconv.Atoi(read()) // Read second integer

	// Initialize ret with the sum of a and b
	ret := a + b

	// Check if ret is less than the difference of a and b
	if ret < (a - b) {
		ret = a - b // Update ret to the difference if it's smaller
	}
	// Check if ret is less than the product of a and b
	if ret < (a * b) {
		ret = a * b // Update ret to the product if it's smaller
	}

	// Print the final result
	fmt.Println(ret)
}
