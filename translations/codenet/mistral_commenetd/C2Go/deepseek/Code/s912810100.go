package main

import (
	"fmt"
)

func main() {
	var a, b, x, y int

	fmt.Scan(&a, &b)

	x = a * b
	y = (a + b) * 2

	fmt.Println(x, y)
}

