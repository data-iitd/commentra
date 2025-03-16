package main

import (
	"fmt"
	"math"
)

func task4(A, B, n int) int {
	for X := -1000; X <= 1001; X++ {
		if A*int(math.Pow(float64(X), float64(n))) == B {
			return X
		}
	}
	return -1 // Return -1 to indicate no solution
}

func main() {
	var A, B, n int
	fmt.Scan(&A, &B, &n)
	result := task4(A, B, n)
	if result == -1 {
		fmt.Println("No solution")
	} else {
		fmt.Println(result)
	}
}
