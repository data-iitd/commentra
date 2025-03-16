package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Declare a variable N to hold the number of elements
	var N int
	// Read the integer N from standard input
	fmt.Scan(&N)

	// Create a new scanner to read input from standard input
	scanner := bufio.NewScanner(os.Stdin)
	// Set the scanner to split input by whitespace
	scanner.Split(bufio.ScanWords)

	// Initialize a slice v of size N to hold counts of occurrences
	v := make([]int, N)
	var a int

	// Loop through the range from 1 to N-1 to read N-1 integers
	for i := 1; i < N; i++ {
		// Scan the next word from input
		scanner.Scan()
		// Convert the scanned text to an integer
		a, _ = strconv.Atoi(scanner.Text())
		// Increment the count at the index corresponding to the value read (adjusted for 0-based index)
		v[a-1]++
	}

	// Create a buffered writer to output results to standard output
	w := bufio.NewWriter(os.Stdout)
	// Loop through the slice v to print the counts of occurrences
	for _, e := range v {
		// Write each count to the output
		fmt.Fprintln(w, e)
	}
	// Flush the buffered writer to ensure all output is written
	w.Flush()
}
