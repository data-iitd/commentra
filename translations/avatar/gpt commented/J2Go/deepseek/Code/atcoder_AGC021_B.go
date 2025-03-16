package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N)

	x := make([]int, N)
	y := make([]int, N)

	for i := 0; i < N; i++ {
		fmt.Scan(&x[i], &y[i])
	}

	for i := 0; i < N; i++ {
		thetas := []float64{}

		for j := 0; j < N; j++ {
			if i == j {
				continue
			}
			theta := math.Atan2(float64(y[j]-y[i]), float64(x[j]-x[i]))
			thetas = append(thetas, theta)
		}

		sort.Float64s(thetas)

		thetas = append(thetas, thetas[0]+2*math.Pi)

		ans := 0.0

		for k := 0; k < N-1; k++ {
			diff := thetas[k+1] - thetas[k] - math.Pi
			if diff > ans {
				ans = diff
			}
		}

		fmt.Println(ans / (2 * math.Pi))
	}
}

