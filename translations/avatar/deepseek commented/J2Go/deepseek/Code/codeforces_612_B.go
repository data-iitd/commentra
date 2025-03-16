package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	dp := make([]int, 200001)

	// Storing positions of the integers in the array dp
	for i := 0; i < n; i++ {
		var num int
		fmt.Scan(&num)
		dp[num] = i
	}

	var ans int64 = 0

	// Calculating the sum of absolute differences between consecutive positions
	for i := 2; i <= n; i++ {
		ans += int64(math.Abs(float64(dp[i] - dp[i-1])))
	}

	fmt.Println(ans) // Printing the final answer
}
