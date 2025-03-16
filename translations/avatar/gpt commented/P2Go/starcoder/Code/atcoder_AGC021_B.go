package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	fmt.Scanf("%d", &N)
	XY := make([][2]int, N)
	for i := range XY {
		fmt.Scanf("%d %d", &XY[i][0], &XY[i][1])
	}
	for i, xy := range XY {
		D := make([]float64, 0, len(XY))
		for j, x := range XY {
			if i == j {
				continue
			}
			D = append(D, math.Atan2(float64(x[0]-xy[0]), float64(x[1]-xy[1])))
		}
		D = append(D, D[0]+2*math.Pi)
		ans := 0.0
		for a, b := range D {
			if b-a >= math.Pi {
				ans += b - a - math.Pi
			}
		}
		fmt.Printf("%.12f\n", ans/(2*math.Pi))
	}
}

