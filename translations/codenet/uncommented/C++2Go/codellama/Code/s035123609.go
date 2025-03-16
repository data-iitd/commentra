package main

import (
	"fmt"
)

var mat [3000][3000]int
var dp [3000][3000][4]int
var dpl [3000]int

func main() {
	var rr, cc, k int
	fmt.Scan(&rr, &cc, &k)
	for i := 1; i <= k; i++ {
		var r, c, v int
		fmt.Scan(&r, &c, &v)
		mat[r - 1][c - 1] = v
	}
	dp[0][0][1] = mat[0][0]
	for y := 0; y < rr; y++ {
		for x := 0; x < cc; x++ {
			for c := 0; c < 4; c++ {
				v := mat[y][x]
				var q int
				if c == 0 || v == 0 {
					q = (x == 0) ? dpl[x] : max(dpl[x], dp[y][x - 1][c])
				} else {
					q = (x == 0) ? dpl[x] + v : max(dpl[x] + v, max(dp[y][x - 1][c], dp[y][x - 1][c - 1] + v))
				}
				dp[y][x][c] = q
			}
		}
		for x := 0; x < cc; x++ {
			dpl[x] = max(max(dp[y][x][0], dp[y][x][1]), max(dp[y][x][2], dp[y][x][3]))
		}
	}
	fmt.Println(dpl[cc - 1])
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

