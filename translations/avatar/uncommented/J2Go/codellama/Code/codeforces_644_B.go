package main

import (
	"fmt"
	"os"
)

func main() {
	sc := make([]int, 0)
	var n, b int
	fmt.Scan(&n, &b)
	ans := make([]int, n)
	q := make([]int, 0)
	for i := 0; i < n; i++ {
		var t, d int
		fmt.Scan(&t, &d)
		for len(q) > 0 && q[0] <= t {
			q = q[1:]
		}
		if len(q) <= b {
			ans[i] = (q[len(q)-1] + d)
			q = append(q, ans[i])
		} else {
			ans[i] = -1
		}
	}
	for i := 0; i < n; i++ {
		fmt.Printf("%d ", ans[i])
	}
}

