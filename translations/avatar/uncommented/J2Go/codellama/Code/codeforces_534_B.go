
package main

import (
	"fmt"
	"math"
)

func main() {
	var v1, v2, t, d int
	fmt.Scan(&v1, &v2, &t, &d)
	dp := make([][]int, t-1)
	for i := 0; i < t-1; i++ {
		dp[i] = make([]int, 1150)
		for j := 0; j < 1150; j++ {
			dp[i][j] = -1e17
		}
	}
	dp[0][v1] = v1
	sum := 0
	for i := 1; i < t-1; i++ {
		for j := 0; j < 1150; j++ {
			for x := 0; x <= d; x++ {
				if j+x < 1150 {
					dp[i][j] = int(math.Max(float64(dp[i][j]), float64(dp[i-1][j+x]+j)))
				}
			}
			for x := d; x >= 0; x-- {
				if j-x >= 0 {
					dp[i][j] = int(math.Max(float64(dp[i][j]), float64(dp[i-1][j-x]+j)))
				}
			}
		}
	}
	ans := math.MinInt64
	for i := t - 2; i < t-1; i++ {
		for j := 0; j < 1150; j++ {
			if math.Abs(float64(j-v2)) <= float64(d) {
				ans = int(math.Max(float64(ans), float64(dp[i][j]+v2)))
			}
		}
	}
	fmt.Println(ans)
}

