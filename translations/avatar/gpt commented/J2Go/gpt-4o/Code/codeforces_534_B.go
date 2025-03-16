package main

import (
	"fmt"
	"math"
)

func main() {
	// Read four integers from input: initial velocity (v1), final velocity (v2), time (t), and maximum change in velocity (d)
	var v1, v2, t, d int
	fmt.Scan(&v1, &v2, &t, &d)

	// Initialize a 2D slice dp to store the maximum values for each time step and velocity
	dp := make([][]int64, t-1)
	for i := range dp {
		dp[i] = make([]int64, 1150)
		for j := range dp[i] {
			dp[i][j] = -1e17 // Fill with a very small value to represent uninitialized states
		}
	}

	// Set the initial state for the first time step with the initial velocity
	dp[0][v1] = int64(v1)

	// Variable to accumulate the maximum sum of velocities
	var sum int64 = 0

	// Iterate through each time step from 1 to t-2
	for i := 1; i < t-1; i++ {
		// Iterate through each possible velocity
		for j := 0; j < 1150; j++ {
			// Update the dp array for increasing velocities
			for x := 0; x <= d; x++ {
				if j+x < 1150 {
					dp[i][j] = int64(math.Max(float64(dp[i][j]), float64(dp[i-1][j+x]+j)))
				}
			}
			// Update the dp array for decreasing velocities
			for x := d; x >= 0; x-- {
				if j-x >= 0 {
					dp[i][j] = int64(math.Max(float64(dp[i][j]), float64(dp[i-1][j-x]+j)))
				}
			}
		}
	}

	// Variable to store the final answer, initialized to the smallest possible value
	var ans int64 = math.MinInt64

	// Iterate through the last time step to find the maximum achievable velocity close to v2
	for i := t - 2; i < t-1; i++ {
		for j := 0; j < 1150; j++ {
			// Check if the current velocity is within the allowed range of v2
			if math.Abs(float64(j-v2)) <= float64(d) {
				ans = int64(math.Max(float64(ans), float64(dp[i][j]+v2)))
			}
		}
	}

	// Output the final answer
	fmt.Println(ans)
}

// <END-OF-CODE>
