
package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	n, m int
	cost  []int
	key   []int
	dp    [1<<12][1005]int
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d %d\n", &n, &m)
	for i := 0; i < (1<<12); i++ {
		for j := 0; j < 1005; j++ {
			dp[i][j] = 1 << 30
		}
	}
	dp[0][0] = 0
	cost = make([]int, m+1)
	key = make([]int, m+1)
	for i := 1; i <= m; i++ {
		fmt.Fscanf(reader, "%d %d\n", &cost[i], &key[i])
		for j := 0; j < key[i]; j++ {
			var k int
			fmt.Fscanf(reader, "%d", &k)
			key[i] |= 1 << (k - 1)
		}
	}
	for i := 0; i < (1<<n); i++ {
		for j := 0; j < m; j++ {
			dp[i][j+1] = min(dp[i][j+1], dp[i][j])
			dp[i|key[j+1]][j+1] = min(dp[i|key[j+1]][j+1], dp[i][j]+cost[j+1])
		}
	}
	if dp[(1<<n)-1][m] == 1<<30 {
		fmt.Println(-1)
	} else {
		fmt.Println(dp[(1<<n)-1][m])
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

