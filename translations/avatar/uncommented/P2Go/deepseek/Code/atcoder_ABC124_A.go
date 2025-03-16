package main

import (
	"fmt"
)

func main() {
	var a, b int
	fmt.Scan(&a, &b)
	c := 0
	for i := 0; i < 2; i++ {
		c += max(a, b)
		if a >= b {
			a--
		} else {
			b--
		}
	}
	fmt.Println(c)
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}
