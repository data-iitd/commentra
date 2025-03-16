package main

import (
	"fmt"
	"math"
)

func main() {
	var N, L, R, QL, QR int
	fmt.Scan(&N, &L, &R, &QL, &QR)
	W := make([]int, N)
	sum := make([]int, N+1)
	for i := 0; i < N; i++ {
		fmt.Scan(&W[i])
		sum[i+1] = sum[i] + W[i]
	}
	min := math.MaxInt64
	for firstR := 0; firstR <= N; firstR++ {
		lCount := firstR
		rCount := N - lCount
		cand := sum[lCount] * L + (sum[N] - sum[lCount]) * R
		llCount := int(math.Max(0, float64(lCount-rCount-1)))
		rrCount := int(math.Max(0, float64(rCount-lCount-1)))
		cand += llCount * QL
		cand += rrCount * QR
		min = int(math.Min(float64(cand), float64(min)))
	}
	fmt.Println(min)
}

