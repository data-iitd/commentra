package main

import (
	"fmt"
)

const MOD = 1e9 + 7

func solve() {
	var n int
	fmt.Scan(&n)

	nums := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&nums[i])
	}

	dp := make([]int64, n+1)
	dp[0] = 1

	kek := make(map[int64]int64)
	prev := make(map[int64]int64)

	for i := 1; i <= n; i++ {
		dp[i] = dp[i-1]
		if prev[nums[i-1]] != int64(i-1) {
			dp[i] += kek[nums[i-1]]
		}
		dp[i] %= MOD

		kek[nums[i-1]] = dp[i]
		prev[nums[i-1]] = int64(i)
	}

	fmt.Println(dp[n])
}

func main() {
	var q int = 1
	// Uncomment the following line if you want to read the number of test cases
	// fmt.Scan(&q)
	for i := 0; i < q; i++ {
		solve()
	}
}

// <END-OF-CODE>
