package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize FastReader to read input efficiently
	in := NewFastReader()

	// Read the number of elements
	n := in.nextInt()

	// Create a TreeSet to keep track of available positions on the left
	left := make(map[int]bool)

	// Initialize an array to store the answers
	answer := make([]int, n)

	// Populate the TreeSet with indices from 0 to n-1
	for i := 0; i < n; i++ {
		left[i] = true
	}

	// Read the number of queries
	q := in.nextInt()

	// Process each query
	for i := 0; i < q; i++ {
		// Read the range [l, r] and the winning index
		l := in.nextInt() - 1
		r := in.nextInt() - 1
		win := in.nextInt() - 1

		// Update the answer array for all positions in the range [l, r]
		for k := range left {
			if k >= l && k <= r {
				answer[k] = win + 1 // Go uses 1-based indexing
				delete(left, k)    // Remove this position from available positions
			}
		}

		// Mark the winning index as available again
		left[win] = true // Add the winning index back to available positions
	}

	// Build the output string from the answer array
	var ans strings.Builder
	for i := 0; i < n; i++ {
		ans.WriteString(strconv.Itoa(answer[i])) // Append each answer to the StringBuilder
	}

	// Print the final answer
	fmt.Println(ans.String())
}

// FastReader class for efficient input reading
type FastReader struct {
	sc *bufio.Scanner
}

func NewFastReader() *FastReader {
	return &FastReader{sc: bufio.NewScanner(os.Stdin)}
}

// Method to read the next token as a String
func (r *FastReader) next() string {
	r.sc.Scan()
	return r.sc.Text()
}

// Method to read the next token as an integer
func (r *FastReader) nextInt() int {
	n, _ := strconv.Atoi(r.next())
	return n
}

// Method to read the next token as a long
func (r *FastReader) nextLong() int64 {
	n, _ := strconv.ParseInt(r.next(), 10, 64)
	return n
}

// Method to read the next token as a double
func (r *FastReader) nextDouble() float64 {
	n, _ := strconv.ParseFloat(r.next(), 64)
	return n
}

// Method to read the next line as a String
func (r *FastReader) nextLine() string {
	r.sc.Scan()
	return r.sc.Text()
}
