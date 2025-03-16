package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = 998244353

var dp [][]int64

func solve(sc *bufio.Scanner, pw *bufio.Writer) {
	sc.Scan()
	A := parseInt(sc.Text())
	sc.Scan()
	B := parseInt(sc.Text())
	sc.Scan()
	C := parseInt(sc.Text())
	sc.Scan()
	D := parseInt(sc.Text())

	dp = make([][]int64, 3001)
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

	pw.WriteString(fmt.Sprintf("%d\n", dp[C][D]))
}

func parseInt(s string) int {
	var res int
	fmt.Sscanf(s, "%d", &res)
	return res
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	pw := bufio.NewWriter(os.Stdout)
	defer pw.Flush()
	solve(sc, pw)
}

