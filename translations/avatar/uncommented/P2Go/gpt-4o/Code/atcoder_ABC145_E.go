package main

import (
	"fmt"
	"sort"
)

type TimeValue struct {
	time int
	val  int
}

func main() {
	var N, T int
	fmt.Scan(&N, &T)

	timeValue := make([]TimeValue, N+1)
	for i := 1; i <= N; i++ {
		fmt.Scan(&timeValue[i].time, &timeValue[i].val)
	}

	// Sort by value
	sort.Slice(timeValue[1:], func(i, j int) bool {
		return timeValue[i+1].val < timeValue[j+1].val
	})

	dp := make([][]int, N+1)
	for i := range dp {
		dp[i] = make([]int, T)
	}

	for t := 0; t < T; t++ {
		dp[0][t] = 0
	}
	for n := 1; n <= N; n++ {
		dp[n][0] = 0
		for t := 1; t < T; t++ {
			if timeValue[n].time > t {
				dp[n][t] = dp[n-1][t]
			} else {
				dp[n][t] = max(dp[n-1][t], timeValue[n].val+dp[n-1][t-timeValue[n].time])
			}
		}
	}

	valAcum := timeValue[N].val
	t := T - 1
	maxVal := valAcum + dp[N-1][t]
	for n := N - 1; n > 0; n-- {
		valAcum += timeValue[n].val
		t -= timeValue[n+1].time
		if t < 0 {
			break
		} else {
			maxVal = max(maxVal, valAcum+dp[n-1][t])
		}
	}
	fmt.Println(maxVal)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>
