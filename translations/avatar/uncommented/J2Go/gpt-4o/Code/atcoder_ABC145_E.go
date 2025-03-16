package main

import (
	"fmt"
	"sort"
)

func main() {
	var N, T int
	fmt.Scan(&N, &T)

	AB := make([][2]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&AB[i][0], &AB[i][1])
	}

	sort.Slice(AB, func(i, j int) bool {
		return AB[i][0] < AB[j][0]
	})

	dp := make([][]int, N+1)
	for i := range dp {
		dp[i] = make([]int, 6001)
	}

	for i := 1; i <= N; i++ {
		for timeAfterEat := 0; timeAfterEat <= 6000; timeAfterEat++ {
			dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i-1][timeAfterEat])
			time := AB[i-1][0]
			value := AB[i-1][1]
			if timeAfterEat-time >= 0 && timeAfterEat-time < T {
				dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i-1][timeAfterEat-time]+value)
			}
		}
	}

	maxValue := 0
	for _, v := range dp[N] {
		if v > maxValue {
			maxValue = v
		}
	}
	fmt.Println(maxValue)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>
