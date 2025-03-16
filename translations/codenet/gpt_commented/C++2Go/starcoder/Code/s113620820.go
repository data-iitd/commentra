
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Constant
const MAX_N = 4000

// Typedef
type ll int64

// Global variables
var wis [MAX_N]ll
var wsums [MAX_N + 1]ll
var dp [MAX_N][MAX_N + 1]ll
var ks [MAX_N][MAX_N + 1]int

// Function declaration
func main() {
	var n int
	var i, j, k int
	var mind, wsum ll
	var mink int

	// Read the number of items
	fmt.Scanf("%d", &n)

	// Initialize prefix sums
	wsums[0] = 0
	for i = 0; i < n; i++ {
		fmt.Scanf("%d", &wis[i])
		wsums[i + 1] = wsums[i] + wis[i]
	}

	// Initialize the dynamic programming and split point tables
	for i = 0; i < n; i++ {
		for j = 0; j <= n; j++ {
			dp[i][j] = LINF
			ks[i][j] = -1
		}
		dp[i][i + 1] = 0
		ks[i][i + 1] = i
	}

	// Fill the dynamic programming table
	for l := 2; l <= n; l++ {
		for i := 0; i <= n - l; i++ {
			j := i + l
			mind = LINF
			wsum = wsums[j] - wsums[i]
			for k := ks[i][j - 1]; k <= ks[i + 1][j]; k++ {
				d := dp[i][k] + dp[k][j] + wsum
				if mind > d {
					mind = d
					mink = k
				}
			}
			dp[i][j] = mind
			ks[i][j] = mink
		}
	}

	// Output the minimum cost to combine all items
	fmt.Printf("%d\n", dp[0][n])
}

