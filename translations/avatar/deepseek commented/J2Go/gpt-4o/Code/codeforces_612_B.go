package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n) // Reading the integer n from the input
	dp := make([]int, 200001) // Initializing a slice to store positions

	// Storing positions of the integers in the slice dp
	for i := 0; i < n; i++ {
		var num int
		fmt.Scan(&num)
		dp[num] = i
	}

	ans := 0.0 // Initializing the answer variable to 0

	// Calculating the sum of absolute differences between consecutive positions
	for i := 2; i <= n; i++ {
		ans += math.Abs(float64(dp[i] - dp[i-1]))
	}

	fmt.Println(int(ans)) // Printing the final answer
}

// <END-OF-CODE>
