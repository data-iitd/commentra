package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)

	x := make([]float64, N)
	u := make([]string, N)

	for i := 0; i < N; i++ {
		fmt.Scan(&x[i], &u[i])
	}

	fmt.Println(solve(x, u))
}

func solve(x []float64, u []string) float64 {
	var sum float64
	for i := 0; i < len(x); i++ {
		if u[i] == "JPY" {
			sum += x[i]
		} else {
			sum += x[i] * 380000
		}
	}
	return sum
}

