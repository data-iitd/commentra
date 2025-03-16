package main

import (
	"fmt"
	"math"
)

func main() {
	var N, D int
	fmt.Scan(&N, &D)

	matrix := make([][]int, N)
	for i := 0; i < N; i++ {
		matrix[i] = make([]int, D)
		for j := 0; j < D; j++ {
			fmt.Scan(&matrix[i][j])
		}
	}

	k := 0
	for i := 0; i < N-1; i++ {
		for j := i + 1; j < N; j++ {
			m := 0
			for n := 0; n < D; n++ {
				diff := matrix[i][n] - matrix[j][n]
				m += diff * diff
			}
			l := math.Sqrt(float64(m))
			if l == math.Floor(l) {
				k++
			}
		}
	}
	fmt.Println(k)
}
