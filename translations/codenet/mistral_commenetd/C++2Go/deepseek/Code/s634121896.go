package main

import (
	"fmt"
	"math"
)

const (
	INF     = 1e9 + 228
	INFLL   = 1e18
	MOD     = 1e9 + 7
	MOD2    = 998244353
	dosz    = 5e5
	SZ      = 1 << 18
	PI      = math.Atan2(0, -1)
)

func solve() {
	var n int
	fmt.Scan(&n)
	nums := make([]int, n)
	last := 0
	for i := 0; i < n; i++ {
		fmt.Scan(&nums[i])
		last = nums[i]
	}
	dp := make([]int, n+1)
	dp[0] = 1
	kek := make(map[int]int)
	prev := make(map[int]int)
	for i := 1; i <= n; i++ {
		dp[i] = dp[i-1] + (prev[nums[i-1]] != i-1 ? kek[nums[i-1]] : 0)
		dp[i] %= MOD
		kek[nums[i-1]] = dp[i]
		prev[nums[i-1]] = i
	}
	fmt.Println(dp[n])
}

func main() {
	var q int
	fmt.Scan(&q)
	for q > 0 {
		solve()
		q--
	}
}

