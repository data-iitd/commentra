package main

import (
	"fmt"
)

const mod = 1000000007

func main() {
	var l string
	fmt.Scan(&l)
	n := len(l)

	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, 2)
	}

	dp[0][0] = 1

	for i := 0; i < n; i++ {
		c := l[i]
		if c == '0' {
			dp[i+1][0] += dp[i][0]
			dp[i+1][1] += dp[i][1] * 3 % mod
		} else {
			dp[i+1][0] += dp[i][0] * 2 % mod
			dp[i+1][1] += dp[i][0]
			dp[i+1][1] += dp[i][1] * 3 % mod
		}
		dp[i+1][0] %= mod
		dp[i+1][1] %= mod
	}

	result := (dp[n][0] + dp[n][1]) % mod
	fmt.Println(result)
}
