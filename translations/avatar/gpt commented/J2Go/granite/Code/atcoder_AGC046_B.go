
package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = 998244353

var (
	dp  = make([][]int64, 3001)
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func init() {
	for i := range dp {
		dp[i] = make([]int64, 3001)
	}
}

func main() {
	var a, b, c, d int
	fmt.Fscanf(in, "%d%d%d%d\n", &a, &b, &c, &d)

	dp[a][b] = 1

	for i := a; i <= c; i++ {
		for j := b; j <= d; j++ {
			if i == a && j == b {
				continue
			}

			ans := int64(0)

			if i > a {
				part := dp[i-1][j]
				ans = (part * int64(j)) % MOD
			}

			if j > b {
				part := dp[i][j-1]
				ans = (ans + (part * int64(i))) % MOD
			}

			if i > a && j > b {
				ans = (ans - (dp[i-1][j-1]*int64(i-1)*int64(j-1)) + MOD) % MOD
			}

			dp[i][j] = ans
		}
	}

	fmt.Fprintf(out, "%d\n", dp[c][d])
	out.Flush()
}

