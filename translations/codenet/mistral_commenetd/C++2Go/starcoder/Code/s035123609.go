
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// 2D matrix to store the given grid data
var mat [3000][3000]int

// 3D dp array to store the maximum sum of submatrices with different conditions
var dp [3000][3000][4]int

// 1D array to store the maximum sum of submatrices ending at the current column
var dpl [3000]int

func main() {
	var rr, cc, k int
	fmt.Scanf("%d %d %d\n", &rr, &cc, &k)

	for i := 0; i < k; i++ {
		var r, c, v int
		fmt.Scanf("%d %d %d\n", &r, &c, &v)
		mat[r-1][c-1] = v
	}

	dp[0][0][1] = mat[0][0]

	for y := 0; y < rr; y++ {
		for x := 0; x < cc; x++ {
			for c := 0; c < 4; c++ {
				v := mat[y][x]
				q := 0
				if c == 0 || v == 0 {
					q = (x == 0)? dpl[x] : max(dpl[x], dp[y][x-1][c])
				} else {
					q = (x == 0)? dpl[x] + v : max(dpl[x] + v, max(dp[y][x-1][c], dp[y][x-1][c-1]+v))
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

