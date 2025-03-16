package main

import (
	"fmt"
	"math"
)

func main() {
	var v1, v2, t, d int
	fmt.Scan(&v1, &v2, &t, &d)

	// Step 2: Initialize a 2D slice dp with dimensions (t-1) x 1150, and fill it with a very small value (-1e17).
	dp := make([][]int64, t-1)
	for i := range dp {
		dp[i] = make([]int64, 1150)
		for j := range dp[i] {
			dp[i][j] = -1e17
		}
	}

	// Step 3: Set the initial value of dp[0][v1] to v1.
	dp[0][v1] = int64(v1)

	// Step 4: Iterate through the time steps from 1 to t-2.
	for i := 1; i < t-1; i++ {
		// Step 5: For each time step, update the dp array based on the possible values of j (current position) and x (distance change).
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

	// Step 6: After updating the dp array, find the maximum value of dp[t-2][j] + v2 where the absolute difference between j and v2 is within the range d.
	ans := int64(math.MinInt64)
	for j := 0; j < 1150; j++ {
		if int64(math.Abs(float64(j-v2))) <= int64(d) {
			ans = int64(math.Max(float64(ans), float64(dp[t-2][j]+v2)))
		}
	}

	// Step 7: Print the result.
	fmt.Println(ans)
}

// <END-OF-CODE>
