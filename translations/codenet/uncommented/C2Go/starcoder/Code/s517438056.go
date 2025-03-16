package main

import (
	"fmt"
	"math"
)

func main() {
	var N, D, i, j, k, n int
	var l float64
	var matrix [][]int
	fmt.Scanf("%d%d", &N, &D)
	matrix = make([][]int, N)
	for i = 0; i < N; i++ {
		matrix[i] = make([]int, D)
	}
	for i = 0; i < N; i++ {
		for j = 0; j < D; j++ {
			fmt.Scanf("%d", &matrix[i][j])
		}
	}
	for i = 0; i < N - 1; i++ {
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
	fmt.Printf("%d\n", k)
}

