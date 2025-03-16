package main

import (
	"fmt"
)

func Euclid(x, y int) int {
	if x < y {
		x, y = y, x
	}

	if y == 0 {
		return x
	}
	return Euclid(y, x%y)
}

func main() {
	var A, B int
	fmt.Scan(&A, &B)

	fmt.Println((A * B) / Euclid(A, B))
}

