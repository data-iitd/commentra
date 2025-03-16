package main

import (
	"fmt"
)

const mod = 1e9 + 7

func main() {
	var N, K int64
	fmt.Scan(&N, &K)
	A := make([]int64, N)
	for i := int64(0); i < N; i++ {
		fmt.Scan(&A[i])
	}

	// Solution
	ans1 := int64(0)
	for i := int64(0); i < N; i++ {
		for j := int64(0); j < N; j++ {
			if i >= j {
				continue
			}
			if A[i] > A[j] {
				ans1++
			}
			ans1 %= mod
		}
	}

	count := make([]int64, 2005)
	for i := int64(0); i < N; i++ {
		count[A[i]-1]++
	}

	ans2 := int64(0)
	remain := N
	for i := int64(0); i < 2005; i++ {
		remain -= count[i]
		ans2 += count[i] * remain
	}

	ans := int64(0)
	tmp := K * (K - 1) / 2
	tmp %= mod
	tmp *= ans2
	tmp %= mod
	ans += ans1 * K
	ans %= mod
	ans += tmp
	ans %= mod

	// Output
	fmt.Println(ans)
}

// <END-OF-CODE>
