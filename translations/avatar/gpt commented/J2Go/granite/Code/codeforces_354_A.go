
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a scanner to read input from the console
	in := bufio.NewReader(os.Stdin)

	// Read the number of elements (N) and the values for L, R, QL, QR
	var N, L, R, QL, QR int
	fmt.Fscanf(in, "%d%d%d%d%d", &N, &L, &R, &QL, &QR)

	// Initialize an array to hold the weights and a prefix sum array
	W := make([]int, N) // Array to store weights
	sum := make([]int, N+1) // Prefix sum array

	// Read weights and compute the prefix sum
	for n := 0; n < N; n++ {
		fmt.Fscanf(in, "%d", &W[n]) // Read weight for each element
		sum[n+1] = sum[n] + W[n] // Update prefix sum
	}

	// Initialize a variable to track the minimum cost
	min := int64(1e18) // Start with the maximum possible value

	// Iterate over possible counts of elements assigned to the left side
	for firstR := 0; firstR <= N; firstR++ {
		lCount := firstR // Count of elements on the left
		rCount := N - lCount // Count of elements on the right

		// Calculate the candidate cost based on current left and right counts
		cand := int64(sum[lCount]) * int64(L) + int64(sum[N]-sum[lCount]) * int64(R)

		// Calculate excess counts for left and right
		llCount := int(max(0, lCount-rCount-1)) // Excess left count
		rrCount := int(max(0, rCount-lCount-1)) // Excess right count

		// Add additional costs for excess elements
		cand += int64(llCount) * int64(QL) // Add cost for excess left elements
		cand += int64(rrCount) * int64(QR) // Add cost for excess right elements

		// Update the minimum cost found
		if cand < min {
			min = cand // Update the minimum cost
		}
	}

	// Output the minimum cost
	fmt.Println(min) // Print the result
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// END-OF-CODE