package main

import (
	"fmt"
)

func main() {
	var Q, H, S, D, N int64
	fmt.Scan(&Q, &H, &S, &D, &N)

	onePrice := min(min(Q*4, H*2), S)
	if float64(onePrice) <= float64(D)/2 {
		fmt.Println(N * onePrice)
	} else {
		fmt.Println((N / 2) * D + (N % 2) * onePrice)
	}
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}
