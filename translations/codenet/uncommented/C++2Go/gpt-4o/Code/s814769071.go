package main

import (
	"fmt"
)

func main() {
	var n, k int64
	fmt.Scan(&n, &k)
	const MOD = 1e9 + 7

	mx := n*(n+1)/2 - (n-k)*(n-k+1)/2
	mn := k * (k - 1) / 2
	res := int64(0)

	for i := k; i <= n+1; i++ {
		res = (res + mx - mn + 1) % MOD
		mx += n - i
		mn += i
	}

	fmt.Println(res)
}

// <END-OF-CODE>
