package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a BufferedReader to read input from the standard input stream
	br := bufio.NewReader(os.Stdin)

	// Create a PrintWriter to output results to the standard output stream
	pw := bufio.NewWriter(os.Stdout)

	// Create an instance of the Fast class to process the input
	f := Fast{}

	// Call the solution method to handle the input and produce output
	f.sol(br, pw)

	// Close the PrintWriter to flush the output
	pw.Flush()
}

type Fast struct{}

func (f *Fast) sol(br *bufio.Reader, pw *bufio.Writer) {
	// Read the first line of input and tokenize it to get the string
	s, _ := br.ReadString('\n')
	s = strings.TrimSpace(s)

	// Initialize a cumulative array to count consecutive characters
	cum := make([]int, len(s)+1)
	cum[0] = cum[len(s)] = 0

	// Fill the cumulative array with counts of consecutive characters
	for i := 1; i < len(s); i++ {
		if s[i] == s[i-1] {
			cum[i] = cum[i-1] + 1 // Increment count if the current character is the same as the previous
		} else {
			cum[i] = cum[i-1] // Carry forward the previous count if different
		}
	}

	// Read the number of queries from the input
	q, _ := strconv.Atoi(strings.TrimSpace(br.Text()))

	// Process each query
	for q > 0 {
		// Read the range for the query
		s, _ = br.ReadString('\n')
		s = strings.TrimSpace(s)
		st := strings.Split(s, " ")
		l, _ := strconv.Atoi(st[0])
		r, _ := strconv.Atoi(st[1])

		// Calculate and print the result for the current query
		fmt.Fprintln(pw, cum[r-1]-cum[l-1])

		q--
	}
}

