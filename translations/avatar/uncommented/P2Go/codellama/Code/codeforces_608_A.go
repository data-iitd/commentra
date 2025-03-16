package main

import (
	"fmt"
	"os"
)

func main() {
	var n, s int
	fmt.Scan(&n, &s)
	c := 0
	for i := 0; i < n; i++ {
		var f, t int
		fmt.Scan(&f, &t)
		x := t - (s - f)
		if x > c {
			c = x
		}
	}
	fmt.Println(s + c)
}

