package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N)

	XY := make([][2]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&XY[i][0], &XY[i][1])
	}

	ans := 0.0

	for i, point := range XY {
		x, y := point[0], point[1]
		D := make([]float64, 0, N-1)

		for j, otherPoint := range XY {
			if j != i {
				X, Y := otherPoint[0], otherPoint[1]
				D = append(D, math.Atan2(float64(X-x), float64(Y-y)))
			}
		}

		sort.Float64s(D)
		D = append(D, D[0]+2*math.Pi)

		for k := 0; k < len(D)-1; k++ {
			a, b := D[k], D[k+1]
			if b-a >= math.Pi {
				ans += (b - a) - math.Pi
			}
		}
	}

	fmt.Println(ans / (2 * math.Pi))
}

// <END-OF-CODE>
