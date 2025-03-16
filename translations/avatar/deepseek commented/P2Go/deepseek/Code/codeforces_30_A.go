package main

import (
	"fmt"
	"math"
)

func task4(A, B, n int) string {
	for X := -1000; X <= 1000; X++ {
		if A*int(math.Pow(float64(X), float64(n))) == B {
			return fmt.Sprintf("%d", X)
		}
	}
	return "No solution"
}

func main() {
	var A, B, n int
	fmt.Scan(&A, &B, &n)
	fmt.Println(task4(A, B, n))
}

