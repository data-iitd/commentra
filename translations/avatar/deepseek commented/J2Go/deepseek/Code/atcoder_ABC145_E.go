package main

import (
	"fmt"
	"sort"
)

func main() {
	var N, T int
	fmt.Scan(&N, &T)

	// Initialize the array to store dishes with their time and value
	AB := make([][2]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&AB[i][0], &AB[i][1])
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
			if dp[i][timeAfterEat] < dp[i-1][timeAfterEat] {
				dp[i][timeAfterEat] = dp[i-1][timeAfterEat]
			}

			// Get the time and value of the current dish
			time := AB[i-1][0]
			value := AB[i-1][1]

			// If the dish can be eaten after the given time, update the DP table
			if 0 <= timeAfterEat-time && timeAfterEat-time < T {
				if dp[i][timeAfterEat] < dp[i-1][timeAfterEat-time]+value {
					dp[i][timeAfterEat] = dp[i-1][timeAfterEat-time] + value
				}
			}
		}
	}

	// Print the maximum value that can be obtained within the time limit
	maxValue := 0
	for _, value := range dp[N] {
		if value > maxValue {
			maxValue = value
		}
	}
	fmt.Println(maxValue)
}

