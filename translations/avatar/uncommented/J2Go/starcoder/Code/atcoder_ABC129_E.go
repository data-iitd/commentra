package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	s := sc.Text()
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
			dp[i+1][1] = (dp[i][0] + dp[i][1]) % 1000000007
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

