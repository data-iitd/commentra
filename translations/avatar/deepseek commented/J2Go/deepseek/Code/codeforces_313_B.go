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

	fast := Fast{}
	fast.sol(reader, writer)
}

type Fast struct{}

func (f Fast) sol(reader *bufio.Reader, writer *bufio.Writer) {
	// Read the input string
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)

	// Initialize the cumulative array to store counts of consecutive identical characters
	cum := make([]int, len(input)+1)
	cum[0] = 0
	cum[len(input)] = 0

	// Fill the cumulative array with counts of consecutive identical characters
	for i := 1; i < len(input); i++ {
		if input[i] == input[i-1] {
			cum[i] = cum[i-1] + 1
		} else {
			cum[i] = cum[i-1]
		}
	}

	// Read the number of queries
	queries, _ := reader.ReadString('\n')
	queries = strings.TrimSpace(queries)
	q, _ := strconv.Atoi(queries)

	// Process each query
	for i := 0; i < q; i++ {
		query, _ := reader.ReadString('\n')
		query = strings.TrimSpace(query)
		parts := strings.Split(query, " ")
		l, _ := strconv.Atoi(parts[0])
		r, _ := strconv.Atoi(parts[1])

		// Calculate and print the result for the query
		writer.WriteString(fmt.Sprintf("%d\n", cum[r-1]-cum[l-1]))
	}
}

