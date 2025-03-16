package main

import (
	"fmt"
)

const mod = 1000000007

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	coef := []int{}

	for i := 1; i*i <= n; i++ {
		coef = append(coef, (n/i)-(n/(i+1)))
	}

	nn := len(coef)
	for i := 1; i*i <= n; i++ {
		if n/i != i {
			coef = append(coef, (n/(n/i))-1)
		}
	}

	coef = append(coef, 1)
	coef = append(coef, 1)

	for i := 1; i <= k; i++ {
		tmp := 0
		for j := nn - 1; j >= 0; j-- {
			tmp += dp[i-1][nn-1-j]
			tmp %= mod
			dp[i][j] = coef[j] * tmp % mod
		}
	}

	sum := 0
	for j := 0; j < nn; j++ {
		sum += dp[k][j]
		sum %= mod
	}

	fmt.Println(sum)
}
