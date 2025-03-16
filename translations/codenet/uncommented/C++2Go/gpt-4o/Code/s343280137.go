package main

import (
	"fmt"
)

const INF = 1 << 29
const MOD = 1000000007

func main() {
	var n, c int64
	fmt.Scan(&n, &c)

	x := make([]int64, n+1)
	v := make([]int64, n+1)

	for i := int64(1); i <= n; i++ {
		fmt.Scan(&x[i], &v[i])
	}

	lefttotal := make([]int64, n+1)
	maxlefttotal := make([]int64, n+1)
	for i := int64(1); i <= n; i++ {
		lefttotal[i] = lefttotal[i-1] + v[i]
	}

	for i := int64(1); i <= n; i++ {
		maxlefttotal[i] = max(maxlefttotal[i-1], lefttotal[i]-x[i])
	}

	righttotal := make([]int64, n+1)
	maxrighttotal := make([]int64, n+1)
	for i := int64(1); i <= n; i++ {
		righttotal[i] = righttotal[i-1] + v[n-i+1]
	}

	for i := int64(1); i <= n; i++ {
		maxrighttotal[i] = max(maxrighttotal[i-1], righttotal[i]-(c-x[n+1-i]))
	}

	ans := int64(0)

	for i := int64(1); i <= n; i++ {
		ans = max(ans, lefttotal[i]-x[i])
		ans = max(ans, lefttotal[i]-2*x[i]+maxrighttotal[n-i])
		ans = max(ans, righttotal[i]-(c-x[n+1-i]))
		ans = max(ans, righttotal[i]-2*(c-x[n+1-i])+maxlefttotal[n-i])
	}

	fmt.Println(ans)
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>
