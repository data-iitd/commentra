
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

// Minimum update function
<<<<<<< HEAD
func chmin(a, b int) int {
	// Minimum update function
	if a > b {
		return b
	}
	return a
=======
func chmin(a, b int) {
	// Minimum update function
	if a > b {
		a = b
	}
	return
>>>>>>> 98c87cb78a (data updated)
}

func main() {
	// Read input
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanln(reader, &N, &K)
	h := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscanln(reader, &h[i])
	}

	// Initialize dynamic programming vector dp with initial value INF for all indices
<<<<<<< HEAD
	dp := make([]int, N)
	for i := 0; i < N; i++ {
=======
	dp := make([]int, 101000)
	for i := 0; i < 101000; i++ {
>>>>>>> 98c87cb78a (data updated)
		dp[i] = 1000000000
	}
	dp[0] = 0

	// Dynamic programming calculation
	for i := 0; i < N; i++ { // Iterate through all indices i
		for j := 1; j <= K; j++ { // Iterate through all window sizes j
			// Update dp[i + j] with the minimum cost to reach this index with window size j
<<<<<<< HEAD
			dp[i+j] = chmin(dp[i+j], dp[i] + abs(h[i] - h[i+j]))
=======
			chmin(dp[i+j], dp[i]+abs(h[i]-h[i+j]))
>>>>>>> 98c87cb78a (data updated)
		}
	}

	// Output the result
	fmt.Println(dp[N-1]) // Print the minimum cost to reach the last index with window size K
}

