
package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	MAX_N = 4000
	LINF  = 1 << 60
)

var (
	wis    [MAX_N]int64
	wsums  [MAX_N + 1]int64
	dp     [MAX_N][MAX_N + 1]int64
	ks     [MAX_N][MAX_N + 1]int
	reader = bufio.NewReader(os.Stdin)
)

func main() {
	var n int
	fmt.Fscanf(reader, "%d\n", &n)

	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d\n", &wis[i])
		wsums[i+1] = wsums[i] + wis[i]
	}

	for i := 0; i < n; i++ {
		for j := 0; j <= n; j++ {
			dp[i][j] = LINF
			ks[i][j] = -1
		}
		dp[i][i+1] = 0
		ks[i][i+1] = i
	}

	for l := 2; l <= n; l++ {
		for i := 0, j := l; j <= n; i, j = i+1, j+1 {
			mind := LINF
			wsum := wsums[j] - wsums[i]
			mink := -1
			for k := ks[i][j-1]; k <= ks[i+1][j]; k++ {
				d := dp[i][k] + dp[k][j] + wsum
				if d < mind {
					mind = d
					mink = k
				}
			}
			dp[i][j] = mind
			ks[i][j] = mink
		}
	}

	fmt.Println(dp[0][n])
}
