// Import necessary packages
package main

import (
	"fmt"
	"sort"
)

// Define input function
func input() string {
	var s string
	fmt.Scan(&s)
	return s
}

// Define time_value struct
type time_value struct {
	time, val int
}

// Define slice of time_value struct
type time_value_slice []time_value

// Define sort function for time_value_slice
func (s time_value_slice) Len() int {
	return len(s)
}

func (s time_value_slice) Less(i, j int) bool {
	return s[i].val < s[j].val
}

func (s time_value_slice) Swap(i, j int) {
	s[i], s[j] = s[j], s[i]
}

// Define main function
func main() {
	// Initialize variables
	var N, T int
	fmt.Scan(&N, &T)

	// Initialize time_value slice
	time_value := make(time_value_slice, N+1)

	// Read time_value for each activity
	for i := 1; i <= N; i++ {
		fmt.Scan(&time_value[i].time, &time_value[i].val)
	}

	// Sort time_value based on their VAL (end time)
	sort.Sort(time_value)

	// Initialize dp matrix
	dp := make([][]int, N+1)
	for i := 0; i <= N; i++ {
		dp[i] = make([]int, T)
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
			if time_value[n].time > t {
				dp[n][t] = dp[n-1][t]
			} else {
				// If current activity's start time is less than or equal to t, then we can include it in the solution
				dp[n][t] = max(dp[n-1][t], time_value[n].val+dp[n-1][t-time_value[n].time])
			}
		}
	}

	// Calculate maximum value that can be obtained
	val_acum := time_value[N].val
	t := T - 1
	max_val := val_acum + dp[N-1][t]

	// Calculate maximum value by considering all activities
	for n := N - 1; n > 0; n-- {
		val_acum += time_value[n].val
		t -= time_value[n+1].time
		if t < 0 {
			break
		} else {
			max_val = max(max_val, val_acum+dp[n-1][t])
		}
	}

	// Print the maximum value
	fmt.Println(max_val)
}

// Define max function
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

