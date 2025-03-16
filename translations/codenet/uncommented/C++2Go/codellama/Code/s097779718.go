package main

import "fmt"

func Euclid(x, y int64) int64 {
	var tmp int64

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
	var A, B int64
	fmt.Scan(&A, &B)

	fmt.Println((A * B) / Euclid(A, B))
}

