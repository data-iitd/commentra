
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n, t int
	fmt.Fscanf(reader, "%d %d\n", &n, &t)
	timeValue := make([][2]int, n+1)
	for i := 1; i <= n; i++ {
		var time, val int
		fmt.Fscanf(reader, "%d %d\n", &time, &val)
		timeValue[i] = [2]int{time, val}
	}
	dp := make([][]int, n+1)
	for i := 0; i <= n; i++ {
		dp[i] = make([]int, t+1)
	}
	for i := 1; i <= n; i++ {
		for j := 1; j <= t; j++ {
			if timeValue[i][0] > j {
				dp[i][j] = dp[i-1][j]
			} else {
				dp[i][j] = max(dp[i-1][j], timeValue[i][1]+dp[i-1][j-timeValue[i][0]])
			}
		}
	}
	valAcum := timeValue[n][1]
	j := t - 1
	maxVal := valAcum + dp[n-1][j]
	for i := n - 1; i > 0; i-- {
		valAcum += timeValue[i][1]
		j -= timeValue[i+1][0]
		if j < 0 {
			break
		} else {
			maxVal = max(maxVal, valAcum+dp[i-1][j])
		}
	}
	fmt.Println(maxVal)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

