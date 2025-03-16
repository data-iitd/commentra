
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const MAX_N = 4000

func main() {
	var n int
	fmt.Scanf("%d", &n)

	wis := make([]int, n)
	wsums := make([]int, n + 1)
	dp := make([][]int, n)
	ks := make([][]int, n)

	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &wis[i])
		wsums[i + 1] = wsums[i] + wis[i]
	}

	for i := 0; i < n; i++ {
		dp[i] = make([]int, n + 1)
		ks[i] = make([]int, n + 1)
		for j := 0; j <= n; j++ {
			dp[i][j] = 1e18
			ks[i][j] = -1
		}
		dp[i][i + 1] = 0
		ks[i][i + 1] = i
	}

	for l := 2; l <= n; l++ {
		for i := 0; i <= n - l; i++ {
			j := i + l
			mind := 1e18
			wsum := wsums[j] - wsums[i]
			mink := -1
			for k := ks[i][j - 1]; k <= ks[i + 1][j]; k++ {
				d := dp[i][k] + dp[k][j] + wsum
				if mind > d {
					mind = d
					mink = k
				}
			}
			dp[i][j] = mind
			ks[i][j] = mink
		}
	}

	fmt.Printf("%d\n", dp[0][n])
}

