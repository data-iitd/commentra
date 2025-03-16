package main

import (
	"fmt"
	"sort"
)

type Activity struct {
	time int
	val  int
}

func main() {
	var N, T int
	fmt.Scan(&N, &T)

	// Initialize time_value slice
	timeValue := make([]Activity, N+1)
	timeValue[0] = Activity{-1, -1} // Placeholder for 1-based index

	// Read time_value for each activity
	for i := 1; i <= N; i++ {
		var time, val int
		fmt.Scan(&time, &val)
		timeValue[i] = Activity{time, val}
	}

	// Sort timeValue based on their val (end time)
	sort.Slice(timeValue[1:], func(i, j int) bool {
		return timeValue[i+1].val < timeValue[j+1].val
	})

	// Initialize dp matrix
	dp := make([][]int, N+1)
	for i := range dp {
		dp[i] = make([]int, T)
		for j := range dp[i] {
			dp[i][j] = -1
		}
	}

	// Initialize first row and column of dp matrix
	for t := 0; t < T; t++ {
		dp[0][t] = 0
	}
	dp[0][0] = 0
	for n := 1; n <= N; n++ {
		dp[n][0] = 0
	}

	// Fill dp matrix
	for n := 1; n <= N; n++ {
		for t := 1; t < T; t++ {
			// If current activity's start time is greater than t, then we cannot include it in the solution
			if timeValue[n].time > t {
				dp[n][t] = dp[n-1][t]
			} else {
				// If current activity's start time is less than or equal to t, then we can include it in the solution
				dp[n][t] = max(dp[n-1][t], timeValue[n].val+dp[n-1][t-timeValue[n].time])
			}
		}
	}

	// Calculate maximum value that can be obtained
	valAcum := timeValue[N].val
	t := T - 1
	maxVal := valAcum + dp[N-1][t]

	// Calculate maximum value by considering all activities
	for n := N - 1; n > 0; n-- {
		valAcum += timeValue[n].val
		t -= timeValue[n+1].time
		if t < 0 {
			break
		} else {
			maxVal = max(maxVal, valAcum+dp[n-1][t])
		}
	}

	// Print the maximum value
	fmt.Println(maxVal)
}

// Helper function to get the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>
