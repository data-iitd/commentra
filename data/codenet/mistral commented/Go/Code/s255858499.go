
package main

import (
	"bufio"
	"os"
	"strconv"
	"fmt"
)

// Initialize a new scanner to read input from stdin
var sc = bufio.NewScanner(os.Stdin)

// Function to read a single line from stdin and return it as a string
func nextLine() string {
	// Scan the next token as a word
	sc.Scan()
	// Return the text of the scanned token as a string
	return sc.Text()
}

// Main function
func main() {
	// Set the scanner to split input on words
	sc.Split(bufio.ScanWords)
	
	// Read the first two integers from stdin and store them in variables a and b
	var a, b int
	a, _ = strconv.Atoi(nextLine()) // Convert the first line read from stdin to an integer and store it in variable a
	b, _ = strconv.Atoi(nextLine()) // Convert the second line read from stdin to an integer and store it in variable b

	// Check if the product of a and b is odd or even
	if a*b%2 != 0 {
		// If the product is odd, print "Odd" to stdout
		fmt.Println("Odd")
	} else {
		// If the product is even, print "Even" to stdout
		fmt.Println("Even")
	}
}
