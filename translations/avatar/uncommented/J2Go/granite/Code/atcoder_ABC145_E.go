
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var (
	N int
	T int
	AB [][2]int
	dp [][6001]int
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initial int = 100000000
	scanner.Scan()
	N, _ = fmt.Sscanf(scanner.Text(), "%d %d", &N, &T)
	AB = make([][2]int, N)
	for i := 0; i < N; i++ {
		scanner.Scan()
		_, _ = fmt.Sscanf(scanner.Text(), "%d %d", &AB[i][0], &AB[i][1])
	}
	sort.Slice(AB, func(i, j int) bool {
		return AB[i][0] < AB[j][0]
	})
	dp = make([][6001]int, N+1)
	for i := 0; i <= N; i++ {
		for j := 0; j <= 6000; j++ {
			dp[i][j] = initial
		}
	}
	dp[0][0] = 0
	for i := 1; i <= N; i++ {
		for j := 0; j <= 6000; j++ {
			dp[i][j] = dp[i-1][j]
			if j-AB[i-1][0] >= 0 && j-AB[i-1][0] < T {
				dp[i][j] = max(dp[i][j], dp[i-1][j-AB[i-1][0]]+AB[i-1][1])
			}
		}
	}
	maxValue := initial
	for i := 0; i <= 6000; i++ {
		maxValue = max(maxValue, dp[N][i])
	}
	fmt.Println(maxValue)
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

// 