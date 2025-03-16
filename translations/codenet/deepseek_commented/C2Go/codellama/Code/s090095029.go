package main

import (
	"fmt"
	"strings"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	r0 := make([]bool, n)
	r1 := make([]int, n)
	nr1 := 0
	for i := 0; i < m; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		if a > b {
			a, b = b, a
		}
		if a == 1 {
			r0[b-1] = true
		}
		if b == n {
			r1[nr1] = a - 1
			nr1++
		}
	}
	res := false
	for i := 0; i < nr1; i++ {
		if r0[r1[i]] {
			res = true
		}
	}
	if res {
		fmt.Println("POSSIBLE")
	} else {
		fmt.Println("IMPOSSIBLE")
	}
}

