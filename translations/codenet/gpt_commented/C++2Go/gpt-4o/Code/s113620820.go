package main

import (
	"fmt"
	"math"
)

const MAX_N = 4000 // Maximum number of items
const LINF = 1 << 60 // Define a large constant for initialization

var wis [MAX_N]int64 // Array for weights
var wsums [MAX_N + 1]int64 // Prefix sums
var dp [MAX_N][MAX_N + 1]int64 // Dynamic programming table
var ks [MAX_N][MAX_N + 1]int // Array to store optimal split points

func main() {
	var n int // Number of items
	fmt.Scan(&n) // Read the number of items

	// Initialize prefix sums
	wsums[0] = 0 // Base case for prefix sums
	for i := 0; i < n; i++ {
		fmt.Scan(&wis[i]) // Read the weight of each item
		wsums[i+1] = wsums[i] + wis[i] // Calculate prefix sums
	}

	// Initialize the dynamic programming and split point tables
	for i := 0; i < n; i++ {
		for j := 0; j <= n; j++ {
			dp[i][j] = LINF // Set initial values to LINF
			ks[i][j] = -1 // Set initial values to -1
		}
		dp[i][i+1] = 0 // Base case: no cost to combine a single item
		ks[i][i+1] = i // Base case: the split point is the item itself
	}

	// Fill the dynamic programming table
	for l := 2; l <= n; l++ { // Iterate over lengths of segments
		for i, j := 0, l; j <= n; i, j = i+1, j+1 { // Iterate over starting index i and ending index j
			mind := LINF // Initialize minimum cost for this segment
			wsum := wsums[j] - wsums[i] // Calculate the total weight of the segment
			mink := -1 // Initialize the best split point
			for k := ks[i][j-1]; k <= ks[i+1][j]; k++ { // Iterate over possible split points
				d := dp[i][k] + dp[k][j] + wsum // Calculate the cost of this split
				if mind > d {
					mind = d // Update minimum cost
					mink = k // Update best split point
				}
			}
			dp[i][j] = mind // Store the minimum cost for segment (i, j)
			ks[i][j] = mink // Store the best split point for segment (i, j)
		}
	}

	// Output the minimum cost to combine all items
	fmt.Println(dp[0][n]) // Print the result
}
