
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a scanner to read input from the standard input stream
	scanner := bufio.NewScanner(os.Stdin)

	// Create a writer to output results to the standard output stream
	writer := bufio.NewWriter(os.Stdout)

	// Create an instance of the Fast struct to process the input
	f := &Fast{}

	// Call the solution method to handle the input and produce output
	f.sol(scanner, writer)

	// Flush the writer to ensure all output is written
	writer.Flush()
}

type Fast struct{}

func (f *Fast) sol(scanner *bufio.Scanner, writer *bufio.Writer) {
	// Read the first line of input and tokenize it to get the string
	scanner.Scan()
	s := strings.Split(scanner.Text(), " ")

	// Initialize a cumulative array to count consecutive characters
	cum := make([]int, len(s[0])+1)
	cum[0] = cum[len(s[0])] = 0

	// Fill the cumulative array with counts of consecutive characters
	for i := 1; i < len(s[0]); i++ {
		if s[0][i] == s[0][i-1] {
			cum[i] = cum[i-1] + 1 // Increment count if the current character is the same as the previous
		} else {
			cum[i] = cum[i-1] // Carry forward the previous count if different
		}
	}

	// Read the number of queries from the input
	scanner.Scan()
	q, _ := strconv.Atoi(scanner.Text())

	// Process each query
	for q > 0 {
		// Read the range for the query
		scanner.Scan()
		l, _ := strconv.Atoi(strings.Split(scanner.Text(), " ")[0])
		r, _ := strconv.Atoi(strings.Split(scanner.Text(), " ")[1])
		r--

		// Calculate and print the result for the current query
		fmt.Fprintln(writer, cum[r]-cum[l-1])

		q--
	}
}

