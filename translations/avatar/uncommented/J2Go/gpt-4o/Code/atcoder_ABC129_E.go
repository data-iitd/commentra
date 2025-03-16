package main

import (
	"fmt"
)

func main() {
	var M int = 1000000007
	var s string
	fmt.Scanln(&s)
	n := len(s)
	dp := make([][2]int, n+1)
	dp[0][0] = 1

	for i := 0; i < n; i++ {
		if s[i] == '0' {
			dp[i+1][0] = dp[i][0]
			dp[i+1][1] = dp[i][1]
		} else {
			dp[i+1][1] = (dp[i][0] + dp[i][1]) % M
		}
		if s[i] == '0' {
			dp[i+1][1] = (dp[i+1][1] + (dp[i][1]*2)%M) % M
		} else {
			dp[i+1][0] = (dp[i+1][0] + (dp[i][0]*2)%M) % M
			dp[i+1][1] = (dp[i+1][1] + (dp[i][1]*2)%M) % M
		}
	}

	result := (dp[n][0] + dp[n][1]) % M
	fmt.Println(result)
}

// <END-OF-CODE>
