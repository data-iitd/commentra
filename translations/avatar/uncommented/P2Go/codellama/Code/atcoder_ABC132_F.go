package main

import (
	"fmt"
)

func main() {
	mod := 1000000007
	var n, k int
	fmt.Scan(&n, &k)
	coef := make([]int, 0)
	for i := 1; i <= int(n**0.5)+1; i++ {
		coef = append(coef, (n/i)-(n/(i+1)))
	}
	coef = append(coef, 1)
	coef = coef[:len(coef)-1]
	nn := len(coef)
	dp := make([][]int, k+1)
	for i := 0; i < k+1; i++ {
		dp[i] = make([]int, nn)
	}
	dp[0][0] = 1
	for i := 1; i < k+1; i++ {
		tmp := 0
		for j := nn - 1; j >= 0; j-- {
			tmp += dp[i-1][(nn-1)-j]
			tmp %= mod
			dp[i][j] = coef[j] * tmp
			dp[i][j] %= mod
		}
	}
	fmt.Println(sum(dp[k]) % mod)
}

func sum(dp [][]int) int {
	sum := 0
	for i := 0; i < len(dp); i++ {
		for j := 0; j < len(dp[i]); j++ {
			sum += dp[i][j]
		}
	}
	return sum
}

