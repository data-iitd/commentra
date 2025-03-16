package main

import (
	"fmt"
)

const MOD = 998244353

func solve(A, B, C, D int) int64 {
	// Create a 2D slice for dynamic programming
	dp := make([][]int64, 3001)
	for i := range dp {
		dp[i] = make([]int64, 3001)
	}

	// Initialize the starting point in the dp array
	dp[A][B] = 1

	// Iterate over the range from A to C and B to D
	for c := A; c <= C; c++ {
		for d := B; d <= D; d++ {
			// Skip the initial point
			if c == A && d == B {
				continue
			}

			// Variable to store the current answer
			ans := int64(0)

			// If moving down (increasing c)
			if c > A {
				part := dp[c-1][d]
				ans = (part * int64(d)) % MOD // Calculate contribution from the previous row
			}

			// If moving right (increasing d)
			if d > B {
				part := dp[c][d-1]
				ans = (ans + (part * int64(c)) % MOD) % MOD // Calculate contribution from the previous column
			}

			// If moving diagonally (increasing both c and d)
			if c > A && d > B {
				ans = (ans - (dp[c-1][d-1] * int64(c-1) * int64(d-1)) % MOD + MOD) % MOD // Adjust for double counting
			}

			// Store the result in the dp array with modulo adjustment
			dp[c][d] = (ans + MOD) % MOD
		}
	}

	// Return the final result for dp[C][D]
	return dp[C][D]
}

func main() {
	var A, B, C, D int
	fmt.Scan(&A, &B, &C, &D) // Read input values A, B, C, D
	result := solve(A, B, C, D)
	fmt.Println(result) // Output the final result for dp[C][D]
}

// <END-OF-CODE>
