package main

import (
	"fmt"
)

func main() {
	var n, m, x int
	a := make([]int, 105)
	fmt.Scanf("%d %d %d", &n, &m, &x)

	for i := 0; i < m; i++ {
		var temp int
		fmt.Scanf("%d", &temp)
		a[temp] = 1
	}

	ansl, ansr, i := 0, 0, x
	for i <= n {
		ansr += a[i]
		i++
	}
	for i >= 0 {
		ansl += a[i]
		i--
	}

	fmt.Println(min(ansl, ansr))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

