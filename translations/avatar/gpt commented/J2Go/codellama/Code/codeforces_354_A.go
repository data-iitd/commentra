package main

import (
	"fmt"
	"math"
)

func main() {
	// Create a Scanner object to read input from the console
	in := new(Scanner)

	// Read the number of elements (N) and the values for L, R, QL, QR
	var N int // Number of elements
	var L int // Cost for left elements
	var R int // Cost for right elements
	var QL int // Additional cost for left excess
	var QR int // Additional cost for right excess

	// Initialize an array to hold the weights and a prefix sum array
	W := make([]int, N) // Array to store weights
	sum := make([]int, N+1) // Prefix sum array

	// Read weights and compute the prefix sum
	for n := 0; n < N; n++ {
		W[n] = in.NextInt() // Read weight for each element
		sum[n+1] = sum[n] + W[n] // Update prefix sum
	}

	// Initialize a variable to track the minimum cost
	min := int(math.MaxInt64) // Start with the maximum possible value

	// Iterate over possible counts of elements assigned to the left side
	for firstR := 0; firstR <= N; firstR++ {
		lCount := firstR // Count of elements on the left
		rCount := N - lCount // Count of elements on the right

		// Calculate the candidate cost based on current left and right counts
		cand := sum[lCount] * L + (sum[N] - sum[lCount]) * R

		// Calculate excess counts for left and right
		llCount := int(math.Max(0, float64(lCount-rCount-1))) // Excess left count
		rrCount := int(math.Max(0, float64(rCount-lCount-1))) // Excess right count

		// Add additional costs for excess elements
		cand += llCount * QL // Add cost for excess left elements
		cand += rrCount * QR // Add cost for excess right elements

		// Update the minimum cost found
		min = int(math.Min(float64(cand), float64(min))) // Keep track of the minimum cost
	}

	// Output the minimum cost
	fmt.Println(min) // Print the result
}

// 