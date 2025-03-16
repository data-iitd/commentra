package main

import (
	"fmt"
	"math"
)

func main() {
	var n, x int
	fmt.Scan(&n, &x)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	b := make([][]int, n)
	for i := range b {
		b[i] = make([]int, n)
	}

	for i := 0; i < n; i++ {
		m := a[i]
		for j := 0; j < n; j++ {
			k := i - j
			if k < 0 {
				k += n
			}
			m = min(m, a[k])
			b[j][i] = m
		}
	}

	m := math.MaxInt64
	for i, j := range b {
		sum := 0
		for _, val := range j {
			sum += val
		}
		m = min(m, sum+x*i)
	}
	fmt.Println(m)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>
