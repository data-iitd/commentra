package main

import (
	"fmt"
	"sort"
)

func main() {
	var N, T int
	fmt.Scan(&N, &T)

	time_value := make([][2]int, N + 1)
	for i := 1; i <= N; i++ {
		fmt.Scan(&time_value[i][0], &time_value[i][1])
	}

	sort.Slice(time_value, func(i, j int) bool {
		return time_value[i][1] > time_value[j][1]
	})

	dp := make([][]int, N + 1)
	for i := range dp {
		dp[i] = make([]int, T)
	}

	for t := 0; t < T; t++ {
		dp[0][t] = 0
	}

	for n := 1; n <= N; n++ {
		dp[n][0] = 0
		for t := 1; t < T; t++ {
			if time_value[n][0] > t {
				dp[n][t] = dp[n - 1][t]
			} else {
				dp[n][t] = max(dp[n - 1][t], time_value[n][1]+dp[n - 1][t - time_value[n][0]])
			}
		}
	}

	val_acum := time_value[N][1]
	t := T - 1
	max_val := val_acum + dp[N - 1][t]

	for n := N - 1; n > 0; n-- {
		val_acum += time_value[n][1]
		t -= time_value[n + 1][0]
		if t < 0 {
			break
		} else {
			max_val = max(max_val, val_acum+dp[n - 1][t])
		}
	}

	fmt.Println(max_val)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

