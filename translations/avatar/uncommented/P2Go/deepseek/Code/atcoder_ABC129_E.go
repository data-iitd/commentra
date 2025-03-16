package main

import (
	"bufio"
	"fmt"
	"os"
)

const mod = 1000000007

func main() {
	reader := bufio.NewReader(os.Stdin)
	l, _, _ := reader.ReadLine()
	n := len(l)
	dp := make([][2]int, n+1)
	dp[0][0] = 1

	for i := 0; i < n; i++ {
		if l[i] == '0' {
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

	fmt.Println((dp[n][0] + dp[n][1]) % mod)
}

