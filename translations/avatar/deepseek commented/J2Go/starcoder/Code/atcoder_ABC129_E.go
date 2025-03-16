package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s)
	s = strings.Replace(s, "\n", "", -1)
	s = strings.Replace(s, "\r", "", -1)
	s = strings.Replace(s, " ", "", -1)
	n := len(s)
	dp := make([][]int, n+1)
	for i := 0; i < n+1; i++ {
		dp[i] = make([]int, 2)
	}
	dp[0][0] = 1
	for i := 0; i < n; i++ {
		if s[i] == '0' {
			dp[i+1][0] = dp[i][0]
			dp[i+1][1] = dp[i][1]
		} else {
			dp[i+1][1] = (dp[i][0] + dp[i][1]) % 1000000007
			dp[i+1][0] = (dp[i][0] * 2) % 1000000007
			dp[i+1][1] = (dp[i][1] * 2) % 1000000007
		}
		if s[i] == '0' {
			dp[i+1][1] += (dp[i][1] * 2) % 1000000007
			dp[i+1][1] %= 1000000007
		} else {
			dp[i+1][0] += (dp[i][0] * 2) % 1000000007
			dp[i+1][1] += (dp[i][1] * 2) % 1000000007
			dp[i+1][0] %= 1000000007
			dp[i+1][1] %= 1000000007
		}
	}
	fmt.Println((dp[n][0] + dp[n][1]) % 1000000007)
}

