package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	t := 0

	for i := 0; i < n; i++ {
		s := 0
		for j := 1; j < n; j++ {
			if j <= i {
				continue
			}
			m := a[i] * a[j]
			s += m
		}
		t += s
	}

	fmt.Println(t)
}

