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

	min := int(math.MaxInt64)

	for firstR := 0; firstR <= N; firstR++ {
		lCount := firstR
		rCount := N - lCount

		cand := int64(sum[lCount]) * int64(L) + (int64(sum[N]) - int64(sum[lCount])) * int64(R)

		llCount := int(math.Max(0, float64(lCount-rCount-1)))
		rrCount := int(math.Max(0, float64(rCount-lCount-1)))

		cand += int64(llCount) * int64(QL)
		cand += int64(rrCount) * int64(QR)

		if cand < int64(min) {
			min = int(cand)
		}
	}

	fmt.Println(min)
}

