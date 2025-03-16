//go:generate echo "https://atcoder.jp/contests/dp/tasks/dp_a"
// This line is a Go generate command to download the problem statement from AtCoder.
// It is not necessary to understand its functionality for the given code.

package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
	"strconv"
)

// Define a custom scanner type for reading input efficiently.
type scanner struct{ *bufio.Scanner }

// NewScanner function creates a new instance of the scanner type.
func newScanner(r io.Reader) *scanner {
	s := bufio.NewScanner(r)
	s.Split(bufio.ScanWords)
	s.Buffer(nil, 100000000) // Set the buffer size to 100MB.
	return &scanner{s}
}

// Define helper functions for converting scanner output to int and int slice.
func (s *scanner) Int() int {
	s.Scan()
	n, _ := strconv.Atoi(s.Text())
	return n
}

func (s *scanner) IntSlice(l int) []int {
	if l == 0 {
		return []int{}
	}
	sl := make([]int, l, l)
	for i := range sl {
		sl[i] = s.Int()
	}
	return sl
}

// Define a helper function for calculating absolute value.
func iabs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// Define the main function to solve the problem.
func solve(n int, heights []int) int {
	// Initialize a table t to store the minimum cost to reach each index.
	t := make([]int, n+1, n+1)
	// Set the initial value of the table to maximum integer.
	for i := range t {
		t[i] = math.MaxInt64
	}
	// Set the base case, the cost to reach index 0 is 0.
	t[0] = 0

	// Iterate through the array from index 1 to n-1.
	for i := 1; i < n; i++ {
		// Calculate the cost to reach index i from the previous index.
		prevIndexCost := t[i-1]
		// Update the cost to reach index i if the difference between heights is beneficial.
		if heightsDiff := heights[i] - heights[i-1]; heightsDiff < 0 {
			prevIndexCost += heightsDiff
		} else {
			prevIndexCost -= heightsDiff
		}
		// Update the cost to reach index i if the difference between previous index is beneficial.
		if prevIndex := i - 2; prevIndex >= 0 {
			prevPrevIndexCost := t[prevIndex]
			heightsDiff := heights[i] - heights[prevIndex]
			if heightsDiff < 0 {
				prevPrevIndexCost += heightsDiff
			} else {
				prevPrevIndexCost -= heightsDiff
			}
			if prevIndexCost < t[i] {
				t[i] = prevIndexCost
			}
			if prevPrevIndexCost < t[i] {
				t[i] = prevPrevIndexCost
			}
		} else {
			// If the difference between previous index is not valid, only update the cost if the current difference is beneficial.
			if prevIndexCost < t[i] {
				t[i] = prevIndexCost
			}
		}
	}

	// Return the minimum cost to reach the last index.
	return t[n-1]
}

// Define the main function to read input and call the solve function.
func main() {
	// Initialize a scanner to read input from standard input.
	sc := newScanner(os.Stdin)
	// Read the number of test cases and iterate through each test case.
	n := sc.Int()
	for i := 0; i < n; i++ {
		// Read the number of heights and initialize an array to store them.
		heights := sc.IntSlice(n)
		// Call the solve function and print the result.
		ans := solve(n, heights)
		fmt.Println(ans)
	}
}

// The following comment can be added at the end of the code.
