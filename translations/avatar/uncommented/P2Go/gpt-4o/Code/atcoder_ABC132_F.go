package main

import (
	"fmt"
)

func main() {
	const mod = 1000000007
	var n, k int
	fmt.Scan(&n, &k)

	coef := []int{}
	for i := 1; i*i <= n; i++ {
		coef = append(coef, (n/i)-(n/(i+1)))
	}
	coef = append(coef, make([]int, n-sum(coef))...) // Fill the rest with 1s
	for i := range coef {
		coef[i] = 1
	}
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
			tmp += dp[i-1][nn-1-j]
			tmp %= mod
			dp[i][j] = coef[j] * tmp % mod
		}
	}

	result := 0
	for _, val := range dp[k] {
		result = (result + val) % mod
	}
	fmt.Println(result)
}

// Helper function to sum elements in a slice
func sum(arr []int) int {
	total := 0
	for _, v := range arr {
		total += v
	}
	return total
}

// Helper function to reverse a slice
func reverse(arr []int) []int {
	for i, j := 0, len(arr)-1; i < j; i, j = i+1, j-1 {
		arr[i], arr[j] = arr[j], arr[i]
	}
	return arr
}

// <END-OF-CODE>
