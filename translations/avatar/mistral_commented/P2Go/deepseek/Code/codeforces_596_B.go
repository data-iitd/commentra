package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)

	var r []int
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		r = append(r, x)
	}

	ans := math.Abs(float64(r[0]))

	for i := 1; i < n; i++ {
		ans += math.Abs(float64(r[i] - r[i-1]))
	}

	fmt.Println(ans)
}

