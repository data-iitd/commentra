package main

import (
	"fmt"
)

func main() {
	var rr, cc, k int
	fmt.Scan(&rr, &cc, &k)

	mat := make([][]int, rr)
	for i := range mat {
		mat[i] = make([]int, cc)
	}

	for i := 1; i <= k; i++ {
		var r, c, v int
		fmt.Scan(&r, &c, &v)
		mat[r-1][c-1] = v
	}

	dp := make([][][]int, rr)
	for i := range dp {
		dp[i] = make([][]int, cc)
		for j := range dp[i] {
			dp[i][j] = make([]int, 4)
		}
	}

	dpl := make([]int, cc)

	dp[0][0][1] = mat[0][0]

	for y := 0; y < rr; y++ {
		for x := 0; x < cc; x++ {
			for c := 0; c < 4; c++ {
				v := mat[y][x]
				var q int
				if c == 0 || v == 0 {
					q = (x == 0) ? dpl[x] : max(dpl[x], dp[y][x-1][c])
				} else {
					q = (x == 0) ? dpl[x] + v : max(dpl[x]+v, max(dp[y][x-1][c], dp[y][x-1][c-1]+v))
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

