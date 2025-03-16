package main

import (
	"fmt"
	"sort"
)

type Item struct {
	time int
	val  int
}

func main() {
	var N, T int
	fmt.Scan(&N, &T)

	// Initialize a slice to store time and value pairs
	timeValue := make([]Item, N+1)
	timeValue[0] = Item{-1, -1} // Dummy entry

	// Read the time and value pairs for each item
	for i := 1; i <= N; i++ {
		var time, val int
		fmt.Scan(&time, &val)
		timeValue[i] = Item{time, val}
	}

	// Sort the timeValue slice based on the value (val)
	sort.Slice(timeValue[1:], func(i, j int) bool {
		return timeValue[i+1].val < timeValue[j+1].val
	})

	// Initialize a 2D slice for dynamic programming
	dp := make([][]int, N+1)
	for i := range dp {
		dp[i] = make([]int, T)
		for j := range dp[i] {
			dp[i][j] = -1
		}
	}

	// Base case: If time is 0, the maximum value is 0 for all items
	for t := 0; t < T; t++ {
		dp[0][t] = 0
	}

	// Fill the dynamic programming table
	for n := 1; n <= N; n++ {
		// Base case: If no time is available, the maximum value is 0
		dp[n][0] = 0
		for t := 1; t < T; t++ {
			// If the current item's time exceeds the available time, skip the item
			if timeValue[n].time > t {
				dp[n][t] = dp[n-1][t]
			} else {
				// Choose the maximum between not taking the item and taking it
				dp[n][t] = max(dp[n-1][t], timeValue[n].val+dp[n-1][t-timeValue[n].time])
			}
		}
	}

	// Initialize the maximum value with the last item's value
	valAcum := timeValue[N].val
	t := T - 1
	maxVal := valAcum + dp[N-1][t]

	// Backtrack to find the maximum value considering previous items
	for n := N - 1; n > 0; n-- {
		valAcum += timeValue[n].val
		t -= timeValue[n+1].time

		// If time goes negative, break the loop
		if t < 0 {
			break
		} else {
			// Update the maximum value if a better option is found
			maxVal = max(maxVal, valAcum+dp[n-1][t])
		}
	}

	// Print the maximum value achievable within the given time
	fmt.Println(maxVal)
}

// Helper function to find the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>
