package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// <START-OF-CODE>

// TaskD...
type TaskD struct {
}

// NewTaskD...
func NewTaskD() *TaskD {
	return &TaskD{}
}

// Solve...
func (t *TaskD) Solve(testNumber int, in io.Reader, out io.Writer) {
	// Read the number of elements and the modulus value
	n, m := readInt(in), readInt(in)

	// Read the array of integers
	a := readIntSlice(in, n)

	// Initialize a HashMap to store counts of remainders
	dp := make(map[int]int)
	ans := 0
	base := 0

	// Iterate through the array to calculate the answer
	for i := 0; i < n; i++ {
		// Update the base remainder
		base = (base - a[i]%m + m) % m

		// Merge the current remainder into the HashMap
		dp[base+a[i]]++

		// Add the count of occurrences of the current base remainder to the answer
		ans += dp[base]
	}

	// Output the final answer
	fmt.Fprintln(out, ans)
}

// readInt reads a single integer from the input
func readInt(in io.Reader) int {
	var i int
	fmt.Fscanf(in, "%d\n", &i)
	return i
}

// readIntSlice reads a slice of integers from the input
func readIntSlice(in io.Reader, n int) []int {
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = readInt(in)
	}
	return a
}

// 