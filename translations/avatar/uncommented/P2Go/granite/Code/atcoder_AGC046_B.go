
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const MOD = 998244353

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var a, b, c, d int
	sc.Scan()
	a, _ = strconv.Atoi(sc.Text())
	sc.Scan()
	b, _ = strconv.Atoi(sc.Text())
	sc.Scan()
	c, _ = strconv.Atoi(sc.Text())
	sc.Scan()
	d, _ = strconv.Atoi(sc.Text())
	dp := make([][]int64, c+1)
	for i := 0; i <= c; i++ {
		dp[i] = make([]int64, d+1)
	}
	dp[a][b] = 1
	for i := a; i <= c; i++ {
		for j := b; j <= d; j++ {
			dp[i][j] += (dp[i][j-1]*int64(i) + dp[i-1][j]*int64(j) - dp[i-1][j-1]*int64(i-1)*int64(j-1)) % MOD
		}
	}
	fmt.Println(dp[c][d])
}
