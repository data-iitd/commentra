package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = 998244353

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	scanner.Scan()
	var A, B, C, D int
	fmt.Sscanf(scanner.Text(), "%d %d %d %d", &A, &B, &C, &D)

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
				ans = (ans - (dp[c-1][d-1] * int64(c-1) * int64(d-1)) % MOD + MOD) % MOD
			}

			dp[c][d] = (ans + MOD) % MOD
		}
	}

	fmt.Fprintln(writer, dp[C][D])
}

