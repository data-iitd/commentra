package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var (
		n, k int
		l, r int
		q    int
		mod  = 1e9 + 7
	)
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	n, _ = strconv.Atoi(sc.Text())
	sc.Scan()
	k, _ = strconv.Atoi(sc.Text())
	sc.Split(bufio.ScanWords)
	sc.Scan()
	q, _ = strconv.Atoi(sc.Text())
	len := make([]int, q)
	l = 1
	for l <= n {
		r = n / (n / l)
		len[q-1] = r - l + 1
		l = r + 1
		q--
	}
	dp := make([]int, k*(q+1))
	for j := 1; j <= q; j++ {
		dp[j] = len[j-1] + dp[j-1]
	}
	for i := 1; i < k; i++ {
		for j := 1; j <= q; j++ {
			dp[i*(q+1)+j] = dp[i*(q+1)+j-1] + dp[(i-1)*(q+1)+q-j+1] * len[j-1]
			dp[i*(q+1)+j] %= mod
		}
	}
	fmt.Println(dp[k*(q+1)-1])
}

