package main

import (
	"fmt"
	"math"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	var l []int
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		l = append(l, x)
	}

	l2 := make([]int, n)
	for i := 0; i < n; i++ {
		if l[i]%m == 0 {
			l2[i] = l[i] / m
		} else {
			l2[i] = l[i]/m + 1
		}
	}

	mx := 0
	ind := 0
	for i := 0; i < n; i++ {
		if l2[i] > mx {
			mx = l2[i]
			ind = i
		}
	}

	fmt.Println(ind + 1)
}

