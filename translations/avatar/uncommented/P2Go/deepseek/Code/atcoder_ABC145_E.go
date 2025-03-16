package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(input), " ")
	N, _ := strconv.Atoi(parts[0])
	T, _ := strconv.Atoi(parts[1])
	timeValue := make([][2]int, N+1)
	timeValue[0] = [-1]int{-1, -1}
	for i := 1; i <= N; i++ {
		input, _ = reader.ReadString('\n')
		parts = strings.Split(strings.TrimSpace(input), " ")
		time, _ := strconv.Atoi(parts[0])
		value, _ := strconv.Atoi(parts[1])
		timeValue[i] = [2]int{time, value}
	}
	sort.Slice(timeValue, func(i, j int) bool {
		return timeValue[i][1] < timeValue[j][1]
	})
	dp := make([][]int, N+1)
	for i := 0; i <= N; i++ {
		dp[i] = make([]int, T)
		for j := 0; j < T; j++ {
			dp[i][j] = -1
		}
	}
	for t := 0; t < T; t++ {
		dp[0][t] = 0
	}
	for n := 1; n <= N; n++ {
		dp[n][0] = 0
		for t := 1; t < T; t++ {
			if timeValue[n][0] > t {
				dp[n][t] = dp[n-1][t]
			} else {
				dp[n][t] = max(dp[n-1][t], timeValue[n][1]+dp[n-1][t-timeValue[n][0]])
			}
		}
	}
	valAcum := timeValue[N][1]
	t := T - 1
	maxVal := valAcum + dp[N-1][t]
	for n := N - 1; n > 0; n-- {
		valAcum += timeValue[n][1]
		t -= timeValue[n+1][0]
		if t < 0 {
			break
		} else {
			maxVal = max(maxVal, valAcum + dp[n-1][t])
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
