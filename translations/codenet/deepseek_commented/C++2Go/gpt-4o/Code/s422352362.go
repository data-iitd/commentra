package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the value of n from the standard input.

	a := make([]int64, n+1) // Declare a slice to store the input values.
	pre := make([]int64, n+1) // Declare a slice to store the prefix sums.
	last := make([]int64, n+1) // Declare a slice to store the suffix sums.

	for i := 1; i <= n; i++ { // Loop to read n integers into the slice a.
		fmt.Scan(&a[i]) // Read the i-th integer and store it in a[i].
	}

	sumpre, sumlast := int64(0), int64(0) // Declare variables to store the cumulative sums of prefix and suffix.
	for i := 1; i < n; i++ { // Loop to calculate the prefix sums.
		sumpre += a[i] // Add the current element to the cumulative sum.
		pre[i] = sumpre // Store the cumulative sum in the pre slice.
	}

	for i := n; i > 1; i-- { // Loop to calculate the suffix sums.
		sumlast += a[i] // Add the current element to the cumulative sum.
		last[i] = sumlast // Store the cumulative sum in the last slice.
	}

	d := int64(math.MaxInt64) // Declare a variable to store the minimum difference and initialize it to a large number.
	for i := 1; i < n; i++ { // Loop to find the minimum absolute difference between prefix and suffix sums.
		d = min(d, abs(pre[i]-last[i+1])) // Update the minimum difference if a smaller one is found.
	}

	fmt.Println(d) // Print the minimum difference found.
}

// Helper function to calculate the absolute value.
func abs(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}

// Helper function to find the minimum of two int64 values.
func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}
