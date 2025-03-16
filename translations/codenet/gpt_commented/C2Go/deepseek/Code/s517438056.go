package main

import (
	"fmt"
	"math"
	"os"
)

func main() {
	var N, D, i, j, k, n int
	var l float64
	matrix := make([][]int, N)

	fmt.Scan(&N, &D)

	for i = 0; i < N; i++ {
		matrix[i] = make([]int, D)
		for j = 0; j < D; j++ {
			fmt.Scan(&matrix[i][j])
		}
	}

	k = 0
	for i = 0; i < N-1; i++ {
		for j = i + 1; j < N; j++ {
			m := 0
			for n = 0; n < D; n++ {
				m += (matrix[i][n] - matrix[j][n]) * (matrix[i][n] - matrix[j][n])
			}
			l = math.Sqrt(float64(m))
			if math.Ceil(l) == math.Floor(l) {
				k++
			}
		}
	}

	fmt.Println(k)
}

