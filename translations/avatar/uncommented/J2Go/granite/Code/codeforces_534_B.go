
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	v1, _ := strconv.Atoi(reader.ReadLine()[2:])
	v2, _ := strconv.Atoi(reader.ReadLine()[2:])
	t, _ := strconv.Atoi(reader.ReadLine()[1:])
	d, _ := strconv.Atoi(reader.ReadLine()[1:])
	dp := make([][]int64, t-1)
	for i := 0; i < t-1; i++ {
		dp[i] = make([]int64, 1150)
		for j := 0; j < 1150; j++ {
			dp[i][j] = -100000000000000000
		}
	}
	dp[0][v1] = v1
	sum := int64(0)
	for i := 1; i < t-1; i++ {
		for j := 0; j < 1150; j++ {
			for x := 0; x <= d; x++ {
				if j+x < 1150 {
					dp[i][j] = max(dp[i][j], dp[i-1][j+x]+int64(j))
				}
			}
			for x := d; x >= 0; x-- {
				if j-x >= 0 {
					dp[i][j] = max(dp[i][j], dp[i-1][j-x]+int64(j))
				}
			}
		}
	}
	ans := int64(-100000000000000000)
	for i := t - 2; i < t-1; i++ {
		for j := 0; j < 1150; j++ {
			if abs(int64(j)-int64(v2)) <= int64(d) {
				ans = max(ans, dp[i][j]+int64(v2))
			}
		}
	}
	fmt.Println(ans)
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func abs(a int64) int64 {
	if a < 0 {
		return -a
	}
	return a
}

// 