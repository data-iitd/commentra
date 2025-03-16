package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)
	dp := make([]int, 200001)

	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		dp[x] = i
	}

	var ans int64 = 0
	for i := 2; i <= n; i++ {
		ans += int64(math.Abs(float64(dp[i] - dp[i-1])))
	}

	fmt.Println(ans)
}

// <END-OF-CODE>
