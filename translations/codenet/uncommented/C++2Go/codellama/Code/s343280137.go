package main

import (
	"fmt"
	"math"
)

func main() {
	var n, c int
	fmt.Scan(&n, &c)

	x := make([]int, n+1)
	v := make([]int, n+1)

	for i := 1; i < n+1; i++ {
		fmt.Scan(&x[i], &v[i])
	}

	lefttotal := make([]int, n+1)
	maxlefttotal := make([]int, n+1)
	for i := 1; i < n+1; i++ {
		lefttotal[i] = lefttotal[i-1] + v[i]
	}

	for i := 1; i < n+1; i++ {
		maxlefttotal[i] = int(math.Max(float64(maxlefttotal[i-1]), float64(lefttotal[i]-x[i])))
	}

	righttotal := make([]int, n+1)
	maxrighttotal := make([]int, n+1)
	for i := 1; i < n+1; i++ {
		righttotal[i] = righttotal[i-1] + v[n-i+1]
	}

	for i := 1; i < n+1; i++ {
		maxrighttotal[i] = int(math.Max(float64(maxrighttotal[i-1]), float64(righttotal[i]-(c-x[n+1-i]))))
	}

	ans := 0

	for i := 1; i < n+1; i++ {
		ans = int(math.Max(float64(ans), float64(lefttotal[i]-x[i])))
		ans = int(math.Max(float64(ans), float64(lefttotal[i]-2*x[i]+maxrighttotal[n-i])))
		ans = int(math.Max(float64(ans), float64(righttotal[i]-(c-x[n+1-i]))))
		ans = int(math.Max(float64(ans), float64(righttotal[i]-2*(c-x[n+1-i])+maxlefttotal[n-i])))
	}

	fmt.Println(ans)
}

