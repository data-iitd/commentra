
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	const MOD = 100000007
	var rr, cc, k int
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d %d %d\n", &rr, &cc, &k)
	mat := make([][]int, rr)
	for i := 0; i < rr; i++ {
		mat[i] = make([]int, cc)
	}
	for i := 0; i < k; i++ {
		var r, c, v int
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d %d %d\n", &r, &c, &v)
		mat[r-1][c-1] = v
	}
	dp := make([][][]int64, rr)
	for i := 0; i < rr; i++ {
		dp[i] = make([][]int64, cc)
		for j := 0; j < cc; j++ {
			dp[i][j] = make([]int64, 4)
		}
	}
	dp[0][0][1] = int64(mat[0][0])
	for y := 0; y < rr; y++ {
		for x := 0; x < cc; x++ {
			for c := 0; c < 4; c++ {
				v := int64(mat[y][x])
				var q int64
				if c == 0 || v == 0 {
					q = int64(x == 0? 0 : dp[y][x-1][c])
				} else {
					q = int64(x == 0? 0 : dp[y][x-1][c])
					q = int64(q < dp[y][x-1][c-1]+v? dp[y][x-1][c-1]+v : q)
				}
				dp[y][x][c] = q
			}
		}
	}
	var max int64
	for x := 0; x < cc; x++ {
		max = int64(max < dp[rr-1][x][0]? dp[rr-1][x][0] : max)
		max = int64(max < dp[rr-1][x][1]? dp[rr-1][x][1] : max)
		max = int64(max < dp[rr-1][x][2]? dp[rr-1][x][2] : max)
		max = int64(max < dp[rr-1][x][3]? dp[rr-1][x][3] : max)
	}
	fmt.Println(max)
}
