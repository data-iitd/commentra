package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)

	var a []int
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		a = append(a, x)
	}

	b := make([]int, n)
	for i := 0; i < n; i++ {
		b[a[i]-1] = i
	}

	res := 0
	for i := 1; i < n; i++ {
		res += int(math.Abs(float64(b[i] - b[i-1])))
	}

	fmt.Println(res)
}

