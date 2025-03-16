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

	result := solve(x, u)
	fmt.Println(result)
}

func solve(x []float64, u []string) float64 {
	var total float64
	for i := 0; i < len(x); i++ {
		if u[i] == "JPY" {
			total += x[i]
		} else if u[i] == "BTC" {
			total += x[i] * 380000
		}
	}
	return total
}

