package main

import (
	"fmt"
	"math"
)

func main() {
	solve()
}

func solve() {
	var N int
	var X int64
	fmt.Scan(&N)
	fmt.Scan(&X)

	x := make([]int64, N)
	xsum := make([]int64, N+1)

	for i := 0; i < N; i++ {
		fmt.Scan(&x[i])
		xsum[i+1] = xsum[i] + x[i]
	}

	ans := X*int64(N) + 5*xsum[N]
	for i := 1; i < N; i++ {
		cost := X*int64(i) + 5*(xsum[N]-xsum[N-i])
		for j, k := int64(5), N-i; k >= 0; j += 2 {
			if cost > ans {
				break
			}
			cost += j * (xsum[k] - xsum[max(k-i, 0)])
			k -= i
		}
		ans = min(ans, cost)
	}

	fmt.Println(ans + int64(N)*X)
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}
