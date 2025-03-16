package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// <START-OF-CODE>

// Solution structure
type Solution struct {
}

// Constructor
func NewSolution() *Solution {
	return new(Solution)
}

// Function to solve the problem
func (s *Solution) solve(in *InputReader, out *bufio.Writer) {
	// Read the number of logs and the value of k
	n := in.nextInt()
	k := in.nextInt()

	// Read the lengths of the logs into an array
	logsLength := in.readArray(n)

	// Initialize binary search bounds
	min := 1
	max := 1000000000 + 1000

	// Perform binary search to find the minimum possible length
	for min < max {
		mid := (min + max) / 2

		// Check if it's possible to cut the logs with the current mid length
		if s.nei(mid, logsLength, k) {
			max = mid
		} else {
			min = mid + 1
		}
	}

	// Output the minimum length found
	out.WriteString(fmt.Sprintf("%d\n", min))
}

// Helper method to determine if logs can be cut with the given mid length
func (s *Solution) nei(mid int, logsLength []int, k int) bool {
	for _, log := range logsLength {
		k -= (log + mid - 1) / mid - 1
	}

	// Return true if we can make the cuts within the limit of k
	return k >= 0
}

// InputReader structure
type InputReader struct {
	reader *bufio.Reader
	tokens []string
}

// Constructor
func NewInputReader(stream *os.File) *InputReader {
	return &InputReader{
		reader: bufio.NewReader(stream),
		tokens: make([]string, 0),
	}
}

// Function to read the next token from input
func (in *InputReader) next() string {
	// Read a new line if the tokenizer is empty
	if len(in.tokens) == 0 {
		in.tokens = strings.Split(in.readLine(), " ")
	}

	// Return the next token
	token := in.tokens[0]
	in.tokens = in.tokens[1:]
	return token
}

// Function to read the next integer from input
func (in *InputReader) nextInt() int {
	// Read the next token
	token := in.next()

	// Convert the token to an integer
	i, err := strconv.Atoi(token)
	if err!= nil {
		panic(err)
	}

	// Return the integer
	return i
}

// Function to read an array of integers from input
func (in *InputReader) readArray(n int) []int {
	// Create an array of integers
	a := make([]int, n)

	// Read the integers
	for i := 0; i < n; i++ {
		a[i] = in.nextInt()
	}

	// Return the array
	return a
}

// Function to read a line from input
func (in *InputReader) readLine() string {
	// Read a line
	line, err := in.reader.ReadString('\n')
	if err!= nil {
		panic(err)
	}

	// Return the line
	return line
}

// Main function
func main() {
	// Create an instance of InputReader for reading input and an instance of
	// bufio.Writer for writing output
	in := NewInputReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)

	// Create an instance of Solution to solve the problem
	s := NewSolution()

	// Solve the problem
	s.solve(in, out)

	// Flush the output
	out.Flush()
}

// 