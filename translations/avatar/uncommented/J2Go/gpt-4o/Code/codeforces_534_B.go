package main

import (
	"fmt"
	"math"
)

func main() {
	var v1, v2, t, d int
	fmt.Scan(&v1, &v2, &t, &d)

	dp := make([][]int64, t-1)
	for i := range dp {
		dp[i] = make([]int64, 1150)
		for j := range dp[i] {
			dp[i][j] = -1e17
		}
	}
	dp[0][v1] = int64(v1)

	for i := 1; i < t-1; i++ {
		for j := 0; j < 1150; j++ {
			for x := 0; x <= d; x++ {
				if j+x < 1150 {
					dp[i][j] = int64(math.Max(float64(dp[i][j]), float64(dp[i-1][j+x]+j)))
				}
			}
			for x := d; x >= 0; x-- {
				if j-x >= 0 {
					dp[i][j] = int64(math.Max(float64(dp[i][j]), float64(dp[i-1][j-x]+j)))
				}
			}
		}
	}

	ans := int64(math.MinInt64)
	for i := t - 2; i < t-1; i++ {
		for j := 0; j < 1150; j++ {
			if math.Abs(float64(j-v2)) <= float64(d) {
				ans = int64(math.Max(float64(ans), float64(dp[i][j]+v2)))
			}
		}
	}

	fmt.Println(ans)
}

// <END-OF-CODE>
