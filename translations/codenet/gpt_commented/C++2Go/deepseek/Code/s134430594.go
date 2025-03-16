package main

import (
	"fmt"
	"math"
)

// Define 'int' as 'int64' for larger integer support
type int int64

// Structure to represent a range with a value
type Ban struct {
	l   int // Left index of the range
	r   int // Right index of the range
	val int // Value associated with the range
}

// Constants for limits and size
const (
	LIM = 20
	N   = 2e5 + 7
)

// Sparse table for range minimum queries
var mn [LIM][N]int
// Precomputed powers of 2
var pw [N]int

// Function to initialize the sparse table
func initSparseTable(a []int) {
	n := len(a)
	// Fill the first row of the sparse table
	for i := 0; i < n; i++ {
		mn[0][i] = int(a[i])
	}
	// Build the sparse table for range maximum queries
	for i := 0; i+1 < LIM; i++ {
		for j := 0; j+(1<<(i+1)) <= n; j++ {
			mn[i+1][j] = min(mn[i][j], mn[i][j+(1<<i)])
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
	p := pw[r-l]
	return min(mn[p][l], mn[p][r-(1<<p)])
}

func main() {
	// Read the number of elements
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	// Read the elements into the slice
	for i := range a {
		fmt.Scan(&a[i])
	}

	// Slice to store the difference between index and value
	dl := make([]int, n)
	for i := 0; i < n; i++ {
		// Check if the value exceeds its index
		if a[i] > i {
			fmt.Println(-1) // Output -1 if the condition fails
			return
		}
		// Calculate the difference and store it
		dl[i] = i - a[i]
	}

	// Initialize answer and slice to store ranges
	ans := int(0)
	bans := []Ban{}
	for i := 0; i < n; i++ {
		r := i
		// Extend the range while the next value is consecutive
		for r+1 < n && a[r]+1 == a[r+1] {
			r++
		}
		// Update the answer with the maximum value in the range
		ans += a[r]
		i = r // Move to the end of the current range
		// Append the range to the bans slice
		bans = append(bans, Ban{r - a[r], r, r - a[r]})
	}

	// Initialize the sparse table with the difference slice
	initSparseTable(dl)
	// Check each range for validity
	for _, t := range bans {
		// If the minimum value in the range exceeds the stored value, output -1
		if get(t.l, t.r) > t.val {
			fmt.Println(-1)
			return
		}
	}
	// Output the final answer
	fmt.Println(ans)
}

// Helper function to get the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

