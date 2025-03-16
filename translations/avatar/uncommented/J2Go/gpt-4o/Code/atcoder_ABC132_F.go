package main

import (
	"fmt"
)

func main() {
	const mod = 1e9 + 7
	var n, k int
	fmt.Scan(&n, &k)

	len := []int{}
	l := 1
	for l <= n {
		r := n / (n / l)
		len = append(len, r-l+1)
		l = r + 1
	}
	q := len
	dp := make([]int64, k*(len(len)+1))

	for j := 1; j <= len(len); j++ {
		dp[j] = int64(len[j-1]) + dp[j-1]
	}

	for i := 1; i < k; i++ {
		for j := 1; j <= len(len); j++ {
			dp[i*(len(len)+1)+j] = dp[i*(len(len)+1)+j-1] + dp[(i-1)*(len(len)+1)+len(len)-j+1]*int64(len[j-1]))
			dp[i*(len(len)+1)+j] %= int64(mod)
		}
	}

	fmt.Println(dp[k*(len(len)+1)-1])
}

// <END-OF-CODE>
