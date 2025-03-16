package main

import (
	"fmt"
	"math"
)

const MAX = 100

func main() {
	var n int
	fmt.Scan(&n)

	x := make([]int, n)
	y := make([]int, n)
	h := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&x[i], &y[i], &h[i])
	}

	for i := 0; i <= MAX; i++ {
		for j := 0; j <= MAX; j++ {
			ch := check(n, x, y, h, i, j)
			if ch > 0 {
				fmt.Printf("%d %d %d\n", i, j, ch)
			}
		}
	}
}

func check(n int, x, y, h []int, cx, cy int) int {
	ch := -1
	for i := 0; i < n; i++ {
		if h[i] > 0 {
			ch = math.Abs(float64(x[i]-cx)) + math.Abs(float64(y[i]-cy)) + float64(h[i])
			break
		}
	}

	for i := 0; i < n; i++ {
		if h[i] != int(math.Max(float64(ch-math.Abs(float64(x[i]-cx))-math.Abs(float64(y[i]-cy))), 0)) {
			return -1
		}
	}
	return ch
}

// <END-OF-CODE>
