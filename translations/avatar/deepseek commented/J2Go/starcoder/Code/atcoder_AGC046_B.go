
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// <START-OF-CODE>

const MOD = 998244353

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Buffer(make([]byte, 1024), int(1e11))
	sc.Split(bufio.ScanWords)
	pw := bufio.NewWriter(os.Stdout)

	// Read the input values for A, B, C, and D
	A, _ := strconv.Atoi(sc.Text())
	B, _ := strconv.Atoi(sc.Text())
	C, _ := strconv.Atoi(sc.Text())
	D, _ := strconv.Atoi(sc.Text())

	// Initialize the dp array for the starting point (A, B)
	dp := make([][]int, C+1)
	for i := range dp {
		dp[i] = make([]int, D+1)
	}
	dp[A][B] = 1

	// Iterate over the range from A to C and from B to D
	for c := A; c <= C; c++ {
		for d := B; d <= D; d++ {
			// Skip the starting point (A, B)
			if c == A && d == B {
				continue
			}

			// Calculate the answer based on previous states
			ans := 0
			if c > A {
				part := dp[c-1][d]
				ans = (part * d) % MOD
			}
			if d > B {
				part := dp[c][d-1]
				ans = (ans + (part * c) % MOD) % MOD
			}
			if c > A && d > B {
				ans = (ans - (dp[c-1][d-1] * (c-1) * (d-1) % MOD) + MOD) % MOD
			}

			// Store the result in dp array
			dp[c][d] = ans
		}
	}

	// Output the result for the final state (C, D)
	fmt.Fprintln(pw, dp[C][D])

	pw.Flush()
	pw.Close()
	sc.Close()
}

// 