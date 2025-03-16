package main

import "fmt"

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	// Initialize the coefficient list
	coef := make([]int, n)
	for i := 1; i < n; i++ {
		coef[i] = (n / i) - (n / (i + 1))
	}
	coef[0] = 1
	// Initialize the dp table
	dp := make([][]int, k+1)
	for i := 0; i <= k; i++ {
		dp[i] = make([]int, n)
	}
	dp[0][0] = 1
	// Dynamic programming to calculate the number of ways to achieve sums with up to k elements
	for i := 1; i <= k; i++ {
		tmp := 0
		for j := n - 1; j >= 0; j-- {
			tmp += dp[i-1][j]
			tmp %= 1000000007
			dp[i][j] = coef[j] * tmp
		}
	}
	// Print the result: the sum of the last row of dp modulo 10^9 + 7
	fmt.Println(dp[k][n-1])
}

