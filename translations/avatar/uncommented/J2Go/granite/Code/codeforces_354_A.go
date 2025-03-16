
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	var N, L, R, QL, QR int
	fmt.Fscanf(in, "%d %d %d %d %d\n", &N, &L, &R, &QL, &QR)
	W := make([]int, N)
	sum := make([]int, N+1)
	for n := 0; n < N; n++ {
		fmt.Fscanf(in, "%d", &W[n])
		sum[n+1] = sum[n] + W[n]
	}
	min := int64(1e18)
	for firstR := 0; firstR <= N; firstR++ {
		lCount := firstR
		rCount := N - lCount
		cand := int64(sum[lCount]) * int64(L) + (int64(sum[N]) - int64(sum[lCount]))*int64(R)
		llCount := int(max(0, lCount-rCount-1))
		rrCount := int(max(0, rCount-lCount-1))
		cand += int64(llCount) * int64(QL)
		cand += int64(rrCount) * int64(QR)
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

