package main

import (
	"fmt"
	"math"
)

func main() {
	// Create a Scanner object to read input from the user
	sc := new(Scanner)

	// Read four integers from input: initial velocity (v1), final velocity (v2), time (t), and maximum change in velocity (d)
	v1 := sc.nextInt()
	v2 := sc.nextInt()
	t := sc.nextInt()
	d := sc.nextInt()

	// Initialize a 2D array dp to store the maximum values for each time step and velocity
	dp := make([][]int, t-1)
	for i := range dp {
		dp[i] = make([]int, 1150)
	}

	// Fill the dp array with a very small value to represent uninitialized states
	for i := 0; i < t-1; i++ {
		for j := 0; j < 1150; j++ {
			dp[i][j] = -1e17
		}
	}

	// Set the initial state for the first time step with the initial velocity
	dp[0][v1] = v1

	// Variable to accumulate the maximum sum of velocities
	sum := 0

	// Iterate through each time step from 1 to t-2
	for i := 1; i < t-1; i++ {
		// Iterate through each possible velocity
		for j := 0; j < 1150; j++ {
			// Update the dp array for increasing velocities
			for x := 0; x <= d; x++ {
				if j+x < 1150 {
					dp[i][j] = int(math.Max(float64(dp[i][j]), float64(dp[i-1][j+x]+j)))
				}
			}
			// Update the dp array for decreasing velocities
			for x := d; x >= 0; x-- {
				if j-x >= 0 {
					dp[i][j] = int(math.Max(float64(dp[i][j]), float64(dp[i-1][j-x]+j)))
				}
			}
		}
	}

	// Variable to store the final answer, initialized to the smallest possible value
	ans := math.MinInt64

	// Iterate through the last time step to find the maximum achievable velocity close to v2
	for i := t - 2; i < t-1; i++ {
		for j := 0; j < 1150; j++ {
			// Check if the current velocity is within the allowed range of v2
			if math.Abs(float64(j-v2)) <= float64(d) {
				ans = int(math.Max(float64(ans), float64(dp[i][j]+v2)))
			}
		}
	}

	// Output the final answer
	fmt.Println(ans)
}

// 