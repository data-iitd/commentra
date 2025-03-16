package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	n, _ := strconv.Atoi(scanner.Text())
	maxn := 4010
	a, _ := strconv.Atoi(scanner.Text())
	b, _ := strconv.Atoi(scanner.Text())
	c, _ := strconv.Atoi(scanner.Text())
	arr := []int{a, b, c}
	dp := make([]int, maxn)
	for i := 0; i < n; i++ {
		dp[i] = -1000000000
	}
	dp[0] = 0
	for i := 0; i < 3; i++ {
		for j := arr[i]; j < maxn; j++ {
			dp[j] = max(dp[j], dp[j-arr[i]]+1)
		}
	}
	fmt.Println(dp[n])
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

