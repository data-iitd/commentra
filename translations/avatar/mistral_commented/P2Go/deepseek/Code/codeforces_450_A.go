package main

import (
	"fmt"
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
		if l[i] % m == 0 {
			l2[i] = l[i] / m
		} else {
			l2[i] = l[i] / m + 1
		}
	}

	maxIndex := 0
	maxValue := l2[0]
	for i := 1; i < n; i++ {
		if l2[i] > maxValue {
			maxValue = l2[i]
			maxIndex = i
		}
	}

	fmt.Println(maxIndex + 1)
}

