package main

import (
	"fmt"
)

type ll int

var mat [3000][3000]int
var dp [3000][3000][4]ll
var dpl [3000]ll

func main() {
	var rr, cc, k int
	fmt.Scan(&rr, &cc, &k)
	for i := 1; i <= k; i++ {
		var r, c, v int
		fmt.Scan(&r, &c, &v)
		mat[r-1][c-1] = v
	}
	dp[0][0][1] = ll(mat[0][0])
	for y := 0; y < rr; y++ {
		for x := 0; x < cc; x++ {
			for c := 0; c < 4; c++ {
				v := mat[y][x]
				var q ll
				if c == 0 || v == 0 {
					if x == 0 {
						q = dpl[x]
					} else {
						q = max(dpl[x], dp[y][x-1][c])
					}
				} else {
					if x == 0 {
						q = dpl[x] + ll(v)
					} else {
						q = max(dpl[x]+ll(v), max(dp[y][x-1][c], dp[y][x-1][c-1]+ll(v)))
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

func max(a, b ll) ll {
	if a > b {
		return a
	}
	return b
}

