package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new instance of the Fast class
	f := new(Fast)

	// Create a new instance of a buffered reader to read input from stdin
	br := bufio.NewReader(os.Stdin)

	// Create a new instance of a buffered writer to write output to stdout
	pw := bufio.NewWriter(os.Stdout)

	// Call the solution method to handle the input and produce output
	f.sol(br, pw)

	// Close the buffered reader and writer to flush the output
	br.Close()
	pw.Close()
}

// Fast is a class to handle the input and output
type Fast struct {
}

// sol handles the input and output
func (f *Fast) sol(br *bufio.Reader, pw *bufio.Writer) {
	// Read the first line of input and tokenize it to get the string
	s := strings.Split(br.ReadString('\n'), " ")[0]

	// Initialize a cumulative array to count consecutive characters
	cum := make([]int, len(s)+1)
	cum[0] = cum[len(s)] = 0

	// Fill the cumulative array with counts of consecutive characters
	for i := 1; i < len(s); i++ {
		if s[i] == s[i-1] {
			cum[i] = cum[i-1] + 1
		} else {
			cum[i] = cum[i-1]
		}
	}

	// Read the number of queries from the input
	q, _ := strconv.Atoi(br.ReadString('\n'))

	// Process each query
	for q > 0 {
		// Read the range for the query
		l, _ := strconv.Atoi(br.ReadString('\n'))
		r, _ := strconv.Atoi(br.ReadString('\n'))

		// Calculate and print the result for the current query
		pw.WriteString(fmt.Sprintf("%d\n", cum[r] - cum[l-1]))

		q--
	}
}

