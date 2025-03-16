package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	// Read the number of elements
	fmt.Scan(&n)

	// Declare arrays to store input values, prefix sums, and suffix sums
	a := make([]int64, n+1)
	pre := make([]int64, n+1)
	last := make([]int64, n+1)

	// Read the input values into the array 'a'
	for i := 1; i <= n; i++ {
		fmt.Scan(&a[i])
	}

	sumpre := int64(0)
	sumlast := int64(0)

	// Calculate prefix sums and store them in 'pre' array
	for i := 1; i < n; i++ {
		sumpre += a[i]
		pre[i] = sumpre
		// Debugging output for prefix sums (commented out)
		// fmt.Printf("%d++\n", pre[i])
	}

	// Calculate suffix sums and store them in 'last' array
	for i := n; i > 1; i-- {
		sumlast += a[i]
		last[i] = sumlast
		// Debugging output for suffix sums (commented out)
		// fmt.Printf("%d+++\n", last[i])
	}

	// Initialize 'd' to a large value to find the minimum difference
	d := int64(math.MaxInt64)

	// Calculate the minimum absolute difference between prefix and suffix sums
	for i := 1; i < n; i++ {
		// Debugging output for the difference calculation (commented out)
		// fmt.Printf("%d\n", pre[i]-last[i+1])
		d = min(d, abs(pre[i]-last[i+1]))
	}

	// Output the minimum difference found
	fmt.Println(d)
}

// Helper function to calculate the absolute value
func abs(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}

// Helper function to find the minimum of two int64 values
func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}
