package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = 998244353

var dp [3001][3001]int64

func solve(sc *bufio.Scanner, pw *bufio.Writer) {
	// Read the input values for A, B, C, and D
	var A, B, C, D int
	fmt.Fscan(sc, &A, &B, &C, &D)

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
			var ans int64 = 0
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

	// Output the result for the final state (C, D)
	fmt.Fprintln(pw, dp[C][D])
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	pw := bufio.NewWriter(os.Stdout)
	defer pw.Flush()
	solve(sc, pw)
}

