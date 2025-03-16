
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n int64
	fmt.Fscanf(reader, "%d\n", &n)
	a := make([]int64, n)
	for i := int64(0); i < n; i++ {
		fmt.Fscanf(reader, "%d", &a[i])
	}
	dp := make([][][]int64, n+1)
	for i := int64(0); i <= n; i++ {
		dp[i] = make([][]int64, 2)
		for j := int64(0); j < 2; j++ {
			dp[i][j] = make([]int64, 20)
			for k := int64(0); k < 20; k++ {
				dp[i][j][k] = -100000000000000000
			}
		}
	}
	dp[0][0][10] = 0
	for i := int64(1); i <= n; i++ {
		for j := int64(6); j <= 14; j++ {
			if dp[i-1][0][j]!= -100000000000000000 {
				dp[i][1][j+1] = max(dp[i][1][j+1], dp[i-1][0][j]+a[i-1])
				dp[i][0][j-1] = max(dp[i][0][j-1], dp[i-1][0][j])
			}
			if dp[i-1][1][j]!= -100000000000000000 {
				dp[i][0][j-1] = max(dp[i][0][j-1], dp[i-1][1][j])
			}
		}
	}
	v := 10 + n/2 - (n-n/2)
	t1 := dp[n][0][v]
	t2 := dp[n][1][v]
	fmt.Println(max(t1, t2))
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}
