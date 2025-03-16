package main

import (
	"fmt"
	"math"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	var mod = int(math.Pow(10, 9) + 7)
	var len = make([]int, 0)
	var l = 1
	for l <= n {
		var r = n / (n / l)
		len = append(len, r-l+1)
		l = r + 1
	}

	var q = len(len)
	var dp = make([]int, k*(q+1))

	for j := 1; j <= q; j++ {
		dp[j] = len[j-1] + dp[j-1]
	}

	for i := 1; i < k; i++ {
		for j := 1; j <= q; j++ {
			dp[i*(q+1)+j] = dp[i*(q+1)+j-1] + dp[(i-1)*(q+1)+q-j+1]*len[j-1]
			dp[i*(q+1)+j] %= mod
		}
	}

	fmt.Println(dp[k*(q+1)-1])
}

