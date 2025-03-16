
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n int
	fmt.Fscanf(reader, "%d\n", &n)
	maxn := 4010
	var a, b, c int
	fmt.Fscanf(reader, "%d %d %d\n", &a, &b, &c)
	arr := []int{a, b, c}
	dp := make([]int, maxn)
	for i := 0; i < n; i++ {
		dp[i] = -100000
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

// 