
package main

import (
	"bufio"
	"fmt"
	"os"
)

const M = 1000000007

func main() {
	reader := bufio.NewReader(os.Stdin)
	s := []byte(reader.String())
	n := len(s)
	dp := make([][]int, n+1)
	for i := 0; i <= n; i++ {
		dp[i] = make([]int, 2)
	}
	dp[0][0] = 1
	for i := 0; i < n; i++ {
		if s[i] == '0' {
			dp[i+1][0] = dp[i][0]
			dp[i+1][1] = dp[i][1]
		} else {
			dp[i+1][1] = (dp[i][0] + dp[i][1]) % M
		}
		if s[i] == '0' {
			dp[i+1][1] += (dp[i][1] * 2) % M
			dp[i+1][1] %= M
		} else {
			dp[i+1][0] += (dp[i][0] * 2) % M
			dp[i+1][1] += (dp[i][1] * 2) % M
			dp[i+1][0] %= M
			dp[i+1][1] %= M
		}
	}
	fmt.Println((dp[n][0]+dp[n][1])%M)
}

