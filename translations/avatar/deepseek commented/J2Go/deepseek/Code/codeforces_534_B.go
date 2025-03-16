package main

import (
	"fmt"
	"math"
)

func main() {
	var v1, v2, t, d int
	fmt.Scan(&v1, &v2, &t, &d)

	// Initialize a 2D slice dp with dimensions (t-1) x 1150, and fill it with a very small value (-1e17).
	dp := make([][]float64, t-1)
	for i := range dp {
		dp[i] = make([]float64, 1150)
		for j := range dp[i] {
			dp[i][j] = -math.Pow(10, 17)
		}
	}

	// Set the initial value of dp[0][v1] to v1.
	dp[0][v1] = float64(v1)

	// Iterate through the time steps from 1 to t-2.
	for i := 1; i < t-1; i++ {
		// For each time step, update the dp array based on the possible values of j (current position) and x (distance change).
		for j := 0; j < 1150; j++ {
			for x := 0; x <= d; x++ {
				if j+x < 1150 {
					dp[i][j] = math.Max(dp[i][j], dp[i-1][j+x]+float64(j))
				}
			}
			for x := d; x >= 0; x-- {
				if j-x >= 0 {
					dp[i][j] = math.Max(dp[i][j], dp[i-1][j-x]+float64(j))
				}
			}
		}
	}

	// After updating the dp array, find the maximum value of dp[t-2][j] + v2 where the absolute difference between j and v2 is within the range d.
	ans := math.Inf(-1)
	for i := t - 2; i < t-1; i++ {
		for j := 0; j < 1150; j++ {
			if math.Abs(float64(j-v2)) <= float64(d) {
				ans = math.Max(ans, dp[i][j]+float64(v2))
			}
		}
	}

	// Print the result.
	fmt.Println(ans)
}
