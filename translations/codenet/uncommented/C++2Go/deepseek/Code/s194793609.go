package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	abs_a := make([]int, n)
	for i := 0; i < n; i++ {
		abs_a[i] = int(math.Abs(float64(a[i])))
	}

	ans := 0
	min := abs_a[0]
	for _, e := range abs_a {
		ans += e
		if min > e {
			min = e
		}
	}

	num_negative := 0
	for _, e := range a {
		if e < 0 {
			num_negative++
		}
	}

	if num_negative%2 != 0 {
		ans -= min * 2
	}

	fmt.Println(ans)
}

