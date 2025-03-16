package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the input string
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s)

	// Initialize the cumulative array to store counts of consecutive identical characters
	cum := make([]int, len(s)+1)
	cum[0] = cum[len(s)] = 0

	// Fill the cumulative array with counts of consecutive identical characters
	for i := 1; i < len(s); i++ {
		if s[i] == s[i-1] {
			cum[i] = cum[i-1] + 1
		} else {
			cum[i] = cum[i-1]
		}
	}

	// Read the number of queries
	reader = bufio.NewReader(os.Stdin)
	q, _ := reader.ReadString('\n')
	q = strings.TrimSpace(q)
	qInt, _ := strconv.Atoi(q)

	// Process each query
	for qInt > 0 {
		reader = bufio.NewReader(os.Stdin)
		l, _ := reader.ReadString('\n')
		l = strings.TrimSpace(l)
		lInt, _ := strconv.Atoi(l)

		r, _ := reader.ReadString('\n')
		r = strings.TrimSpace(r)
		rInt, _ := strconv.Atoi(r)

		// Calculate and print the result for the query
		fmt.Println(cum[rInt-1] - cum[lInt-1])

		qInt--
	}
}

