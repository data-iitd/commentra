package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new reader to read input from the standard input stream
	reader := bufio.NewReader(os.Stdin)
	
	// Create a new writer to output results to the standard output stream
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	
	// Create an instance of the Fast struct to process the input
	f := Fast{}
	
	// Call the sol method to handle the input and produce output
	f.sol(reader, writer)
}

type Fast struct{}

func (f Fast) sol(reader *bufio.Reader, writer *bufio.Writer) {
	// Read the first line of input and split it into tokens to get the string
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	
	// Initialize a cumulative array to count consecutive characters
	cum := make([]int, len(input)+1)
	cum[0] = cum[len(input)]
	
	// Fill the cumulative array with counts of consecutive characters
	for i := 1; i < len(input); i++ {
		if input[i] == input[i-1] {
			cum[i] = cum[i-1] + 1
		} else {
			cum[i] = cum[i-1]
		}
	}
	
	// Read the number of queries from the input
	queries, _ := reader.ReadString('\n')
	queries = strings.TrimSpace(queries)
	q, _ := strconv.Atoi(queries)
	
	// Process each query
	for i := 0; i < q; i++ {
		// Read the range for the query
		rangeInput, _ := reader.ReadString('\n')
		rangeInput = strings.TrimSpace(rangeInput)
		parts := strings.Split(rangeInput, " ")
		l, _ := strconv.Atoi(parts[0])
		r, _ := strconv.Atoi(parts[1])
		
		// Calculate and print the result for the current query
		writer.WriteString(fmt.Sprintf("%d\n", cum[r-1]-cum[l-1]))
	}
}

