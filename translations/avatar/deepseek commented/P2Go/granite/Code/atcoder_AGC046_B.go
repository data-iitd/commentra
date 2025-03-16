
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	const m = 998244353
	reader := bufio.NewReader(os.Stdin)
	a, _ := strconv.Atoi(nextString(reader))
	b, _ := strconv.Atoi(nextString(reader))
	c, _ := strconv.Atoi(nextString(reader))
	d, _ := strconv.Atoi(nextString(reader))
	dp := make([][]int64, c+1)
	for i := range dp {
		dp[i] = make([]int64, d+1)
	}
	dp[a][b] = 1
	for i := a; i <= c; i++ {
		for j := b; j <= d; j++ {
			dp[i][j] = (dp[i][j-1]*int64(i)+dp[i-1][j]*int64(j)-dp[i-1][j-1]*int64(i-1)*int64(j-1)) % m
		}
	}
	fmt.Println(dp[c][d])
}

func nextString(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	for i := 0; i < len(s); i++ {
		if s[i] == '\n' {
			return s[:i]
		}
	}
	return s
}
