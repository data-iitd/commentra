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

	r := []string{}
	m := 0
	for i := 1; i < n; i++ {
		if math.Abs(float64(a[m])) < math.Abs(float64(a[i])) {
			m = i
		}
	}

	for i := 0; i < n; i++ {
		if a[m] >= 0 != a[i] >= 0 {
			r = append(r, fmt.Sprintf("%d %d", m+1, i+1))
		}
	}

	if a[m] >= 0 {
		for i := 1; i < n; i++ {
			r = append(r, fmt.Sprintf("%d %d", i, i+1))
		}
	} else {
		for i := n; i > 1; i-- {
			r = append(r, fmt.Sprintf("%d %d", i, i-1))
		}
	}

	fmt.Println(len(r))
	for _, v := range r {
		fmt.Println(v)
	}
}

