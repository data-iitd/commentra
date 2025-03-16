
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a scanner to read input from the user
	scanner := bufio.NewScanner(os.Stdin)

	// Read four integers from input: initial velocity (v1), final velocity (v2), time (t), and maximum change in velocity (d)
	scanner.Scan()
	v1, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	v2, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	t, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	d, _ := strconv.Atoi(scanner.Text())

	// Initialize a 2D array dp to store the maximum values for each time step and velocity
	dp := make([][]int64, t-1)
	for i := 0; i < t-1; i++ {
		dp[i] = make([]int64, 1150)
		for j := 0; j < 1150; j++ {
			dp[i][j] = -1000000000
		}
	}

	// Set the initial state for the first time step with the initial velocity
	dp[0][v1] = v1

	// Variable to accumulate the maximum sum of velocities
	sum := int64(0)

	// Iterate through each time step from 1 to t-2
	for i := 1; i < t-1; i++ {
		// Iterate through each possible velocity
		for j := 0; j < 1150; j++ {
			// Update the dp array for increasing velocities
			for x := 0; x <= d; x++ {
				if j+x < 1150 {
					dp[i][j] = max(dp[i][j], dp[i-1][j+x]+int64(j))
				}
			}
			// Update the dp array for decreasing velocities
			for x := d; x >= 0; x-- {
				if j-x >= 0 {
					dp[i][j] = max(dp[i][j], dp[i-1][j-x]+int64(j))
				}
			}
		}
	}

	// Variable to store the final answer, initialized to the smallest possible value
	ans := int64(-1000000000)

	// Iterate through the last time step to find the maximum achievable velocity close to v2
	for i := t - 2; i < t-1; i++ {
		for j := 0; j < 1150; j++ {
			// Check if the current velocity is within the allowed range of v2
			if abs(int64(j)-int64(v2)) <= int64(d) {
				ans = max(ans, dp[i][j]+int64(v2))
			}
		}
	}

	// Output the final answer
	fmt.Println(ans)
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func abs(a int64) int64 {
	if a < 0 {
		return -a
	}
	return a
}

// END-OF-CODE