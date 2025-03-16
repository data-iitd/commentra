package main

import (
	"fmt"
)

const (
	INF  = 1001001001001001
	inf  = 1000000007
	MOD  = 1000000007
	PI   = 3.1415926535897932
)

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int64, n)
	acc := make([]int64, n+1)

	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		acc[i+1] = (acc[i] + a[i]) % MOD
	}

	var ans int64 = 0
	for i := 0; i < n; i++ {
		ans = (ans + (a[i]%MOD)*(MOD+acc[n]-acc[i+1])%MOD) % MOD
	}

	fmt.Println(ans)
}

// <END-OF-CODE>
