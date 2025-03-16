package main

import (
	"fmt"
	"math"
)

func main() {
	var n, d int
	fmt.Scan(&n, &d)

	points := make([][]int, n)
	for i := 0; i < n; i++ {
		points[i] = make([]int, d)
		for j := 0; j < d; j++ {
			fmt.Scan(&points[i][j])
		}
	}

	dist := func(x, y []int) float64 {
		tmp := 0.0
		for i := 0; i < d; i++ {
			tmp += math.Pow(float64(x[i]-y[i]), 2)
		}
		return math.Sqrt(tmp)
	}

	count := 0

	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if dist(points[i], points[j]) == float64(int(dist(points[i], points[j]))) {
				count++
			}
		}
	}

	fmt.Println(count)
}
