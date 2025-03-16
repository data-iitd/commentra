package main

import (
	"fmt"
)

const MOD = 998244353

func main() {
	var A, B, C, D int
	fmt.Scan(&A, &B, &C, &D)

	dp := make([][]int64, 3001)
	for i := range dp {
		dp[i] = make([]int64, 3001)
	}

	dp[A][B] = 1

	for c := A; c <= C; c++ {
		for d := B; d <= D; d++ {
			if c == A && d == B {
				continue
			}
			ans := int64(0)
			if c > A {
				part := dp[c-1][d]
				ans = (part * int64(d)) % MOD
			}
			if d > B {
				part := dp[c][d-1]
				ans = (ans + (part * int64(c)) % MOD) % MOD
			}
			if c > A && d > B {
				ans = (ans - (dp[c-1][d-1] * int64(c-1) * int64(d-1)) % MOD + MOD) % MOD
			}
			dp[c][d] = (ans + MOD) % MOD
		}
	}

	fmt.Println(dp[C][D])
}

// <END-OF-CODE>
