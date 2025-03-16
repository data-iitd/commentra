package main

import (
	"fmt"
	"math"
)

func Euclid(x, y int) int {
	var tmp int

	if x < y {
		tmp = x
		x = y
		y = tmp
	}

	if x%y == 0 {
		return y
	}
	return Euclid(y, x%y)
}

func main() {
	var A, B int
	fmt.Scanf("%d %d", &A, &B)

	fmt.Printf("%d\n", A*B/Euclid(A, B))
}

