package main

import (
	"fmt"
)

const mod = 1e9 + 7

func main() {
	var N, K int
	fmt.Scan(&N, &K)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	ans1 := 0
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			if i >= j {
				continue
			}
			if A[i] > A[j] {
				ans1++
			}
			ans1 %= mod
		}
	}

	count := make([]int, 2005)
	for i := 0; i < N; i++ {
		count[A[i]-1]++
	}

	ans2 := 0
	remain := N
	for i := 0; i < 2005; i++ {
		remain -= count[i]
		ans2 += count[i] * remain
	}

	ans := 0
	tmp := K * (K - 1) / 2
	tmp %= mod
	tmp *= ans2
	tmp %= mod
	ans += ans1 * K
	ans %= mod
	ans += tmp
	ans %= mod

	fmt.Println(ans)
}

