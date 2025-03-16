package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a buffered reader to read input from standard input
	reader := bufio.NewReader(os.Stdin)

	// Read the first line of input
	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s)

	// Initialize a cumulative array to count consecutive characters
	cum := make([]int, len(s)+1)
	cum[0] = 0
	for i := 1; i < len(s); i++ {
		if s[i] == s[i-1] {
			cum[i] = cum[i-1] + 1 // Increment count if the current character is the same as the previous
		} else {
			cum[i] = cum[i-1] // Carry forward the previous count if different
		}
	}
	cum[len(s)] = cum[len(s)-1]

	// Read the number of queries from the input
	qLine, _ := reader.ReadString('\n')
	qLine = strings.TrimSpace(qLine)
	q, _ := strconv.Atoi(qLine)

	// Process each query
	for i := 0; i < q; i++ {
		queryLine, _ := reader.ReadString('\n')
		queryLine = strings.TrimSpace(queryLine)
		parts := strings.Split(queryLine, " ")
		l, _ := strconv.Atoi(parts[0])
		r, _ := strconv.Atoi(parts[1])
		r-- // Adjust r to be zero-based

		// Calculate and print the result for the current query
		result := cum[r] - cum[l-1]
		fmt.Println(result)
	}
}

// <END-OF-CODE>
