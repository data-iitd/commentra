// Importing required packages
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Creating a buffer scanner for reading input from stdin
var sc = bufio.NewScanner(os.Stdin)

// Function to read a single line from stdin
func read() string {
	sc.Scan() // Scan the next token
	return sc.Text() // Return the text of the scanned token
}

// Main function
func main() {
	// Setting the scanner to scan words as tokens
	sc.Split(bufio.ScanWords)

	// Reading the first integer 'a' from stdin
	a, _ := strconv.Atoi(read()) // Converting the read string to integer 'a'

	// Reading the second integer 'b' from stdin
	b, _ := strconv.Atoi(read()) // Converting the read string to integer 'b'

	// Calculating the sum of 'a' and 'b'
	ret := a + b

	// Checking if the sum is less than the difference of 'a' and 'b'
	if ret < (a - b) {
		// If true, then update the value of 'ret'
		ret = a - b
	}

	// Checking if the sum is less than the product of 'a' and 'b'
	if ret < (a * b) {
		// If true, then update the value of 'ret'
		ret = a * b
	}

	// Printing the final value of 'ret'
	fmt.Println(ret)

	// End of the code
}
