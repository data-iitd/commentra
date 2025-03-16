package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// <START-OF-CODE>

// TaskD class containing the solve method
type TaskD struct {
}

// NewTaskD returns a new instance of TaskD
func NewTaskD() *TaskD {
	return &TaskD{}
}

// Solve the problem
func (t *TaskD) Solve(testNumber int, input *InputReader, output *OutputWriter) {
	// Read the number of elements and the modulo value
	n := input.ReadInt()
	m := input.ReadInt()

	// Read the array of elements
	a := input.ReadIntArray(n)

	// HashMap to store the frequency of remainders
	dp := make(map[int]int)

	// Initialize the answer and base variable
	ans := 0
	base := 0

	// Iterate through the array to calculate the answer
	for i := 0; i < n; i++ {
		// Update the base variable
		base = (base - a[i]%m + m) % m

		// Update the frequency of remainders in the HashMap
		dp[base+a[i]%m]++

		// Add the frequency of the current remainder to the answer
		ans += dp[base]
	}

	// Print the final answer
	output.WriteInt(ans)
}

// InputReader class to read input efficiently
type InputReader struct {
	r *bufio.Reader
}

// NewInputReader returns a new instance of InputReader
func NewInputReader(r *bufio.Reader) *InputReader {
	return &InputReader{r: r}
}

// Read the next string from the input
func (i *InputReader) ReadString() string {
	s, _ := i.r.ReadString('\n')
	return strings.TrimSpace(s)
}

// Read the next integer from the input
func (i *InputReader) ReadInt() int {
	n, _ := strconv.Atoi(i.ReadString())
	return n
}

// Read the next array of integers from the input
func (i *InputReader) ReadIntArray(n int) []int {
	a := make([]int, n)
	for j := 0; j < n; j++ {
		a[j] = i.ReadInt()
	}
	return a
}

// OutputWriter class to write output efficiently
type OutputWriter struct {
	w *bufio.Writer
}

// NewOutputWriter returns a new instance of OutputWriter
func NewOutputWriter(w *bufio.Writer) *OutputWriter {
	return &OutputWriter{w: w}
}

// Write the output
func (o *OutputWriter) WriteInt(n int) {
	o.w.WriteString(fmt.Sprintf("%d\n", n))
}

// 