package main

import (
	"fmt"
)

func main() {
	var n, i, j, p int
	p = 97
	fmt.Scan(&n)
	c := make([]rune, n)

	for i = 0; i < 4; i++ {
		for j = i; j < n; j += 4 {
			c[j] = rune(p)
		}
		p++
	}

	for i = 0; i < n; i++ {
		fmt.Print(string(c[i]))
	}
}

