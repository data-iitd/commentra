package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	fmt.Scanf("%d", &N)
	XY := make([][]int, N)
	for i := 0; i < N; i++ {
		var x, y int
		fmt.Scanf("%d %d", &x, &y)
		XY[i] = []int{x, y}
	}
	D := make([]float64, N)
	for i := 0; i < N; i++ {
		D[i] = math.Atan2(float64(XY[0][0]-XY[i][0]), float64(XY[0][1]-XY[i][1]))
	}
	for i := 0; i < N; i++ {
		D[i] = math.Mod(D[i], 2*math.Pi)
	}
	ans := 0.0
	for i := 0; i < N-1; i++ {
		ans += math.Mod(D[i+1]-D[i], 2*math.Pi)
	}
	fmt.Printf("%.10f\n", ans/(2*math.Pi))
}

