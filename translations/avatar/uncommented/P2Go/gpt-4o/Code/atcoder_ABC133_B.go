package main

import (
	"fmt"
	"math"
)

func dist(x, y []int) float64 {
	tmp := 0.0
	for i := 0; i < len(x); i++ {
		tmp += math.Pow(float64(x[i]-y[i]), 2)
	}
	return math.Sqrt(tmp)
}

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
	for i, elm := range points {
		for j := i + 1; j < n; j++ {
			if dist(elm, points[j]) == math.Floor(dist(elm, points[j])) {
				count++
			}
		}
	}
	fmt.Println(count)
}

// <END-OF-CODE>
