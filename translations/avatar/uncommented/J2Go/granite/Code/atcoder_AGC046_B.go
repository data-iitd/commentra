
package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = 998244353

var (
	dp [3001][3001]int64
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	A := nextInt(sc)
	B := nextInt(sc)
	C := nextInt(sc)
	D := nextInt(sc)
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
				ans = (ans + (part * int64(c))) % MOD
			}
			if c > A && d > B {
				ans = (ans - (dp[c-1][d-1]*int64(c-1)*int64(d-1)) % MOD + MOD) % MOD
			}
			dp[c][d] = ans
		}
	}
	fmt.Println(dp[C][D])
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	i, _ := fmt.Sscanf(sc.Text(), "%d")
	return i
}

// 