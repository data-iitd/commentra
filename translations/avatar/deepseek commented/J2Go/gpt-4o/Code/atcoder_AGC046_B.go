package main

import (
	"fmt"
)

const MOD = 998244353

func solve(A, B, C, D int) int64 {
	dp := make([][]int64, 3001)
	for i := range dp {
		dp[i] = make([]int64, 3001)
	}

	// Initialize the dp array for the starting point (A, B)
	dp[A][B] = 1

	// Iterate over the range from A to C and from B to D
	for c := A; c <= C; c++ {
		for d := B; d <= D; d++ {
			// Skip the starting point (A, B)
			if c == A && d == B {
				continue
			}

			// Calculate the answer based on previous states
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
				ans = (ans - (dp[c-1][d-1] * int64(c-1) * int64(d-1) % MOD) + MOD) % MOD
			}

			// Store the result in dp array
			dp[c][d] = ans
		}
	}

	// Return the result for the final state (C, D)
	return dp[C][D]
}

func main() {
	var A, B, C, D int
	fmt.Scan(&A, &B, &C, &D)
	result := solve(A, B, C, D)
	fmt.Println(result)
}

// <END-OF-CODE>
