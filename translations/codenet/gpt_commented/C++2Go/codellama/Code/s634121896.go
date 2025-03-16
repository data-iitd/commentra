
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n int
	fmt.Scan(&n)
	nums := make([]int, n)
	last := 0
	for i := 0; i < n; i++ {
		fmt.Scan(&nums[i])
	}
	dp := make([]int, n+1)
	dp[0] = 1
	kek := make(map[int]int)
	prev := make(map[int]int)
	for i := 1; i <= n; i++ {
		dp[i] = dp[i-1] + (prev[nums[i-1]] != i-1) * kek[nums[i-1]]
		dp[i] %= 1000000007
		kek[nums[i-1]] = dp[i]
		prev[nums[i-1]] = i
	}
	fmt.Println(dp[n])
}

