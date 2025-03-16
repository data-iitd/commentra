
package main

import "fmt"

func main() {
	var N int
	fmt.Scan(&N)
	x := make([]float64, N)
	for i := 0; i < N; i++ {
		var s string
		fmt.Scan(&s)
		x[i] = eval(s)
	}
	fmt.Println(sum(x))
}

func eval(s string) float64 {
	if s == "JPY" {
		return 1.0
	} else if s == "BTC" {
		return 380000.0
	} else {
		return 0.0
	}
}

func sum(x []float64) float64 {
	var total float64
	for _, v := range x {
		total += v
	}
	return total
}

