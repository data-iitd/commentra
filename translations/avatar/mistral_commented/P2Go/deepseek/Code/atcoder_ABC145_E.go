package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input := bufio.NewScanner(reader)
	input.Split(bufio.ScanWords)

	var N, T int
	var TIME, VAL int = 0, 1

	// Read N and T
	input.Scan()
	N, _ = strconv.Atoi(input.Text())
	input.Scan()
	T, _ = strconv.Atoi(input.Text())

	// Initialize time_value list
	time_value := make([][2]int, N+1)
	time_value[0] = [2]int{-1, -1}

	// Read time_value for each activity
	for i := 1; i <= N; i++ {
		input.Scan()
		time, _ := strconv.Atoi(input.Text())
		input.Scan()
		val, _ := strconv.Atoi(input.Text())
		time_value[i] = [2]int{time, val}
	}

	// Sort time_value based on their VAL (end time)
	sort.Slice(time_value, func(i, j int) bool {
		return time_value[i][VAL] < time_value[j][VAL]
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
			if time_value[n][TIME] > t {
				dp[n][t] = dp[n-1][t]
			} else {
				// If current activity's start time is less than or equal to t, then we can include it in the solution
				dp[n][t] = max(dp[n-1][t], time_value[n][VAL]+dp[n-1][t-time_value[n][TIME]])
			}
		}
	}

	// Calculate maximum value that can be obtained
	val_acum := time_value[N][VAL]
	t := T - 1
	max_val := val_acum + dp[N-1][t]

	// Calculate maximum value by considering all activities
	for n := N - 1; n > 0; n-- {
		val_acum += time_value[n][VAL]
		t -= time_value[n+1][TIME]
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

