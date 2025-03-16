package main

import (
	"fmt"
)

func main() {
	var N, L, R, QL, QR int
	fmt.Scan(&N, &L, &R, &QL, &QR)
	W := make([]int, N)
	sum := make([]int, N+1)
	for n := 0; n < N; n++ {
		fmt.Scan(&W[n])
		sum[n+1] = sum[n] + W[n]
	}
	min := int64(1e18)
	for firstR := 0; firstR <= N; firstR++ {
		lCount := firstR
		rCount := N - lCount
		cand := int64(sum[lCount]*L + (sum[N]-sum[lCount])*R)
		llCount := max(0, lCount-rCount-1)
		rrCount := max(0, rCount-lCount-1)
		cand += int64(llCount*QL + rrCount*QR)
		if cand < min {
			min = cand
		}
	}
	fmt.Println(min)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

