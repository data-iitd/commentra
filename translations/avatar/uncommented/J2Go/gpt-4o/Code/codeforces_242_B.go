package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, n)
	b := make([]int, n)
	left := math.MaxInt32
	right := 0

	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		fmt.Scan(&b[i])
		if a[i] < left {
			left = a[i]
		}
		if b[i] > right {
			right = b[i]
		}
	}

	for i := 0; i < n; i++ {
		if left == a[i] && right == b[i] {
			fmt.Println(i + 1)
			return
		}
	}
	fmt.Println(-1)
}

// <END-OF-CODE>
