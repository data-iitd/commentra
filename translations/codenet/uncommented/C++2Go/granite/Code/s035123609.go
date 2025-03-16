
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func main() {
	var rr, cc, k int
	fmt.Fscanf(in, "%d%d%d\n", &rr, &cc, &k)
	mat := make([][]int, rr)
	for i := 0; i < rr; i++ {
		mat[i] = make([]int, cc)
	}
	for i := 0; i < k; i++ {
		var r, c, v int
		fmt.Fscanf(in, "%d%d%d\n", &r, &c, &v)
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
					q = int64(x == 0? 0 : dpl[x])
				} else {
					q = int64(x == 0? 0 : dpl[x]) + v
				}
				dp[y][x][c] = q
			}
		}
		for x := 0; x < cc; x++ {
			dpl[x] = int64(max(max(dp[y][x][0], dp[y][x][1]), max(dp[y][x][2], dp[y][x][3])))
		}
	}
	fmt.Fprintf(out, "%d\n", dpl[cc-1])
	out.Flush()
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func main() {
	var rr, cc, k int
	fmt.Fscanf(in, "%d%d%d\n", &rr, &cc, &k)
	mat := make([][]int, rr)
	for i := 0; i < rr; i++ {
		mat[i] = make([]int, cc)
	}
	for i := 0; i < k; i++ {
		var r, c, v int
		fmt.Fscanf(in, "%d%d%d\n", &r, &c, &v)
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
					q = int64(x == 0? 0 : dpl[x])
				} else {
					q = int64(x == 0? 0 : dpl[x]) + v
				}
				dp[y][x][c] = q
			}
		}
		for x := 0; x < cc; x++ {
			dpl[x] = int64(max(max(dp[y][x][0], dp[y][x][1]), max(dp[y][x][2], dp[y][x][3])))
		}
	}
	fmt.Fprintf(out, "%d\n", dpl[cc-1])
	out.Flush()
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

