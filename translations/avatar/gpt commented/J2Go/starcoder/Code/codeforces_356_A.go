package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// FastReader is a wrapper around bufio.Reader.
// It provides fast input reading in a way that's convenient for this problem.
type FastReader struct {
	r *bufio.Reader
}

// NewFastReader returns a new FastReader.
func NewFastReader(r *bufio.Reader) *FastReader {
	return &FastReader{r: r}
}

// ReadString reads a line from the input, removes the trailing newline,
// and returns the string.
func (f *FastReader) ReadString() string {
	s, _ := f.r.ReadString('\n')
	return strings.TrimSuffix(s, "\n")
}

// ReadInt reads a single integer from the input and returns it.
func (f *FastReader) ReadInt() int {
	i, _ := strconv.Atoi(f.ReadString())
	return i
}

// ReadIntSlice reads a line from the input and returns a slice of integers.
func (f *FastReader) ReadIntSlice() []int {
	line := f.ReadString()
	return strings.Split(line, " ")
}

// ReadInt64Slice reads a line from the input and returns a slice of int64s.
func (f *FastReader) ReadInt64Slice() []int64 {
	line := f.ReadString()
	var s []int64
	for _, v := range strings.Split(line, " ") {
		i, _ := strconv.ParseInt(v, 10, 64)
		s = append(s, i)
	}
	return s
}

// ReadFloat64Slice reads a line from the input and returns a slice of float64s.
func (f *FastReader) ReadFloat64Slice() []float64 {
	line := f.ReadString()
	var s []float64
	for _, v := range strings.Split(line, " ") {
		i, _ := strconv.ParseFloat(v, 64)
		s = append(s, i)
	}
	return s
}

func main() {
	// Initialize a new FastReader.
	f := NewFastReader(bufio.NewReader(os.Stdin))

	// Read the number of elements.
	n := f.ReadInt()

	// Create a TreeSet to keep track of available positions on the left.
	left := make(map[int]struct{})

	// Initialize an array to store the answers.
	answer := make([]int, n)

	// Populate the TreeSet with indices from 0 to n-1.
	for i := 0; i < n; i++ {
		left[i] = struct{}{}
	}

	// Read the number of queries.
	q := f.ReadInt()

	// Process each query.
	for q > 0 {
		// Read the range [l, r] and the winning index.
		l, r := f.ReadInt()-1, f.ReadInt()-1
		win := f.ReadInt()

		// Update the answer array for all positions in the range [l, r].
		for i := l; i <= r; i++ {
			answer[i] = win
			delete(left, i)
		}

		// Mark the winning index as available again.
		answer[win-1] = 0
		left[win-1] = struct{}{}

		q--
	}

	// Build the output string from the answer array.
	var ans strings.Builder
	for _, v := range answer {
		ans.WriteString(fmt.Sprintf("%d", v))
	}

	// Print the final answer.
	fmt.Println(ans.String())
}

// 