
package main

import (
	"bufio"
	"fmt"
	"os"
)

const mod = 1e9 + 7

func main() {
	reader := bufio.NewReader(os.Stdin)
	l, _ := reader.ReadString('\n')
	l = l[:len(l)-1]
	n := len(l)
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, 2)
	}
	dp[0][0] = 1
	for i, c := range l {
		if c == '0' {
			dp[i+1][0] = (dp[i][0] + dp[i][1]*3) % mod
			dp[i+1][1] = dp[i][1] * 3 % mod
		} else {
			dp[i+1][0] = (dp[i][0]*2 + dp[i][1]) % mod
			dp[i+1][1] = (dp[i][0] + dp[i][1]*3) % mod
		}
	}
	fmt.Println((dp[n][0] + dp[n][1]) % mod)
}
