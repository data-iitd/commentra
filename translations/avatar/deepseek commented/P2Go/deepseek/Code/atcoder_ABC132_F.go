package main

import (
	"fmt"
)

const mod = 1000000007

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	// Calculate the coefficients for the number of multiples of each divisor up to n
	coef := []int{}
	for i := 1; i <= n; i++ {
		coef = append(coef, (n/i)-(n/(i+1)))
	}
	coef = append(coef, 1)
	for i := len(coef) - 2; i >= 0; i-- {
		coef[i] += coef[i+1]
	}

	nn := len(coef)
	dp := make([][]int, k+1)
	for i := range dp {
		dp[i] = make([]int, nn)
	}
	dp[0][0] = 1

	// Dynamic programming to calculate the number of ways to achieve sums with up to k elements
	for i := 1; i <= k; i++ {
		tmp := 0
		for j := nn - 1; j >= 0; j-- {
			tmp += dp[i-1][nn-1-j]
			tmp %= mod
			dp[i][j] = coef[j] * tmp % mod
		}
	}

	// Print the result: the sum of the last row of dp modulo mod
	sum := 0
	for j := 0; j < nn; j++ {
		sum += dp[k][j]
		sum %= mod
	}
	fmt.Println(sum)
}

