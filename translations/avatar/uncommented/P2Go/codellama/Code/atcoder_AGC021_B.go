package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	fmt.Scan(&N)
	XY := make([][2]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&XY[i][0], &XY[i][1])
	}
	for i, xy := range XY {
		D := make([]float64, N)
		for j, xy2 := range XY {
			if i != j {
				D[j] = math.Atan2(float64(xy[0]-xy2[0]), float64(xy[1]-xy2[1]))
			}
		}
		D = append(D, D[0]+2*math.Pi)
		ans := 0.0
		for a, b := range D {
			if b-a >= math.Pi {
				ans = b - a - math.Pi
			}
		}
		fmt.Println(ans / (2 * math.Pi))
	}
}

