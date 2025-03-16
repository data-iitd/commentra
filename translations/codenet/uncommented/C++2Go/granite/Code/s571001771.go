
package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	r = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)
)

func main() {
	const inf = 123456789012
	var n, m int
	fmt.Fscanf(r, "%d%d\n", &n, &m)
	key := make([]int, m+1)
	cost := make([]int, m+1)
	dp := make([][]int, 1<<n)
	for i := range dp {
		dp[i] = make([]int, m+1)
		for j := range dp[i] {
			dp[i][j] = inf
		}
	}
	dp[0][0] = 0
	for i := 1; i <= m; i++ {
		fmt.Fscanf(r, "%d%d", &cost[i], &key[i])
		for j := 0; j < key[i]; j++ {
			var k int
			fmt.Fscanf(r, "%d", &k)
			key[i] |= 1 << (k - 1)
		}
	}
	for i := 0; i < 1<<n; i++ {
		for j := 1; j <= m; j++ {
			dp[i][j] = min(dp[i][j], dp[i][j-1])
			dp[i|key[j]][j] = min(dp[i|key[j]][j], dp[i][j-1]+cost[j])
		}
	}
	if dp[(1<<n)-1][m] == inf {
		fmt.Fprintln(w, -1)
	} else {
		fmt.Fprintln(w, dp[(1<<n)-1][m])
	}
	w.Flush()
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

