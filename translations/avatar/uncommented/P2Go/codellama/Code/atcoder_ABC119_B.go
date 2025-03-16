
package main

import "fmt"

func main() {
	var N int
	fmt.Scan(&N)
	x := make([]float64, N)
	for i := 0; i < N; i++ {
		var s string
		fmt.Scan(&s)
		if s == "JPY" {
			x[i] = 1.0
		} else {
			x[i] = 380000.0
		}
	}
	fmt.Println(sum(x))
}

func sum(x []float64) float64 {
	var s float64
	for _, v := range x {
		s += v
	}
	return s
}

