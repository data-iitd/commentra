package main

import (
	"fmt"
	"math"
)

const MAX_N = 4000
const LINF = 1 << 60

func main() {
	var n int
	fmt.Scan(&n)

	wis := make([]int64, MAX_N)
	wsums := make([]int64, MAX_N+1)
	dp := make([][]int64, MAX_N)
	ks := make([][]int, MAX_N)

	for i := range dp {
		dp[i] = make([]int64, MAX_N+1)
		ks[i] = make([]int, MAX_N+1)
	}

	wsums[0] = 0
	for i := 0; i < n; i++ {
		fmt.Scan(&wis[i])
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
		for i := 0; j := l; j <= n; i++ {
			j = i + l
			mind := LINF
			wsum := wsums[j] - wsums[i]
			mink := -1
			for k := ks[i][j-1]; k <= ks[i+1][j]; k++ {
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

	fmt.Println(dp[0][n])
}

// <END-OF-CODE>
