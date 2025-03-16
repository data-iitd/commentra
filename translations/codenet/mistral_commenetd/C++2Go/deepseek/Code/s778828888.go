package main

import (
	"fmt"
	"math"
)

func main() {
	var n, m, x int
	fmt.Scan(&n, &m, &x)

	a := make([]int, 105)
	for i := 0; i < m; i++ {
		var temp int
		fmt.Scan(&temp)
		a[temp] = 1
	}

	ansl, ansr := 0, 0
	for i := x; i <= n; i++ {
		ansr += a[i]
	}

	for i := x; i >= 0; i-- {
		ansl += a[i]
	}

	fmt.Println(int(math.Min(float64(ansl), float64(ansr))))
}

