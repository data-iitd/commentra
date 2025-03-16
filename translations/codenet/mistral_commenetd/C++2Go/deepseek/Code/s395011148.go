package main

import (
	"fmt"
	"math"
)

const N = 1 << 18

var A [N]int64
var dp [N][2][20]int64

func main() {
	var n int
	fmt.Scan(&n)
	for i := 1; i <= n; i++ {
		fmt.Scan(&A[i])
	}

	// Initialize dp array with minimum values
	for i := 0; i <= n; i++ {
		for j := 0; j < 20; j++ {
			dp[i][0][j] = -int64(math.Pow(2, 60))
			dp[i][1][j] = -int64(math.Pow(2, 60))
		}
	}

	// Base case: dp[0][0][10] = 0
	dp[0][0][10] = 0

	// Iterate through all the elements of the array A
	for i := 1; i <= n; i++ {
		for j := 6; j <= 14; j++ {
			if dp[i-1][0][j] != -int64(math.Pow(2, 60)) {
				if dp[i][1][j+1] < dp[i-1][0][j]+int64(A[i]) {
					dp[i][1][j+1] = dp[i-1][0][j] + int64(A[i])
				}
				if dp[i][0][j-1] < dp[i-1][0][j] {
					dp[i][0][j-1] = dp[i-1][0][j]
				}
			}
			if dp[i-1][1][j] != -int64(math.Pow(2, 60)) {
				if dp[i][0][j-1] < dp[i-1][1][j] {
					dp[i][0][j-1] = dp[i-1][1][j]
				}
			}
		}
	}

	// Calculate the value of T1 and T2
	v := 10 + (n / 2) - (n - (n / 2))
	var t1, t2 int64
	t1 = dp[n][0][v]
	t2 = dp[n][1][v]

	// Print the maximum value of T1 and T2
	fmt.Println(max(t1, t2))
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

