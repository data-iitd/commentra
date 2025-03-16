/*
 * 2415.go: Sashimi
 */

package main

import (
	"fmt"
)

/*
 * constant
 */
const (
	MAX_N = 4000 // Maximum number of items
)

type (
	ll int64 // Define ll as a long long type
)

const (
	LINF = 1 << 60 // Define a large constant for initialization
)

/*
 * typedef
 */

/*
 * global variables
 */
var (
	wis   [MAX_N]ll // Arrays for weights, prefix sums, and dynamic programming table
	wsums [MAX_N + 1]ll
	dp    [MAX_N][MAX_N + 1]ll
	ks    [MAX_N][MAX_N + 1]int
)

/*
 * subroutines
 */

/*
 * main
 */
func main() {
	var n int // Number of items
	fmt.Scan(&n) // Read the number of items

	// Initialize prefix sums
	wsums[0] = 0 // Base case for prefix sums
	for i := 0; i < n; i++ {
		fmt.Scan(&wis[i]) // Read the weight of each item
		wsums[i + 1] = wsums[i] + wis[i] // Calculate prefix sums
	}

	// Initialize the dynamic programming and split point tables
	for i := 0; i < n; i++ {
		for j := 0; j <= n; j++ {
			dp[i][j] = LINF // Set initial values to LINF
			ks[i][j] = -1 // Initialize the best split point
		}
		dp[i][i + 1] = 0 // Base case: no cost to combine a single item
		ks[i][i + 1] = i // Base case: the split point is the item itself
	}

	// Fill the dynamic programming table
	for l := 2; l <= n; l++ { // Iterate over lengths of segments
		for i := 0; i < n; i++ { // Iterate over starting index i
			j := i + l // Calculate ending index j
			if j > n {
				break
			}
			mind := LINF // Initialize minimum cost for this segment
			wsum := wsums[j] - wsums[i] // Calculate the total weight of the segment
			mink := -1 // Initialize the best split point
			for k := ks[i][j - 1]; k <= ks[i + 1][j]; k++ { // Iterate over possible split points
				d := dp[i][k] + dp[k][j] + wsum // Calculate the cost of this split
				if mind > d {
					mind = d // Update minimum cost and best split point
					mink = k
				}
			}
			dp[i][j] = mind // Store the minimum cost for segment (i, j)
			ks[i][j] = mink // Store the best split point for segment (i, j)
		}
	}

	// Output the minimum cost to combine all items
	fmt.Println(dp[0][n]) // Print the result
}

