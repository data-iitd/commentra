
package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = 100000007

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var n, k int
	sc.Scan()
	n = int(binary.BigEndian.Uint64(sc.Bytes()))
	sc.Scan()
	k = int(binary.BigEndian.Uint64(sc.Bytes()))
	var len []int
	l := 1
	for l <= n {
		r := n / (n / l)
		len = append(len, r-l+1)
		l = r + 1
	}
	q := len(len)
	dp := make([]int, k*(q+1))
	for j := 1; j <= q; j++ {
		dp[j] = len[j-1] + dp[j-1]
	}
	for i := 1; i < k; i++ {
		for j := 1; j <= q; j++ {
			dp[i*(q+1)+j] = dp[i*(q+1)+j-1]+dp[(i-1)*(q+1)+q-j+1]*len[j-1]
			dp[i*(q+1)+j] %= MOD
		}
	}
	fmt.Println(dp[k*(q+1)-1])
}

