package main

import (
	"fmt"
	"math"
)

const MAX_N = 200005

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int64, MAX_N)
	pre := make([]int64, MAX_N)
	last := make([]int64, MAX_N)

	for i := 1; i <= n; i++ {
		fmt.Scan(&a[i])
		pre[i] = pre[i-1] + a[i]
		last[i] = last[i+1] + a[i]
	}

	var sumpre, sumlast int64

	for i := 1; i < n; i++ {
		sumpre += a[i]
		pre[i] = sumpre
	}

	for i := n; i > 0; i-- {
		sumlast += a[i]
		last[i] = sumlast
	}

	d := int64(math.MaxInt64)

	for i := 1; i < n; i++ {
		d = min(d, abs(pre[i]-last[i+1]))
	}

	fmt.Println(d)
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func abs(a int64) int64 {
	if a < 0 {
		return -a
	}
	return a
}

