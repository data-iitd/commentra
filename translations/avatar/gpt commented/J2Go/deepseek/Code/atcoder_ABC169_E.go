package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Define a constant number for modulo operations
	const num = 998244353

	// Initialize bufio.Reader to read input from standard input
	reader := bufio.NewReader(os.Stdin)

	// Initialize bufio.Writer to output results to standard output
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read the number of pairs (n) from input
	n, _ := strconv.Atoi(readLine(reader))

	// Create two slices to store the two sets of integers
	ai := make([]int, 0, n)
	bi := make([]int, 0, n)

	// Read n pairs of integers from input
	for i := 0; i < n; i++ {
		// Read a line of input
		line, _ := reader.ReadString('\n')
		// Split the line into tokens
		tokens := strings.Fields(line)
		// Convert the first token to an integer and add to the first slice
		a, _ := strconv.Atoi(tokens[0])
		ai = append(ai, a)
		// Convert the second token to an integer and add to the second slice
		b, _ := strconv.Atoi(tokens[1])
		bi = append(bi, b)
	}

	// Sort both slices to prepare for median calculation
	sort.Ints(ai)
	sort.Ints(bi)

	// Check if the number of elements is odd
	if n%2 == 1 {
		// Calculate the result for odd n using the median values
		fmt.Fprintln(writer, bi[len(bi)/2]-ai[len(ai)/2]+1)
	} else {
		// Calculate the average of the two middle values for even n
		b := float64(ai[len(ai)/2]+ai[len(ai)/2-1]) / 2
		c := float64(bi[len(bi)/2]+bi[len(bi)/2-1]) / 2
		// Calculate the result for even n and print it
		fmt.Fprintln(writer, int(2*(c-b)+1))
	}
}

// Helper function to read a line of input from the reader
func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return strings.TrimSpace(line)
}
