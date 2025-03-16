
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

// Define 'int' as 'int64' for larger integer support
type int = int64

// Structure to represent a range with a value
type Ban struct {
	l, r, val int
}

func main() {
	// Optimize input/output
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	// Read the number of elements
	var n int
	fmt.Fscanf(reader, "%d\n", &n)
	a := make([]int, n)
	// Read the elements into the slice
	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d", &a[i])
	}

	// Slice to store the difference between index and value
	dl := make([]int, n)
	for i := 0; i < n; i++ {
		// Check if the value exceeds its index
		if a[i] > i {
			fmt.Fprintln(writer, "-1") // Output -1 if the condition fails
			writer.Flush()
			return
		}
		// Calculate the difference and store it
		dl[i] = i - a[i]
	}

	// Initialize answer and slice to store ranges
	ans := 0
	bans := make([]*Ban, 0, n)
	for i := 0; i < n; i++ {
		r := i
		// Extend the range while the next value is consecutive
		for r+1 < n && a[r]+1 == a[r+1] {
			r++
		}
		// Update the answer with the maximum value in the range
		ans += a[r]
		i = r // Move to the end of the current range
		// Store the range in the bans slice
		bans = append(bans, &Ban{l: r - a[r], r: r, val: r - a[r]})
	}

	// Initialize the sparse table with the difference slice
	sp := NewSparseTable(dl)
	// Check each range for validity
	for _, t := range bans {
		// If the minimum value in the range exceeds the stored value, output -1
		if sp.query(t.l, t.r) > t.val {
			fmt.Fprintln(writer, "-1")
			writer.Flush()
			return
		}
	}
	// Output the final answer
	fmt.Fprintln(writer, ans)
	writer.Flush()
}

// Sparse table for range minimum queries
type SparseTable struct {
	n   int
	log int
	dp  [][]int
}

// Function to initialize the sparse table
func NewSparseTable(a []int) *SparseTable {
	n := len(a)
	log := 0
	for 1<<log < n {
		log++
	}
	dp := make([][]int, log+1)
	for i := 0; i <= log; i++ {
		dp[i] = make([]int, n)
	}
	for i := 0; i < n; i++ {
		dp[0][i] = a[i]
	}
	for i := 1; i <= log; i++ {
		for j := 0; j+(1<<i) <= n; j++ {
			dp[i][j] = min(dp[i-1][j], dp[i-1][j+(1<<i-1)])
		}
	}
	return &SparseTable{n, log, dp}
}

// Function to get the minimum value in the range [l, r]
func (sp *SparseTable) query(l, r int) int {
	k := sp.log
	for k >= 0 && l+(1<<k) > r {
		k--
	}
	return min(sp.dp[k][l], sp.dp[k][r-(1<<k)+1])
}

// Function to get the minimum value between two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Translate the above Go code to Python and end with comment "