package main

import (
	"fmt"
	"math"
)

const MAX_N = 4000
const LINF = 1 << 60

type ll int

var wis [MAX_N]int
var wsums [MAX_N + 1]int
var dp [MAX_N][MAX_N + 1]ll
var ks [MAX_N][MAX_N + 1]int

func main() {
	var n int
	fmt.Scan(&n)

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
		for i, j := 0, l; j <= n; i, j = i+1, j+1 {
			var mind ll = LINF
			wsum := wsums[j] - wsums[i]
			var mink int = -1

			for k := ks[i][j-1]; k <= ks[i+1][j]; k++ {
				d := dp[i][k] + dp[k][j] + ll(wsum)

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
