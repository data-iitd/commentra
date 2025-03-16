
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
	in := FastReader{}

	// Read the number of elements
	n, _ := strconv.Atoi(in.next())

	// Create a TreeSet to keep track of available positions on the left
	left := make(map[int]bool)

	// Initialize an array to store the answers
	answer := make([]int, n)

	// Populate the TreeSet with indices from 0 to n-1
	for i := 0; i < n; i++ {
		left[i] = true
	}

	// Read the number of queries
	q, _ := strconv.Atoi(in.next())

	// Process each query
	for q > 0 {
		// Read the range [l, r] and the winning index
		l, _ := strconv.Atoi(in.next())
		r, _ := strconv.Atoi(in.next())
		win, _ := strconv.Atoi(in.next())

		// Update the answer array for all positions in the range [l, r]
		for i := l; i <= r; i++ {
			if left[i] {
				answer[i] = win
				delete(left, i)
			}
		}

		// Mark the winning index as available again
		left[win-1] = true
		q--
	}

	// Build the output string from the answer array
	ans := ""
	for i := 0; i < n; i++ {
		ans += strconv.Itoa(answer[i])
	}

	// Print the final answer
	fmt.Println(ans)
}

// FastReader class for efficient input reading
type FastReader struct {
	scanner *bufio.Scanner
	buffer  []byte
}

func (f *FastReader) next() string {
	if f.buffer == nil {
		f.scanner = bufio.NewScanner(os.Stdin)
		f.buffer = make([]byte, 0, 1024)
	}
	for f.scanner.Scan() {
		f.buffer = append(f.buffer, f.scanner.Bytes()...)
	}
	if len(f.buffer) == 0 {
		return ""
	}
	s := string(f.buffer)
	f.buffer = nil
	return s
}

func (f *FastReader) nextInt() int {
	return int(f.nextInt64())
}

func (f *FastReader) nextInt64() int64 {
	s := f.next()
	i, _ := strconv.ParseInt(s, 10, 64)
	return i
}

func (f *FastReader) nextFloat() float64 {
	s := f.next()
	f64, _ := strconv.ParseFloat(s, 64)
	return f64
}

func (f *FastReader) nextString() string {
	s := f.next()
	return strings.TrimSpace(s)
}

func (f *FastReader) nextLine() string {
	s := f.next()
	return strings.TrimSpace(s)
}

