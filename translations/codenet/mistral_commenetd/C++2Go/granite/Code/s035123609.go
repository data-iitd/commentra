

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	const MOD = 100000007
	const MAXN = 3000
	var rr, cc, k int
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d%d%d\n", &rr, &cc, &k)
	var mat [MAXN][MAXN]int
	for i := 0; i < k; i++ {
		var r, c, v int
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d%d%d\n", &r, &c, &v)
		mat[r-1][c-1] = v
	}
	var dp [MAXN][MAXN][4]int64
	dp[0][0][1] = int64(mat[0][0])
	for y := 0; y < rr; y++ {
		for x := 0; x < cc; x++ {
			for c := 0; c < 4; c++ {
				v := mat[y][x]
				var q int64
				if c == 0 || v == 0 {
					q = int64(x == 0? dpl[x] : max(dpl[x], dp[y][x-1][c]))
				} else {
					q = int64(x == 0? dpl[x]+v : max(dpl[x]+v, max(dp[y][x-1][c], dp[y][x-1][c-1]+v)))
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

