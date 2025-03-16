package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	a, b, c := 0, 0, 0

	for i := 0; i < n; i++ {
		var num int
		fmt.Scan(&num)
		a += num
	}

	for i := 0; i < n-1; i++ {
		var num int
		fmt.Scan(&num)
		b += num
	}

	for i := 0; i < n-2; i++ {
		var num int
		fmt.Scan(&num)
		c += num
	}

	x := a - b
	y := b - c

	fmt.Println(x)
	fmt.Println(y)
}

// <END-OF-CODE>
