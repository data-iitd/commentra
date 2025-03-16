
package main

import (
	"fmt"
)

type matrix [3000][3000]int
type dp [3000][3000][4]int
type dpl [3000]int

var (
	rr, cc, k int
	mat       matrix
	dp        dp
	dpl       dpl
)

func main() {
	fmt.Scan(&rr, &cc, &k)

	for i := 1; i <= k; i++ {
		var r, c, v int
		fmt.Scan(&r, &c, &v)
		mat[r-1][c-1] = v
	}

	dp[0][0][1] = mat[0][0]

	for y := 0; y < rr; y++ {
		for x := 0; x < cc; x++ {
			for c := 0; c < 4; c++ {
				v := mat[y][x]
				q := 0
				if c == 0 || v == 0 {
					q = dpl[x]
					if x > 0 {
						q = max(q, dp[y][x-1][c])
					}
				} else {
					q = dpl[x] + v
					if x > 0 {
						q = max(q, max(dp[y][x-1][c], dp[y][x-1][c-1]+v))
					}
				}
				dp[y][x][c] = q
			}
		}
		for x := 0; x < cc; x++ {
			dpl[x] = max(max(dp[y][x][0], dp[y][x][1]), max(dp[y][x][2], dp[y][x][3]))
		}
	}

	fmt.Println(dpl[cc-1])
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

