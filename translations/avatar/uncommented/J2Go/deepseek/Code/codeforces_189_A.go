package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	maxn := 4010
	a := 0
	b := 0
	c := 0
	fmt.Scan(&a, &b, &c)
	arr := []int{a, b, c}
	dp := make([]int, maxn)
	for i := 0; i < maxn; i++ {
		dp[i] = -2147483648
	}
	dp[0] = 0
	for i := 0; i < 3; i++ {
		for j := arr[i]; j < maxn; j++ {
			if dp[j] < dp[j-arr[i]]+1 {
				dp[j] = dp[j-arr[i]] + 1
			}
		}
	}
	fmt.Println(dp[n])
}
