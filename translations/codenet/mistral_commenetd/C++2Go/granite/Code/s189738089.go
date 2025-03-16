

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Initialize dynamic programming vector dp with initial value INF for all indices
	dp := make([]int, 101000)
	for i := 0; i < 101000; i++ {
		dp[i] = 1 << 30
	}
	dp[0] = 0

	// Read input
	reader := bufio.NewReader(os.Stdin)
	N, _ := strconv.Atoi(readLine(reader)) // Number of elements in the array and the size of the window
	K, _ := strconv.Atoi(readLine(reader)) // Number of elements in the array and the size of the window
	h := make([]int, N)                      // Array of heights
	for i := 0; i < N; i++ {
		h[i], _ = strconv.Atoi(readLine(reader)) // Read each height from the input
	}

	// Dynamic programming calculation
	for i := 0; i < N; i++ { // Iterate through all indices i
		for j := 1; j <= K; j++ { // Iterate through all window sizes j
			// Update dp[i + j] with the minimum cost to reach this index with window size j
			if dp[i+j] > dp[i]+abs(h[i]-h[i+j]) {
				dp[i+j] = dp[i] + abs(h[i]-h[i+j])
			}
		}
	}

	// Output the result
	fmt.Println(dp[N-1]) // Print the minimum cost to reach the last index with window size K
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}
	return ""
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

