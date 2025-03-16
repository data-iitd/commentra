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

	count := 0

	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if isIntegerDistance(points[i], points[j], d) {
				count++
			}
		}
	}

	fmt.Println(count)
}

func isIntegerDistance(x, y []int, d int) bool {
	sum := 0.0
	for i := 0; i < d; i++ {
		sum += math.Pow(float64(x[i]-y[i]), 2)
	}
	return math.Sqrt(sum) == float64(int(math.Sqrt(sum)))
}
