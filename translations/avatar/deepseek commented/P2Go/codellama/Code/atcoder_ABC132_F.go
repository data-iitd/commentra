package main

import (
	"fmt"
	"math"
)

const mod = 1000000007

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	coef := make([]int, 0, int(math.Sqrt(float64(n)))+1)
	for i := 1; i <= int(math.Sqrt(float64(n)))+1; i++ {
		coef = append(coef, (n/i)-(n/(i+1)))
	}
	coef = append(coef, make([]int, n-len(coef))...)
	coef = reverse(coef)

	nn := len(coef)
	dp := make([][]int, k+1)
	for i := range dp {
		dp[i] = make([]int, nn)
	}
	dp[0][0] = 1

	for i := 1; i <= k; i++ {
		tmp := 0
		for j := nn - 1; j >= 0; j-- {
			tmp += dp[i-1][(nn-1)-j]
			tmp %= mod
			dp[i][j] = coef[j] * tmp
			dp[i][j] %= mod
		}
	}

	var sum int
	for _, v := range dp[k] {
		sum += v
		sum %= mod
	}
	fmt.Println(sum)
}

func reverse(arr []int) []int {
	for i, j := 0, len(arr)-1; i < j; i, j = i+1, j-1 {
		arr[i], arr[j] = arr[j], arr[i]
	}
	return arr
}

