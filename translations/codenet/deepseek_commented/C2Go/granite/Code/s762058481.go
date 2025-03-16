
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function to return the smaller value between two integers
func chmin(a, b int) int {
	if a > b {
		return b
	} else {
		return a
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())-1]) // Read the number of elements
	dp := make([]int, n)                                                 // Declare the dp array
	h := make([]int, n)                                                  // Declare the h array
	for i := 0; i < n; i++ {
		dp[i] = 10000 // Initialize the dp array to a large value
	}

	for i := 0; i < n; i++ {
		h[i], _ = strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())-1]) // Read the heights into the h array
	}

	dp[0] = 0 // Starting point with no cost
	for i := 1; i < n; i++ {
		if i == 1 {
			dp[1] = abs(h[1]-h[0]) // Cost to reach the first step
		} else {
			dp[i] = chmin(dp[i-1]+abs(h[i]-h[i-1]), dp[i-2]+abs(h[i]-h[i-2])) // Calculate the minimum cost to reach the current step
		}
	}
	fmt.Println(dp[n-1]) // Print the minimum cost to reach the last step
	// 