package main

import (
	"fmt"
	"math"
)

func main() {
	// Create a scanner to read input from the console
	var N, L, R, QL, QR int
	fmt.Scan(&N, &L, &R, &QL, &QR)

	// Initialize a slice to hold the weights and a prefix sum slice
	W := make([]int, N) // Slice to store weights
	sum := make([]int, N+1) // Prefix sum slice

	// Read weights and compute the prefix sum
	for n := 0; n < N; n++ {
		fmt.Scan(&W[n]) // Read weight for each element
		sum[n+1] = sum[n] + W[n] // Update prefix sum
	}

	// Initialize a variable to track the minimum cost
	min := math.MaxInt64 // Start with the maximum possible value

	// Iterate over possible counts of elements assigned to the left side
	for firstR := 0; firstR <= N; firstR++ {
		lCount := firstR // Count of elements on the left
		rCount := N - lCount // Count of elements on the right

		// Calculate the candidate cost based on current left and right counts
		cand := sum[lCount]*L + (sum[N] - sum[lCount])*R

		// Calculate excess counts for left and right
		llCount := max(0, lCount-rCount-1) // Excess left count
		rrCount := max(0, rCount-lCount-1) // Excess right count

		// Add additional costs for excess elements
		cand += llCount * QL // Add cost for excess left elements
		cand += rrCount * QR // Add cost for excess right elements

		// Update the minimum cost found
		min = minInt(cand, min) // Keep track of the minimum cost
	}

	// Output the minimum cost
	fmt.Println(min) // Print the result
}

// Helper function to find the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Helper function to find the minimum of two integers
func minInt(a, b int) int {
	if a < b {
		return a
	}
	return b
}
