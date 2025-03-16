package main

import (
	"fmt"
	"math"
)

const MAX_N = 4000
const LINF = 1 << 60

func main() {
	var n int
	fmt.Scan(&n)

	// Initialize arrays
	wis := make([]int64, MAX_N)
	wsums := make([]int64, MAX_N+1)
	dp := make([][]int64, MAX_N)
	ks := make([][]int, MAX_N)

	for i := 0; i < n; i++ {
		dp[i] = make([]int64, MAX_N+1)
		ks[i] = make([]int, MAX_N+1)
	}

	// Read weights and calculate prefix sums
	for i := 0; i < n; i++ {
		fmt.Scan(&wis[i])
		wsums[i+1] = wsums[i] + wis[i]
	}

	// Initialize dp and ks with default values
	for i := 0; i < n; i++ {
		for j := 0; j <= n; j++ {
			dp[i][j] = LINF
			ks[i][j] = -1
		}
		dp[i][i+1] = 0
		ks[i][i+1] = i
	}

	// Calculate dp and ks for all subarrays of size 2 to n
	for l := 2; l <= n; l++ {
		for i := 0; j := l; j <= n; i++ {
			// Initialize variables for current subarray
			mind := LINF
			wsum := wsums[j] - wsums[i]
			mink := -1

			// Find the minimum cost and index of the previous subarray that can be combined with the current subarray
			for k := ks[i][j-1]; k <= ks[i+1][j]; k++ {
				// Calculate the cost of combining the current subarray with the previous subarray
				d := dp[i][k] + dp[k][j] + wsum

				// Update minimum cost and index if found a better combination
				if mind > d {
					mind = d
					mink = k
				}
			}

			// Update dp and ks for the current subarray
			dp[i][j] = mind
			ks[i][j] = mink
		}
	}

	// Print the result
	fmt.Println(dp[0][n])
}
