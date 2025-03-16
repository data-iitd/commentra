package main

import (
	"fmt"
	"math"
)

func main() {
	var N, D int
	fmt.Scan(&N, &D)
	vectors := make([][]int, N)
	for i := 0; i < N; i++ {
		vectors[i] = make([]int, D)
		for j := 0; j < D; j++ {
			fmt.Scan(&vectors[i][j])
		}
	}
	answer := 0
	for i := 0; i < N-1; i++ {
		for j := i + 1; j < N; j++ {
			dist := 0
			for d := 0; d < D; d++ {
				x := vectors[i][d] - vectors[j][d]
				dist += x * x
			}
			sq := math.Sqrt(float64(dist))
			if math.Abs(sq-math.Floor(sq)) < 1e-3 {
				answer++
			}
		}
	}
	fmt.Println(answer)
}

