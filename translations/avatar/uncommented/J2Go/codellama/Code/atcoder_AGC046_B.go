
package main

import (
	"fmt"
	"math"
)

func main() {
	MOD := int64(998244353)
	dp := make([][]int64, 3001)
	for i := range dp {
		dp[i] = make([]int64, 3001)
	}
	var solve func(A, B, C, D int) int64
	solve = func(A, B, C, D int) int64 {
		if A == C && B == D {
			return 1
		}
		if dp[A][B] != 0 {
			return dp[A][B]
		}
		ans := int64(0)
		if A < C {
			ans += solve(A+1, B, C, D) * int64(B)
			ans %= MOD
		}
		if B < D {
			ans += solve(A, B+1, C, D) * int64(A)
			ans %= MOD
		}
		if A < C && B < D {
			ans -= solve(A+1, B+1, C, D) * int64(A-1) * int64(B-1)
			if ans < 0 {
				ans += MOD
			}
		}
		dp[A][B] = ans
		return ans
	}
	var A, B, C, D int
	fmt.Scan(&A, &B, &C, &D)
	fmt.Println(solve(A, B, C, D))
}

