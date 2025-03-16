package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	fmt.Scan(&N)
	XY := make([][2]float64, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&XY[i][0], &XY[i][1])
	}

	for i := 0; i < N; i++ {
		x, y := XY[i][0], XY[i][1]
		D := make([]float64, 0, N-1)
		for j := 0; j < N; j++ {
			if i != j {
				dx := XY[j][0] - x
				dy := XY[j][1] - y
				D = append(D, math.Atan2(dy, dx))
			}
		}
		sort.Float64s(D)
		D = append(D, D[0]+2*math.Pi)
		ans := 0.0
		for a, b := range D {
			if b-a >= math.Pi {
				ans = (b - a) - math.Pi
				break
			}
		}
		fmt.Println(ans / (2 * math.Pi))
	}
}

