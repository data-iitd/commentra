package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define input function
func input() string {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	return strings.TrimSpace(input)
}

func main() {
	// Read input
	var N, T int
	fmt.Sscanf(input(), "%d %d", &N, &T)

	// Initialize time_value list
	time_value := make([][]int, N+1)
	for i := 0; i < N+1; i++ {
		time_value[i] = make([]int, 2)
	}

	// Read time_value for each activity
	for i := 1; i < N+1; i++ {
		fmt.Sscanf(input(), "%d %d", &time_value[i][0], &time_value[i][1])
	}

	// Sort time_value based on their VAL (end time)
	for i := 1; i < N+1; i++ {
		for j := i; j > 0 && time_value[j][1] < time_value[j-1][1]; j-- {
			time_value[j], time_value[j-1] = time_value[j-1], time_value[j]
		}
	}

	// Initialize dp matrix
	dp := make([][]int, N+1)
	for i := 0; i < N+1; i++ {
		dp[i] = make([]int, T+1)
	}

	// Initialize first row and column of dp matrix
	for t := 0; t < T; t++ {
		dp[0][t] = 0
	}
	dp[0][0] = 0
	for n := 1; n < N+1; n++ {
		dp[n][0] = 0
	}

	// Fill dp matrix
	for n := 1; n < N+1; n++ {
		for t := 1; t < T; t++ {
			// If current activity's start time is greater than t, then we cannot include it in the solution
			if time_value[n][0] > t {
				dp[n][t] = dp[n-1][t]
			}
			// If current activity's start time is less than or equal to t, then we can include it in the solution
			else {
				dp[n][t] = max(dp[n-1][t], time_value[n][1] + dp[n-1][t-time_value[n][0]])
			}
		}
	}

	// Calculate maximum value that can be obtained
	val_acum := time_value[N][1]
	t := T - 1
	max_val := val_acum + dp[N-1][t]

	// Calculate maximum value by considering all activities
	for n := N - 1; n > 0; n-- {
		val_acum += time_value[n][1]
		t -= time_value[n+1][0]
		if t < 0 {
			break
		} else {
			max_val = max(max_val, val_acum+dp[n-1][t])
		}
	}

	// Print the maximum value
	fmt.Println(max_val)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

