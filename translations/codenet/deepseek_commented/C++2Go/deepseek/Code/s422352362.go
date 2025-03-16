package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int64, n+1)
	pre := make([]int64, n+1)
	last := make([]int64, n+1)

	for i := 1; i <= n; i++ {
		fmt.Scan(&a[i])
	}

	var sumpre, sumlast int64
	for i := 1; i < n; i++ {
		sumpre += a[i]
		pre[i] = sumpre
	}

	for i := n; i > 1; i-- {
		sumlast += a[i]
		last[i] = sumlast
	}

	d := int64(math.Pow(2, 60))
	for i := 1; i < n; i++ {
		if diff := int64(math.Abs(float64(pre[i] - last[i+1])); diff < d {
			d = diff
		}
	}

	fmt.Println(d)
}
