package main

import (
	"fmt"
	"math"
)

const MOD = 1e9 + 7

func solve() {
	var n int
	fmt.Scan(&n)
	nums := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&nums[i])
	}

	dp := make([]int64, n+1)
	dp[0] = 1
	kek := make(map[int]int64)
	prev := make(map[int]int)

	for i := 1; i <= n; i++ {
		if prev[nums[i-1]] != i-1 {
			dp[i] = (dp[i-1] + kek[nums[i-1]]) % MOD
		} else {
			dp[i] = dp[i-1] % MOD
		}
		kek[nums[i-1]] = dp[i]
		prev[nums[i-1]] = i
	}

	fmt.Println(dp[n])
}

func main() {
	solve()
}

// <END-OF-CODE>
