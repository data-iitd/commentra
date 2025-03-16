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

	for i := 0; i < N; i++ {
		x, y := XY[i][0], XY[i][1]
		var D []float64

		for j := 0; j < N; j++ {
			if j != i {
				X, Y := XY[j][0], XY[j][1]
				angle := math.Atan2(float64(X-x), float64(Y-y))
				D = append(D, angle)
			}
		}

		sort.Float64s(D)
		D = append(D, D[0]+2*math.Pi)

		ans := 0.0
		for k := 0; k < len(D)-1; k++ {
			a, b := D[k], D[k+1]
			if b-a >= math.Pi {
				ans = (b - a) - math.Pi
			}
		}

		fmt.Println(ans / (2 * math.Pi))
	}
}

// <END-OF-CODE>
