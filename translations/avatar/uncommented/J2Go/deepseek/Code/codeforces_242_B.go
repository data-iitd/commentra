package main

import (
	"fmt"
	"math"
)

const INF = int(1e9 + 5)

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	b := make([]int, n)
	left := INF
	right := 0
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i], &b[i])
		if a[i] < left {
			left = a[i]
		}
		if b[i] > right {
			right = b[i]
		}
	}
	for i := 0; i < n; i++ {
		if a[i] == left && b[i] == right {
			fmt.Println(i + 1)
			return
		}
	}
	fmt.Println(-1)
}

