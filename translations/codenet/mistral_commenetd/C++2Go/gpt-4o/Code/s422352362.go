package main

import (
	"fmt"
	"math"
)

const MAX_N = 200005

func main() {
	var n int
	fmt.Scan(&n)

	// Initialize arrays
	a := make([]int64, MAX_N)
	pre := make([]int64, MAX_N)
	last := make([]int64, MAX_N)

	// Read the elements of the array
	for i := 1; i <= n; i++ {
		fmt.Scan(&a[i])
		// Initialize pre and last arrays
		pre[i] = pre[i-1] + a[i]
	}

	// Initialize sum of prefix and suffix arrays to zero
	var sumpre, sumlast int64

	// Calculate prefix sum
	for i := 1; i < n; i++ {
		sumpre += a[i]
		pre[i] = sumpre
	}

	// Calculate suffix sum
	for i := n; i > 0; i-- {
		sumlast += a[i]
		last[i] = sumlast
	}

	// Initialize difference as maximum int64 value
	d := int64(math.MaxInt64)

	// Find the minimum difference between prefix and suffix sums
	for i := 1; i < n; i++ {
		d = min(d, abs(pre[i]-last[i+1]))
	}

	// Print the minimum difference
	fmt.Println(d)
}

// Helper function to calculate absolute value
func abs(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}

// Helper function to find minimum of two int64 values
func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}
