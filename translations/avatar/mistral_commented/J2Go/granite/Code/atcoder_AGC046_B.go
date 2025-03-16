

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
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	var a, b, c, d int
	fmt.Fscanf(reader, "%d %d %d %d\n", &a, &b, &c, &d)

	dp[a][b] = 1

	for c1 := a; c1 <= c; c1++ {
		for d1 := b; d1 <= d; d1++ {
			if c1 == a && d1 == b {
				continue
			}

			ans := int64(0)

			if c1 > a {
				part := dp[c1-1][d1]
				ans = (part * int64(d1)) % MOD
			}

			if d1 > b {
				part := dp[c1][d1-1]
				ans = (ans + (part * int64(c1))) % MOD
			}

			if c1 > a && d1 > b {
				ans = (ans - (dp[c1-1][d1-1] * int64((c1-1)*(d1-1)))) % MOD
			}

			dp[c1][d1] = (ans + MOD) % MOD
		}
	}

	fmt.Fprintf(writer, "%d\n", dp[c][d])

	writer.Flush()
}

These comments should provide a clear understanding of the code for anyone who reads it.