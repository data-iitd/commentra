
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Initialize a dp slice to store the minimum cost to reach each step
	dp := make([]int, 101000)
	for i := range dp {
		dp[i] = 1 << 30 // Set the initial value to infinity
	}
	dp[0] = 0 // Base case: cost to reach the first step is 0

	// Read the number of steps (N) and the maximum jump distance (K)
	N, K := readInt(), readInt()
	h := make([]int, N) // Slice to store the heights of the steps
	for i := 0; i < N; i++ {
		h[i] = readInt() // Read the heights of the steps
	}

	// Dynamic programming to calculate the minimum cost to reach each step
	for i := 0; i < N; i++ {
		for j := 1; j <= K; j++ {
			// Update the minimum cost to reach step i + j
			if dp[i+j] > dp[i]+abs(h[i]-h[i+j]) {
				dp[i+j] = dp[i] + abs(h[i]-h[i+j])
			}
		}
	}

	// Output the minimum cost to reach the last step
	fmt.Println(dp[N-1])
}

func readInt() int {
	// Read an integer from the input
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

// Translate the above Go code to Python and end with comment "