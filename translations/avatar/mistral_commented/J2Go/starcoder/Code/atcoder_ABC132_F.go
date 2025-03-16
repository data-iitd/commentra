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
	)

	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &n, &k)

	var (
		l, r, q int
		len     []int
	)

	l = 1
	for l <= n {
		r = n / (n / l)
		len = append(len, r-l+1)
		l = r + 1
	}

	q = len(len)
	dp := make([]int, k*(q+1))
	dp[0] = 1
	for i := 1; i < k; i++ {
		dp[i*(q+1)] = 1
		for j := 1; j <= q; j++ {
			dp[i*(q+1)+j] = (dp[i*(q+1)+j-1] + dp[(i-1)*(q+1)+q-j+1]*len[j-1]) % 1000000007
		}
	}

	fmt.Println(dp[k*(q+1)-1])
}

