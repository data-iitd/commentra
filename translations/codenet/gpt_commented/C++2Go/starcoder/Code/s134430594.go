package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define 'int' as 'int64' for larger integer support
type int int64

// Structure to represent a range with a value
type Ban struct {
	l, r, val int
}

// Constants for limits and size
const LIM = 20
const N = 2e5 + 7

// Sparse table for range minimum queries
var mn [LIM][N]int
// Precomputed powers of 2
var pw [N]int

// Function to initialize the sparse table
func init(a []int) {
	n := len(a)
	// Fill the first row of the sparse table
	for i := 0; i < n; i++ {
		mn[0][i] = a[i]
	}
	// Build the sparse table for range maximum queries
	for i := 0; i + 1 < LIM; i++ {
		for j := 0; j + (1 << (i + 1)) <= n; j++ {
			mn[i + 1][j] = max(mn[i][j], mn[i][j + (1 << i)])
		}
	}
	// Precompute powers of 2 for later use
	pw[1] = 0
	for i := 2; i < N; i++ {
		pw[i] = pw[i/2] + 1
	}
}

// Function to get the minimum value in the range [l, r]
func get(l, r int) int {
	r++
	p := pw[r - l]
	return min(mn[p][l], mn[p][r-(1<<p)])
}

func main() {
	// Optimize input/output
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	// Read the number of elements
	var n int
	fmt.Fscan(in, &n)
	a := make([]int, n)
	// Read the elements into the vector
	for i := range a {
		fmt.Fscan(in, &a[i])
	}

	// Vector to store the difference between index and value
	dl := make([]int, n)
	for i := 0; i < n; i++ {
		// Check if the value exceeds its index
		if a[i] > i {
			fmt.Fprintln(out, -1) // Output -1 if the condition fails
			return
		}
		// Calculate the difference and store it
		dl[i] = i - a[i]
	}

	// Initialize answer and vector to store ranges
	ans := 0
	bans := make([]Ban, 0)
	for i := 0; i < n; i++ {
		r := i
		// Extend the range while the next value is consecutive
		for r+1 < n && a[r]+1 == a[r+1] {
			r++
		}
		// Update the answer with the maximum value in the range
		ans += a[r]
		i = r // Move to the end of the current range
		// Store the range in the bans vector
		bans = append(bans, Ban{r - a[r], r, r - a[r]})
	}

	// Initialize the sparse table with the difference vector
	init(dl)
	// Check each range for validity
	for _, t := range bans {
		// If the minimum value in the range exceeds the stored value, output -1
		if get(t.l, t.r) > t.val {
			fmt.Fprintln(out, -1)
			return
		}
	}
	// Output the final answer
	fmt.Fprintln(out, ans)
}

