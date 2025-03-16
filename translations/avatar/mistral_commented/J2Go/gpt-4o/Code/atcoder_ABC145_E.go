package main

import (
	"fmt"
	"sort"
)

func main() {
	var N, T int
	fmt.Scan(&N, &T)

	// Initialize a slice to store the start time and value of each activity
	AB := make([][2]int, N)

	// Read the start time and value of each activity
	for i := 0; i < N; i++ {
		fmt.Scan(&AB[i][0], &AB[i][1])
	}

	// Sort the AB slice based on the start time of each activity
	sort.Slice(AB, func(i, j int) bool {
		return AB[i][0] < AB[j][0]
	})

	// Initialize a 2D slice dp to store the maximum value that can be obtained up to a certain time after eating an activity
	dp := make([][]int, N+1)
	for i := range dp {
		dp[i] = make([]int, 6001)
	}

	// For each activity i from 1 to N, calculate the maximum value that can be obtained
	for i := 1; i <= N; i++ {
		for timeAfterEat := 0; timeAfterEat <= 6000; timeAfterEat++ {
			// Set the value of dp[i][timeAfterEat] to be the maximum of its previous value
			dp[i][timeAfterEat] = dp[i-1][timeAfterEat]

			// If the timeAfterEat is within the time limit T after the start time of activity i
			time := AB[i-1][0]
			value := AB[i-1][1]
			if timeAfterEat >= time && timeAfterEat < time+T {
				dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i-1][timeAfterEat-time]+value)
			}
		}
	}

	// Find the maximum value that can be obtained after eating all the activities
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
