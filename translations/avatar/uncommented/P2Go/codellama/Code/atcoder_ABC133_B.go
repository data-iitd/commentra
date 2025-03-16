package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	var n, d int
	fmt.Scan(&n, &d)
	points := make([][]int, n)
	for i := 0; i < n; i++ {
		points[i] = make([]int, d)
		fmt.Scan(&points[i])
	}
	count := 0
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if isInteger(dist(points[i], points[j])) {
				count++
			}
		}
	}
	fmt.Println(count)
}

func dist(x, y []int) float64 {
	tmp := 0.0
	for i := 0; i < d; i++ {
		tmp += (x[i] - y[i]) * (x[i] - y[i])
	}
	return math.Sqrt(tmp)
}

func isInteger(x float64) bool {
	return x == float64(int(x))
}

// 