package main

import (
	"fmt"
	"sort"
)

func main() {
	var N, T int
	fmt.Scan(&N, &T) // Read the number of dishes and the time limit for eating dishes

	// Initialize the slice to store dishes with their time and value
	AB := make([][2]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&AB[i][0], &AB[i][1]) // Read the time and value for each dish
	}

	// Sort the dishes based on their eating time
	sort.Slice(AB, func(i, j int) bool {
		return AB[i][0] < AB[j][0]
	})

	// Initialize the DP table with dimensions (N+1) x 6001
	dp := make([][]int, N+1)
	for i := range dp {
		dp[i] = make([]int, 6001)
	}

	// Fill the DP table
	for i := 1; i <= N; i++ {
		for timeAfterEat := 0; timeAfterEat <= 6000; timeAfterEat++ {
			// Inherit the maximum value from the previous dish
			dp[i][timeAfterEat] = dp[i-1][timeAfterEat]

			// Get the time and value of the current dish
			time := AB[i-1][0]
			value := AB[i-1][1]

			// If the dish can be eaten after the given time, update the DP table
			if timeAfterEat-time >= 0 && timeAfterEat-time < T {
				dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i-1][timeAfterEat-time]+value)
			}
		}
	}

	// Find the maximum value that can be obtained within the time limit
	maxValue := 0
	for _, v := range dp[N] {
		if v > maxValue {
			maxValue = v
		}
	}
	fmt.Println(maxValue)
}

// Helper function to find the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
