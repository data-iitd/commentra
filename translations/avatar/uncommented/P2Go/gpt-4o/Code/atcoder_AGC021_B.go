package main

import (
	"fmt"
	"math"
	"os"
	"sort"
)

func main() {
	var N int
	fmt.Fscan(os.Stdin, &N)
	XY := make([][2]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscan(os.Stdin, &XY[i][0], &XY[i][1])
	}

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

		ans := 0.0
		for j := 0; j < len(D)-1; j++ {
			a, b := D[j], D[j+1]
			if b-a >= math.Pi {
				ans = (b - a) - math.Pi
			}
		}
		fmt.Println(ans / (2 * math.Pi))
	}
}

// <END-OF-CODE>
