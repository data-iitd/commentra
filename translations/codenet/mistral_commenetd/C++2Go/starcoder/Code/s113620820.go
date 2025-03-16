
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define constants
const MAX_N = 4000
const LINF = 1 << 60

// Define types and aliases (if any)
type ll int64

// Initialize global variables
var wis [MAX_N]ll
var wsums [MAX_N + 1]ll
var dp [MAX_N][MAX_N + 1]ll
var ks [MAX_N][MAX_N + 1]int

// Define subroutines (if any)

// main
func main() {
	// Read input
	var n int
	fmt.Scanf("%d\n", &n)

	// Initialize arrays
	for i := 0; i < n; i++ {
		fmt.Scanf("%d\n", &wis[i])
		wsums[i + 1] = wsums[i] + wis[i]
	}

	// Initialize 2D array dp and 2D array ks with default values
	for i := 0; i < n; i++ {
		for j := 0; j <= n; j++ {
			dp[i][j] = LINF
			ks[i][j] = -1
		}
		dp[i][i + 1] = 0
		ks[i][i + 1] = i
	}

	// Calculate dp and ks for all subarrays of size 2 to n
	for l := 2; l <= n; l++ {
		for i := 0; i <= n - l; i++ {
			j := i + l
			// Initialize variables for current subarray
			var mind ll
			var wsum ll
			var mink int

			// Find the minimum cost and index of the previous subarray that can be combined with the current subarray
			for k := ks[i][j - 1]; k <= ks[i + 1][j]; k++ {
				// Calculate the cost of combining the current subarray with the previous subarray
				d := dp[i][k] + dp[k][j] + wsums[j] - wsums[i]

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
	fmt.Printf("%d\n", dp[0][n])

	// Terminate the program
	return
}

