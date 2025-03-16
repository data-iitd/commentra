//go:generate echo "https://atcoder.jp/contests/dp/tasks/dp_a"
package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
	"strconv"
)

// scanner wraps bufio.Scanner to provide convenient methods for reading input.
type scanner struct{ *bufio.Scanner }

// newScanner initializes a new scanner with a specified input reader.
func newScanner(r io.Reader) *scanner {
	s := bufio.NewScanner(r)
	s.Split(bufio.ScanWords) // Set the scanner to split input by words.
	s.Buffer(nil, 100000000)  // Set a large buffer size for the scanner.
	return &scanner{s}
}

// Int reads the next integer from the input.
func (s *scanner) Int() int {
	s.Scan() // Scan the next token.
	n, _ := strconv.Atoi(s.Text()) // Convert the scanned text to an integer.
	return n
}

// IntSlice reads a slice of integers from the input with the specified length.
func (s *scanner) IntSlice(l int) []int {
	if l == 0 {
		return []int{} // Return an empty slice if length is zero.
	}
	sl := make([]int, l, l) // Create a slice of the specified length.
	for i := range sl {
		sl[i] = s.Int() // Fill the slice with integers from input.
	}
	return sl
}

// iabs returns the absolute value of an integer.
func iabs(x int) int {
	if x < 0 {
		return -x // Return the negation if x is negative.
	}
	return x // Return x if it is non-negative.
}

// solve computes the minimum cost to reach the last height using dynamic programming.
func solve(n int, heights []int) int {
	t := make([]int, n+1, n+1) // Create a slice to store minimum costs.
	for i := range t {
		t[i] = math.MaxInt64 // Initialize all costs to a large value.
	}

	t[0] = 0 // The cost to reach the first height is zero.
	for i := 1; i < n; i++ {
		// Calculate the cost to reach the current height from the previous height.
		if v := t[i-1] + iabs(heights[i]-heights[i-1]); v < t[i] {
			t[i] = v // Update the cost if it's lower.
		}
		// Calculate the cost to reach the current height from two heights back.
		if 1 < i {
			if v := t[i-2] + iabs(heights[i]-heights[i-2]); v < t[i] {
				t[i] = v // Update the cost if it's lower.
			}
		}
	}

	return t[n-1] // Return the minimum cost to reach the last height.
}

// main function to execute the program.
func main() {
	sc := newScanner(os.Stdin) // Initialize the scanner for standard input.
	n := sc.Int() // Read the number of heights.
	heights := sc.IntSlice(n) // Read the heights into a slice.
	ans := solve(n, heights) // Solve for the minimum cost.
	fmt.Println(ans) // Print the result.
}
