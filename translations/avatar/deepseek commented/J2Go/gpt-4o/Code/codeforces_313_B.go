package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	f := Fast{}
	f.sol(reader, writer)
}

type Fast struct{}

func (f *Fast) sol(reader *bufio.Reader, writer *bufio.Writer) {
	// Read the input string
	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s)

	// Initialize the cumulative array to store counts of consecutive identical characters
	cum := make([]int, len(s)+1)
	cum[0] = 0

	// Fill the cumulative array with counts of consecutive identical characters
	for i := 1; i < len(s); i++ {
		if s[i] == s[i-1] {
			cum[i] = cum[i-1] + 1
		} else {
			cum[i] = cum[i-1]
		}
	}
	cum[len(s)] = cum[len(s)-1] // Ensure the last element is set correctly

	// Read the number of queries
	qStr, _ := reader.ReadString('\n')
	qStr = strings.TrimSpace(qStr)
	q, _ := strconv.Atoi(qStr)

	// Process each query
	for i := 0; i < q; i++ {
		queryStr, _ := reader.ReadString('\n')
		queryStr = strings.TrimSpace(queryStr)
		parts := strings.Split(queryStr, " ")
		l, _ := strconv.Atoi(parts[0])
		r, _ := strconv.Atoi(parts[1])
		r-- // Convert to zero-based index

		// Calculate and print the result for the query
		result := cum[r] - cum[l-1]
		fmt.Fprintln(writer, result)
	}
}

// <END-OF-CODE>
