package main

import (
	"fmt"
)

func main() {
	const mod = 10e9 + 7
	var l string
	fmt.Scan(&l)
	n := len(l)
	dp := make([][2]int, n+1)
	dp[0][0] = 1

	for i, c := range l {
		if c == '0' {
			dp[i+1][0] += dp[i][0]
			dp[i+1][1] += dp[i][1] * 3
		} else {
			dp[i+1][0] += dp[i][0] * 2
			dp[i+1][1] += dp[i][0]
			dp[i+1][1] += dp[i][1] * 3
		}
		dp[i+1][0] %= int(mod)
		dp[i+1][1] %= int(mod)
	}

	result := (dp[n][0] + dp[n][1]) % int(mod)
	fmt.Println(result)
}

// <END-OF-CODE>
