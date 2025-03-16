package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	v1, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	v2, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	t, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	d, _ := strconv.Atoi(sc.Text())
	dp := make([][]int, t-1)
	for i := 0; i < t-1; i++ {
		dp[i] = make([]int, 1150)
		for j := 0; j < 1150; j++ {
			dp[i][j] = -1e17
		}
	}
	dp[0][v1] = v1
	sum := 0
	for i := 1; i < t-1; i++ {
		for j := 0; j < 1150; j++ {
			for x := 0; x <= d; x++ {
				if j+x < 1150 {
					dp[i][j] = max(dp[i][j], dp[i-1][j+x]+j)
				}
			}
			for x := d; x >= 0; x-- {
				if j-x >= 0 {
					dp[i][j] = max(dp[i][j], dp[i-1][j-x]+j)
				}
			}
		}
	}
	ans := -1e17
	for i := t - 2; i < t-1; i++ {
		for j := 0; j < 1150; j++ {
			if abs(j-v2) <= d {
				ans = max(ans, dp[i][j]+v2)
			}
		}
	}
	fmt.Println(ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

