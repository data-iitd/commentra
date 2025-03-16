package main

import (
	"fmt"
)

const MAX = 3000

var mat [MAX][MAX]int
var dp [MAX][MAX][4]int64
var dpl [MAX]int64

func main() {
	var rr, cc, k int
	fmt.Scan(&rr, &cc, &k)

	for i := 0; i < k; i++ {
		var r, c, v int
		fmt.Scan(&r, &c, &v)
		mat[r-1][c-1] = v
	}

	dp[0][0][1] = int64(mat[0][0])
	for y := 0; y < rr; y++ {
		for x := 0; x < cc; x++ {
			for c := 0; c < 4; c++ {
				v := mat[y][x]
				var q int64
				if c == 0 || v == 0 {
					if x == 0 {
						q = dpl[x]
					} else {
						q = max(dpl[x], dp[y][x-1][c])
					}
				} else {
					if x == 0 {
						q = dpl[x] + int64(v)
					} else {
						q = max(dpl[x]+int64(v), max(dp[y][x-1][c], dp[y][x-1][c-1]+int64(v)))
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

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>
