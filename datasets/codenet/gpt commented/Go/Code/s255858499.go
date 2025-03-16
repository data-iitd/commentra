package main

import (
	"bufio"
	"os"
	"strconv"
	"fmt"
)

// Initialize a new scanner to read input from standard input
var sc = bufio.NewScanner(os.Stdin)

// Function to read the next line of input and return it as a string
func nextLine() string {
	sc.Scan() // Read the next line
	return sc.Text() // Return the text of the line
}

func main() {
	// Set the scanner to split input by whitespace
	sc.Split(bufio.ScanWords)

	// Read the first integer from input and convert it to an integer
	var a, _ = strconv.Atoi(nextLine())
	// Read the second integer from input and convert it to an integer
	var b, _ = strconv.Atoi(nextLine())

	// Check if the product of a and b is odd
	if a*b % 2 != 0 {
		// If the product is odd, print "Odd"
		fmt.Println("Odd")
	} else {
		// If the product is even, print "Even"
		fmt.Println("Even")
	}
}
