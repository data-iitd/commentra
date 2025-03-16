package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	var a, b, c int
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		a += x
	}
	for i := 0; i < n-1; i++ {
		var x int
		fmt.Scan(&x)
		b += x
	}
	for i := 0; i < n-2; i++ {
		var x int
		fmt.Scan(&x)
		c += x
	}

	x := a - b
	y := b - c
	fmt.Println(x)
	fmt.Println(y)
}

