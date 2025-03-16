package main

import (
	"fmt"
	"math"
)

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func ruisekiLR(array []int) ([]int, []int) {
	op := func(a, b int) int {
		return gcd(a, b)
	}
	e := 0
	n := len(array)
	left := make([]int, n+1)
	right := make([]int, n+1)
	for i := range left {
		left[i] = e
	}
	for i := range right {
		right[i] = e
	}
	for i := 0; i < n; i++ {
		left[i+1] = op(left[i], array[i])
	}
	for i := n - 1; i >= 0; i-- {
		right[i] = op(right[i+1], array[i])
	}
	return left, right
}

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := range a {
		fmt.Scan(&a[i])
	}
	left, right := ruisekiLR(a)
	ans := 0
	for i := 0; i < n; i++ {
		ans = int(math.Max(float64(ans), float64(gcd(left[i], right[i+1]))))
	}
	fmt.Println(ans)
}

