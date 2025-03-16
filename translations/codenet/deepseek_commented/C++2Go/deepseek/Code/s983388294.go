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
	curr := 0
	for i := 0; i < n; i++ {
		if a[i] == curr+1 {
			curr++
		}
	}
	if curr > 0 {
		fmt.Println(n - curr)
	} else {
		fmt.Println(-1)
	}
}

